#include "Game/Asset/Public/Scene.h"
#include "Render/RenderCore/Public/RenderCommand.h"

using namespace Lumen::Game;
using namespace Lumen::Render;

Scene::Scene()
{

}

bool Scene::CreateEntity(std::string_view className)
{
	rttr::type derivedType = rttr::type::get_by_name(className.data());
	if (!derivedType.is_valid()) return false;

	// Note variant manage data life itself, we need to persistent data with shared_ptr
	variant derived = derivedType.create();
	auto entity = derived.get_value<std::shared_ptr<Entity>>();
	entity->SetName(className.data() + std::string("_") + std::to_string(nameIndex++));
	entities.emplace_back(entity);

	ENQUEUE_RENDER_COMMAND("CreateEntity", [entityProxy = Entity(*entity.get())](RHIContext* graphicsContext) {
		graphicsContext->CreateEntity(entityProxy);
	});

	return true;
}

void Scene::DeleteEntity(std::string_view name)
{
	for (int i = 0; i < entities.size(); i++)
	{
		if (entities[i]->GetName() == name.data())
		{
			auto guid = entities[i]->GetGuid().str();
			ENQUEUE_RENDER_COMMAND("RemoveRenderItem", [guid](RHIContext* graphicsContext) {
				graphicsContext->RemoveRenderItem(guid);
			});

			entities.erase(entities.begin() + i);
			break;
		}
	}
}

void Scene::UpdateEntity(Entity* entity)
{
	ENQUEUE_RENDER_COMMAND("UpdateEntity", [entityProxy = Entity(*entity)](RHIContext* graphicsContext) {
		graphicsContext->UpdateEntity(entityProxy);
	});
}

// This following is generated by Ubpa::USRefl::AutoRefl

RTTR_REGISTRATION
{
	registration::class_<Lumen::Game::Scene>("Scene")
		.constructor<>()
		.property("camera", &Scene::camera)
		(
			metadata("serialize", true)
		)
		.property("light", &Scene::light)
		(
			metadata("serialize", true)
		)
		.property("entities", &Scene::entities)
		(
			metadata("serialize", true)
		)
	;
}