#pragma once

#include "Game/Asset/Public/Prefab.h"
#include "Game/GamePlay/Public/Camera.h"
#include "Game/GamePlay/Public/Light.h"

// It seems std::vector<std::shared_ptr<T>> cannot be parsed by USRefl correctly now. Try fix later

namespace Lumen::Game
{
    struct Scene : public BaseObject
    {
        Scene();

        // Create an entity by editor reflection
        Entity* CreateEntity(std::string_view className);
        // Delete an entity by editor reflection
        // Erase opeartion is not efficient, improve it later
        void DeleteEntity(std::string_view name);
        // Update entity data binding in render thread
        void UpdateEntity(Entity* entity);
        
        // TODO. Settings

        [[serialize(true)]]
        std::vector<std::shared_ptr<Entity>> entities;

        // The index is used for avoiding name duplication
        // TODO. use a better way to manage index to avoid name duplication
        uint32_t nameIndex = 0;

        RTTR_ENABLE(BaseObject)
    };
}