#include "Scene.h"
#include <iostream>
#include "json.hpp"

Scene::Scene() {
	
	std::cout << "SCENE CREATED" << std::endl;

}

Scene::~Scene() {
	
	std::cout << "SCENE Destroyed" << std::endl;

}

void Scene::initilize() {

	std::cout << "SCENE INITIALIZED" << std::endl;



}

void Scene::Destroy() {

	std::cout << "SCENE DESTROYED" << std::endl;
	for (Entity* entity : entities) {
		delete entity;
	}
	entities.clear();

}

void Scene::Update() {

	std::cout << "SCENE UPDATED" << std::endl;
	for (Entity* entity : entities) {
		entity->Update();
	}


}

void Scene::AddEntry(Entity* _entity) {

	entities.push_back(_entity);

}

void Scene::RemoveEntry(Entity* _entity) {
	entities.remove(_entity);

}


void Scene::Load(json::JSON& _json) {
	
	if (_json.hasKey("Entities")) {
	
		for (auto& entity : _json["Entities"].ArrayRange()) {
		
			std::string entityName = entity["Name"].ToString();
			std::cout << "Entity Name: " << entityName << std::endl;

			Component* comp = new Component();
			comp->Load(entity);

		}

	}







	
	




	
	

}
