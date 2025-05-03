#pragma once
#include "Component.h"
#include "Layer.h"
#include "GameObject.h"
#include "Scene.h"
#include "SceneManager.h"
#include "Transform.h"
namespace so
 {
	namespace object {
		template <typename T> static T* Instantiate(so::enums::eLayerType type) {
			T* gameObject =  new T();
			gameObject->SetLayerType(type);
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			return gameObject;
		}

		template <typename T> static T* Instantiate(so::enums::eLayerType type, math::Vector2 position) {
			T* gameObject =  new T();
			gameObject->SetLayerType(type);
			Scene* activeScene = SceneManager::GetActiveScene();
			Layer* layer = activeScene->GetLayer(type);
			layer->AddGameObject(gameObject);

			Transform* tr = gameObject->GetComponent<Transform>();
			tr->SetPos(position);
			return gameObject;
		}
		/*static void Destroy(GameObject* obj) {
			obj->Death();
		}*/
		static void DontDestroyOnLoad(GameObject* gameObject)
		{
			Scene* activeScene = SceneManager::GetActiveScene();
			// ��������� ���ӿ�����Ʈ�� �����ش�.
			activeScene->EraseGameObject(gameObject);

			// �ش� ���ӿ�����Ʈ�� -> DontDestroy������ �־��ش�.
			Scene* dontDestroyOnLoad = SceneManager::GetDontDestroyOnLoad();
			dontDestroyOnLoad->AddGameObject(gameObject, gameObject->GetLayerType());
		}
	}
	
} 