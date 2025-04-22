#include "GameObject.h"
#include "Input.h"
#include "Time.h"
#include "Transform.h"
namespace so {
	GameObject::GameObject()
	{
		mComponents.resize((UINT)enums::eComponentType::End);
		initializeTranform();
	}

	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr) 
				continue;
			//delete comp;
			comp = nullptr;
		}
	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr) continue;
			comp->Initialize();
		}
	}


	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr) continue;
			comp->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr) continue;
			comp->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr) continue;
			comp->Render(hdc);
		}


	}
	void GameObject::initializeTranform()
	{
		AddComponent<Transform>();
	}
}
	

