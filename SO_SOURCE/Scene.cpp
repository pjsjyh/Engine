#include "Scene.h"

namespace so {
	so::Scene::Scene()
		:mLayers{}
	{
		CreateLayers();
	}

	so::Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{
		for (Layer* layer : mLayers) {
			if (layer == nullptr) continue;
			layer->Initialize();
		}
	}
	void Scene::Update()
	{
		for (Layer* layer : mLayers) {
			if (layer == nullptr) continue;

			layer->Update();
		}

	}
	void Scene::LateUpdate()
	{
		for (Layer* layer : mLayers) {
			if (layer == nullptr) continue;

			layer->LateUpdate();
		}

	}
	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : mLayers) {
			if (layer == nullptr) continue;

			layer->Render(hdc);
		}

	}
	void Scene::OnEnter()
	{
	}
	void Scene::OnExit()
	{
	}

	void Scene::AddGameObject(GameObject* gameObj, const enums::eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameObj);
	}
	void Scene::CreateLayers() {
		mLayers.resize((UINT)enums::eLayerType::Max);
		for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++)
		{
			mLayers[i] = new Layer();
		}
	}

}

