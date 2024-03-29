#include "Sprite.h"

#include "RenderSystem.h"
#include "Entity.h"

void Sprite::Initialize() {
	Component::Initialize();
}

void Sprite::Destroy() {
	Component::Destroy();

	texAsset = nullptr;
}

void Sprite::Update() {
	// Do Nothing
}

void Sprite::Render() {
	SDL_RenderCopyF(RenderSystem::Instance().GetRenderer(), texAsset->GetTexture(), &bounds, entity->GetTransform());
}

void Sprite::Load(const json::JSON& spriteNode) {
	// Get bounds
	if (spriteNode.hasKey("bounds")) {
		const auto& bounds_node = spriteNode.at("bounds");

		if (bounds_node.hasKey("x")) {
			bounds.x = bounds_node.at("x").ToInt();
		}
		if (bounds_node.hasKey("y")) {
			bounds.y = bounds_node.at("y").ToInt();
		}
		if (bounds_node.hasKey("width")) {
			bounds.w = bounds_node.at("width").ToInt();
		}
		if (bounds_node.hasKey("height")) {
			bounds.h = bounds_node.at("height").ToInt();
		}
	}

	// TODO: Set Sprite's texAsset
}
