#include "Game/GamePlay/Public/Light.h"

using namespace Lumen::Game;

DirectionalLight::DirectionalLight()
{
	mClassName = "DirectionalLight";
}

// This following is generated by Ubpa::USRefl::AutoRefl

RTTR_REGISTRATION
{
	registration::class_<Lumen::Game::DirectionalLight>("DirectionalLight")
		.property("strength", &DirectionalLight::strength)
		(
			metadata("serialize", true)
		)
		.constructor<>()
		.constructor<const Vec3&, const Vec3&, const Vec3&, const Vec3&>()
		.method("GetPosition", &DirectionalLight::GetPosition)
		.method("GetDirection", &DirectionalLight::GetDirection)
	;
}