#include "AnimatedSprite.h"

#include "Time.h"
#include "RenderSystem.h"
#include "Entity.h"

void AnimatedSprite::Update() {
	char index = (startIndex + char((float) fps * Time::Instance().DeltaTime())) % count;

	// Set up directional offset
	offset.x = index * ((unsigned char) direction ^ 1) * bounds.w;
	offset.y = index * ((unsigned char) direction & 1) * bounds.h;
}

void AnimatedSprite::Render() {
	SDL_Rect calc_bounds = bounds + offset;
	SDL_RenderCopyF(RenderSystem::Instance().GetRenderer(), texAsset->GetTexture(), &calc_bounds, entity->GetTransform());
}

void AnimatedSprite::Load(const json::JSON& AnimatedSpriteNode) {
	// Get bounds
	Sprite::Load(AnimatedSpriteNode);

	if (AnimatedSpriteNode.hasKey("start")) {
		startIndex = (unsigned char) AnimatedSpriteNode.at("start").ToInt();
	}
	
	if (AnimatedSpriteNode.hasKey("fps")) {
		fps = (unsigned char) AnimatedSpriteNode.at("fps").ToInt();
	}

	if (AnimatedSpriteNode.hasKey("count")) {
		count = (unsigned char) AnimatedSpriteNode.at("count").ToInt();
	}

	if (AnimatedSpriteNode.hasKey("direction")) {
		direction = (SpriteDirection) AnimatedSpriteNode.at("direction").ToInt();
	}
}
