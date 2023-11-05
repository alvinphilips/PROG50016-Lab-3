#include "Object.h"

void Object::Initialize() {
	initialized = true;
}

void Object::Destroy() {
	// Make sure we were previously initialized
	_ASSERT(initialized);

	initialized = false;

	// Set id to a special value when destroyed, perhaps for future optimization?
	id = -1;
}

void Object::Load(const json::JSON& objectNode) {
	// Set the Object's name
	if (objectNode.hasKey("name")) {
		name = objectNode.at("name").ToString();
	}

	// Set the Object's id
	if (objectNode.hasKey("id")) {
		id = objectNode.at("id").ToInt();
	}
}
