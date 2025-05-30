#pragma once

#include "CommonInclude.h"
#include "Component.h"
#include "Collider.h"
namespace so::object
{
	void Destory(GameObject* gameObject);
}
namespace so {
	class GameObject : public Entity
	{
	public:
		friend void object::Destory(GameObject* obj);
		enum class eState
		{
			Active,
			Paused,
			Dead,
			End
		};
		GameObject();
		~GameObject();
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);
			mComponents[(UINT)comp->GetType()] = comp;
			mComponents.push_back(comp);

			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}

			return component;
		}
		eState GetState() { return mState; }
		void SetActive(bool power)
		{
			if (power == true) mState = eState::Active;
			if (power == false) mState = eState::Paused;
		}
		bool IsActive() { return mState == eState::Active; }

		bool IsDead() { return mState == eState::Dead; }
		void SetLayerType(eLayerType layerType) { mLayerType = layerType; }
		eLayerType GetLayerType() { return mLayerType; }

	private:
		void initializeTranform();
		void death() { mState = eState::Dead; }

	private:
		std::vector<Component*> mComponents;
		eState mState;
		eLayerType mLayerType;
	};
}


