#include "TitleScene.h"
#include "Input.h"
#include "PlayScene.h"
#include "SceneManager.h"
namespace so {
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		Scene::Initialize();
	}
	void TitleScene::Update()
	{
		Scene::Update();
	}
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::N)) {
			SceneManager::LoadScene(L"PlayScene");
		}
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);
	}
	void TitleScene::OnEnter()
	{
		Scene::OnEnter();
	}
	void TitleScene::OnExit()
	{
		Scene::OnExit();
	}
}