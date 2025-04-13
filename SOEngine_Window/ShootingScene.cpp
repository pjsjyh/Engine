#include "ShootingScene.h"
#include "Input.h"
#include "Time.h"
so::ShootingScene::ShootingScene()
{
}

so::ShootingScene::~ShootingScene()
{
}

void so::ShootingScene::Initialize()
{
	
}

void so::ShootingScene::Update()
{
	if (Input::GetKeyDown(eKeyCode::A)) {
		Shooting* obj = new Shooting(700, 800);
		Scene::AddShootingObject(obj);

	}
	Scene::Update();
}

void so::ShootingScene::LateUpdate()
{
	Scene::LateUpdate();
}

void so::ShootingScene::Render(HDC hdc)
{
	Scene::Render(hdc);
}
