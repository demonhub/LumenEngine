#pragma once

#include "Game/GamePlay/Public/Entity.h"
#include "Game/GamePlay/Public/Component.h"
#include "Core/Math/Public/Vector.h"

using namespace Lumen::Game;
using namespace Lumen::Core;
using namespace rttr;

// It seems std::vector<std::shared_ptr<T>> cannot be parsed by USRefl correctly now. Try fix later

namespace Lumen::Test
{
    struct DerivedComponent : Component
    {
        DerivedComponent();

        [[serialize(true)]]
        int mSub = 10;

        RTTR_ENABLE(Component)
    };

    struct DerivedSubComponent : public DerivedComponent
    {
        DerivedSubComponent();
        DerivedSubComponent(int num) : mDerivedSub(num) {}

        [[serialize(true)]]
        int mDerivedSub = 20;

        [[serialize(true)]]
        AssetRef mAssetRef;

        RTTR_ENABLE(DerivedComponent)
    };

    class Derived : public Entity
    {
    public:
        Derived();
        Derived(std::string_view name);

        void Func();

        [[serialize(true)]]
        int mAge = 23;

        [[serialize(true)]]
        unsigned int mUnsignedInt = 233;

        [[serialize(true)]]
        bool mFlag = false;

        float mFloat = 10.f;

        [[serialize(true)]]
        double mDouble = 10.0;

        [[serialize(true)]]
        Vec3 mVec = Vec3(1, 2, 3);

        [[serialize(true)]]
        Vec3 mVec1 = Vec3(4, 5, 6);

        [[serialize(true)]]
        DerivedSubComponent mObj;

        [[serialize(true)]]
        std::shared_ptr<DerivedSubComponent> mObjPtr;

        [[serialize(true)]]
        std::vector<DerivedSubComponent> mObjs;

        [[serialize(true)]]
        std::vector<std::shared_ptr<DerivedSubComponent>> mObjPtrs;

    private:
        [[serialize(true)]]
        std::string mSecrect = "guess";

        RTTR_REGISTRATION_FRIEND
        RTTR_ENABLE(Entity)
    };
}