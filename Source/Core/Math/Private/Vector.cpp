#include "../Public/Vector.h"

using namespace Lumen::Core;

Vec2 Vec2::operator+(const Vec2& v) const
{
    Vec2 vec2;
    vec2.x = x + v.x;
    vec2.y = y + v.y;
    return vec2;
}

Vec2 Vec2::operator-(const Vec2& v) const
{
    Vec2 vec2;
    vec2.x = x - v.x;
    vec2.y = y - v.y;
    return vec2;
}

Vec2 Vec2::operator*(const float num) const
{
    Vec2 vec2;
    vec2.x = x * num;
    vec2.y = y * num;
    return vec2;
}

Vec2 Vec2::operator/(const float num) const
{
    Vec2 vec2;
    float invn = 1 / num;
    vec2.x = x * invn;
    vec2.y = y * invn;
    return vec2;
}

Vec2& Vec2::operator+=(const Vec2& v)
{
    x += v.x;
    y += v.y;
    return *this;
}

Vec2& Vec2::operator-=(const Vec2& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

Vec2& Vec2::operator*=(const float num)
{
    x *= num;
    y *= num;
    return *this;
}

Vec2& Vec2::operator/=(const float num)
{
    float invn = 1 / num;
    x *= invn;
    y *= invn;
    return *this;
}

float Vec2::Dot(const Vec2& v) const
{
    return x * v.x + y * v.y;
}

float Vec2::Length()
{
    return sqrt(x * x + y * y);
}

Vec2 Vec2::Normalize()
{
    Vec2 vec2;
    float invn = 1 / Length();
    vec2.x = x * invn;
    vec2.y = y * invn;
    return vec2;
}

Vec3 Vec3::operator-(void)
{
    Vec3 vec3;
    vec3.x = -x;
    vec3.y = -y;
    vec3.z = -z;
    return vec3;
}

Vec3 Vec3::operator+(const Vec3& v) const
{
    Vec3 vec3;
    vec3.x = x + v.x;
    vec3.y = y + v.y;
    vec3.z = z + v.z;
    return vec3;
}

Vec3 Vec3::operator-(const Vec3& v) const
{
    Vec3 vec3;
    vec3.x = x - v.x;
    vec3.y = y - v.y;
    vec3.z = z - v.z;
    return vec3;
}

Vec3 Vec3::operator*(float num) const
{
    Vec3 vec3;
    vec3.x = x * num;
    vec3.y = y * num;
    vec3.z = z * num;
    return vec3;
}

Vec3 Vec3::operator/(float num) const
{
    Vec3 vec3;
    float invNum = 1 / num;
    vec3.x = x * invNum;
    vec3.y = y * invNum;
    vec3.z = z * invNum;
    return vec3;
}

Vec3& Vec3::operator+=(const Vec3& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vec3& Vec3::operator-=(const Vec3& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vec3& Vec3::operator*=(float num)
{
    x *= num;
    y *= num;
    z *= num;
    return *this;
}

Vec3& Vec3::operator/=(float num)
{
    float invNum = 1 / num;
    x *= invNum;
    y *= invNum;
    z *= invNum;
    return *this;
}

bool Vec3::operator==(const Vec3& v) const
{
    return x == v.x && y == v.y && z == v.z;
}

float Vec3::SqrLength()
{
    return x * x + y * y + z * z;
}


float Vec3::Length()
{
    return sqrt(x * x + y * y + z * z);
}

Vec3 Vec3::Normalize()
{
    Vec3 vec3;

    // Prevent zero exception
    float len = Length();
    if (len < 1e-10) return vec3;

    float invn = 1 / len;
    vec3.x = x * invn;
    vec3.y = y * invn;
    vec3.z = z * invn;
    return vec3;
}

float Vec3::Dot(const Vec3& v) const
{
    return x * v.x + y * v.y + z * v.z;
}

Vec3 Vec3::Cross(const Vec3& v) const
{
    Vec3 vec3;
    vec3.x = y * v.z - z * v.y;
    vec3.y = z * v.x - x * v.z;
    vec3.z = x * v.y - y * v.x;
    return vec3;
}

Vec3 Vec3::ElementProduct(const Vec3& v) const
{
    Vec3 vec3;
    vec3.x = x * v.x;
    vec3.y = y * v.y;
    vec3.z = z * v.z;
    return vec3;
}

Vec4::Vec4(const Vec3& v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    w = 1;
}

Vec4::Vec4(const Vec3& v, float w) : w(w)
{
    x = v.x;
    y = v.y;
    z = v.z;
}

Vec4 Vec4::operator+(const Vec4& v) const
{
    Vec4 vec4;
    vec4.x = x + v.x;
    vec4.y = y + v.y;
    vec4.z = z + v.z;
    vec4.w = w + v.w;
    return vec4;
}

Vec4 Vec4::operator-(const Vec4& v) const
{
    Vec4 vec4;
    vec4.x = x - v.x;
    vec4.y = y - v.y;
    vec4.z = z - v.z;
    vec4.w = w - v.w;
    return vec4;
}

Vec4 Vec4::operator*(float num) const
{
    Vec4 vec4;
    vec4.x = x * num;
    vec4.y = y * num;
    vec4.z = z * num;
    vec4.w = w * num;
    return vec4;
}

Vec4 Vec4::operator/(float num) const
{
    Vec4 vec4;
    float invn = 1 / num;
    vec4.x = x * invn;
    vec4.y = y * invn;
    vec4.z = z * invn;
    vec4.w = w * invn;
    return vec4;
}

Vec4& Vec4::operator+=(const Vec4& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}

Vec4& Vec4::operator-=(const Vec4& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}

Vec4& Vec4::operator*=(float num)
{
    x *= num;
    y *= num;
    z *= num;
    w *= num;
    return *this;
}

Vec4& Vec4::operator/=(float num)
{
    float invn = 1 / num;
    x *= invn;
    y *= invn;
    z *= invn;
    w *= invn;
    return *this;
}

Vec3 Vec4::xyz() const
{
    Vec3 vec3;
    vec3.x = x;
    vec3.y = y;
    vec3.z = z;
    return vec3;
}

// This following is generated by Ubpa::USRefl::AutoRefl

RTTR_REGISTRATION
{
    registration::class_<Lumen::Core::Vec2>("Vec2")
        .property("x", &Vec2::x)
        (
            metadata("serialize", true)
        )
        .property("y", &Vec2::y)
        (
            metadata("serialize", true)
        )
        .constructor<>()(policy::ctor::as_object)
        .constructor<float, float>()
        .method("operator+", &Vec2::operator+)
        .method("operator-", &Vec2::operator-)
        .method("operator*", &Vec2::operator*)
        .method("operator/", &Vec2::operator/)
        .method("operator+=", &Vec2::operator+=)
        .method("operator-=", &Vec2::operator-=)
        .method("operator*=", &Vec2::operator*=)
        .method("operator/=", &Vec2::operator/=)
        .method("Dot", &Vec2::Dot)
        .method("Length", &Vec2::Length)
        .method("Normalize", &Vec2::Normalize)
    ;
    registration::class_<Lumen::Core::Vec3>("Vec3")
        .property("x", &Vec3::x)
        (
            metadata("serialize", true)
        )
        .property("y", &Vec3::y)
        (
            metadata("serialize", true)
        )
        .property("z", &Vec3::z)
        (
            metadata("serialize", true)
        )
        .constructor<>()(policy::ctor::as_object)
        .constructor<float>()
        .constructor<float, float, float>()
        .method("operator-", select_overload<Vec3(void)>(&Vec3::operator-))
        .method("operator+", &Vec3::operator+)
        .method("operator-", select_overload<Vec3(const Vec3&) const>(&Vec3::operator-))
        .method("operator*", &Vec3::operator*)
        .method("operator/", &Vec3::operator/)
        .method("operator+=", &Vec3::operator+=)
        .method("operator-=", &Vec3::operator-=)
        .method("operator*=", &Vec3::operator*=)
        .method("operator/=", &Vec3::operator/=)
        .method("operator==", &Vec3::operator==)
        .method("SqrLength", &Vec3::SqrLength)
        .method("Length", &Vec3::Length)
        .method("Normalize", &Vec3::Normalize)
        .method("Dot", &Vec3::Dot)
        .method("Cross", &Vec3::Cross)
        .method("ElementProduct", &Vec3::ElementProduct)
    ;
    registration::class_<Lumen::Core::Vec4>("Vec4")
        .property("x", &Vec4::x)
        (
            metadata("serialize", true)
        )
        .property("y", &Vec4::y)
        (
            metadata("serialize", true)
        )
        .property("z", &Vec4::z)
        (
            metadata("serialize", true)
        )
        .property("w", &Vec4::w)
        (
            metadata("serialize", true)
        )
        .constructor<>()(policy::ctor::as_object)
        .constructor<float, float, float, float>()
        .constructor<const Vec3&>()
        .constructor<const Vec3&, float>()
        .method("operator+", &Vec4::operator+)
        .method("operator-", &Vec4::operator-)
        .method("operator*", &Vec4::operator*)
        .method("operator/", &Vec4::operator/)
        .method("operator+=", &Vec4::operator+=)
        .method("operator-=", &Vec4::operator-=)
        .method("operator*=", &Vec4::operator*=)
        .method("operator/=", &Vec4::operator/=)
        .method("xyz", &Vec4::xyz)
    ;
}