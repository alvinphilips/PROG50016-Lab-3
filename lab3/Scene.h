#pragma once

#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"

class Scene {
	friend class SceneManager;
	std::list<Entity*> entities;
	std::string name;
	int id;
protected:
	void Initialize();
	void Destroy();
	void Update();
	void Load(std::string fileName);
public:
	Entity* CreateEntity();
	void RemoveEntity(Entity* _entity);
	Entity* FindEntityById(int id);
};

#endif