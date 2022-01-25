#include "../Public/Component.h"

using namespace Lumen::Game;

Component::Component()
{

}

// This following is generated by Ubpa::USRefl::AutoRefl

RTTR_REGISTRATION
{
    registration::class_<Lumen::Game::AssetRef>("AssetRef")
        .property("guid", &AssetRef::guid)
        (
            metadata("serialize", true)
        )
        .property("ref", &AssetRef::ref)
        .constructor<>()
    ;
    registration::class_<Lumen::Game::Component>("Component")
        .constructor<>()
        .method("GetName", &Component::GetName)
        .method("SetName", &Component::SetName)
        .property("mName", &Component::mName, registration::private_access)
        (
            metadata("serialize", true)
        )
    ;
}