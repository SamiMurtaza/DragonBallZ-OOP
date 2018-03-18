#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y, int R, int G, int B)
{
//	renderer = rend;d
    objTexture = TextureManager::LoadTexture(textureSheet, R, G, B);
    xpos = x;
    ypos = y;
}

void GameObject::render()
{
    SDL_RenderCopyEx(Game::renderer, objTexture, &srcRect, &destRect, 0.0, NULL, flip);
}

GameObject::~GameObject() {}
