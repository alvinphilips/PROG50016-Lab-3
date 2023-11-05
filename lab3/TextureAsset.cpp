#include "TextureAsset.h"

#include "RenderSystem.h"

void TextureAsset::Load(const json::JSON& textureAssetNode) {
	Asset::Load(textureAssetNode);

	// Create texture if we have an image field
	if (textureAssetNode.hasKey("image")) {
		SDL_Surface* image = IMG_Load(textureAssetNode.at("image").ToString().c_str());
		texture = SDL_CreateTextureFromSurface(RenderSystem::Instance().GetRenderer(), image);
		SDL_FreeSurface(image);
	}
}

void TextureAsset::Destroy() {
	SDL_DestroyTexture(texture);
	texture = nullptr;

	// We don't 'own' the renderer, hence we just set it to null without destroying it
	renderer = nullptr;
}
