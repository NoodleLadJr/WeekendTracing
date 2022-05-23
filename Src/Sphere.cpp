#include "Sphere.h"

bool Sphere::Hit(const Ray& r, double t_Min, double t_Max, HitRecord& Rec) const
{
    Vec3 Oc = r.Origin() - Center;
    auto a = r.Direction().LengthSquared();
    auto HalfB = dot(Oc, r.Direction());
    auto c = Oc.LengthSquared() - Radius*Radius;
    auto Discriminant = HalfB*HalfB-a*c;
    if(Discriminant < 0) {return false;}
    auto Sqrtd = sqrt(Discriminant);

    //Find the nearest root

    auto Root = (-HalfB - Sqrtd) / a;
    if(Root < t_Min || t_Max < Root)
    {
        Root = (-HalfB+Sqrtd) / a;
        if(Root < t_Min || t_Max < Root) {return false;}
    }
    Rec.t = Root;
    Rec.P = r.At(Rec.t);
    Vec3 OutwardNormal = (Rec.P - Center) / Radius;
    Rec.SetFaceNormal(r,OutwardNormal);
}
