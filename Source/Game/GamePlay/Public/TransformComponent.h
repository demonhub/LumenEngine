#pragma once

#include "Component.h"
#include "Core/Math/Public/MathUtil.h"

namespace Lumen::Game
{
    class TransformComponent : public Component
    {
    public:
        TransformComponent();

    public:
        [[serialize(true)]]
        Vec3 position;
        [[serialize(true)]]
        Vec3 rotation;
        [[serialize(true)]]
        Vec3 scale = Vec3(1.f);

        RTTR_REGISTRATION_FRIEND
        RTTR_ENABLE(Component)
    };
}