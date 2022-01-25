#include "../Public/Derived.h"
#include <iostream>

using namespace Lumen::Test;

DerivedSubComponent::DerivedSubComponent()
{
    mAssetRef.guid = xg::newGuid();
}

Derived::Derived(std::string_view name)
{
    SetName(name);
    mObj.SetName("sub");

    for (int i = 0; i < 2; i++)
        mObjs.emplace_back(new DerivedSubComponent(2));
};

void Derived::Func()
{
    std::cout << "default func" << std::endl;
}

// This following is generated by Ubpa::USRefl::AutoRefl

using namespace Lumen::Test;

RTTR_REGISTRATION
{
    registration::class_<Lumen::Test::DerivedComponent>("DerivedComponent")
        .property("mSub", &DerivedComponent::mSub)
        (
            metadata("serialize", true)
        )
        .constructor<>()
    ;
    registration::class_<Lumen::Test::DerivedSubComponent>("DerivedSubComponent")
        .constructor<>()
        .constructor<int>()
        .property("mDerivedSub", &DerivedSubComponent::mDerivedSub)
        (
            metadata("serialize", true)
        )
        .property("mAssetRef", &DerivedSubComponent::mAssetRef)
        (
            metadata("serialize", true)
        )
    ;
    registration::class_<Lumen::Test::Derived>("Derived")
        .constructor<>()
        .constructor<std::string_view>()
        .method("Func", &Derived::Func)
        .property("mAge", &Derived::mAge)
        (
            metadata("serialize", true)
        )
        .property("mUnsignedInt", &Derived::mUnsignedInt)
        (
            metadata("serialize", true)
        )
        .property("mFlag", &Derived::mFlag)
        (
            metadata("serialize", true)
        )
        .property("mFloat", &Derived::mFloat)
        .property("mDouble", &Derived::mDouble)
        (
            metadata("serialize", true)
        )
        .property("mVec", &Derived::mVec)
        (
            metadata("serialize", true)
        )
        .property("mObj", &Derived::mObj)
        (
            metadata("serialize", true)
        )
        .property("mObjs", &Derived::mObjs)
        (
            metadata("serialize", true)
        )
        .property("mSecrect", &Derived::mSecrect, registration::private_access)
        (
            metadata("serialize", true)
        )
    ;
}