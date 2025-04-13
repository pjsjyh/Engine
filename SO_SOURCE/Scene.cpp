#include "Scene.h"

namespace so {
	so::Scene::Scene()
		:mGameObjects{}
	{
	}

	so::Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{
	}
	void Scene::Update()
	{
		for (GameObject* gameObj : mGameObjects) {
			gameObj->Update();
		}
		for (Shooting* gameObj : mShootingObj) {
			gameObj->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects) {
			gameObj->LateUpdate();
		}
		for (Shooting* gameObj : mShootingObj) {
			gameObj->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGameObjects) {
			gameObj->Render(hdc);
		}
		for (Shooting* gameObj : mShootingObj) {
			gameObj->Render(hdc);
		}
	}
	 void Scene::AddGameObject(GameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}
	 void Scene::AddShootingObject(Shooting* gameObject)
	 {
		 mShootingObj.push_back(gameObject);
	 }
	 void Scene::StartShoot(Shooting* shootObj)
	 {

	 }
}

