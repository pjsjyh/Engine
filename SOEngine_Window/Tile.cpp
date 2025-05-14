#include "Tile.h"
#include "Input.h"
#include "Transform.h"
#include "Time.h"
#include "TilemapRenderer.h"
namespace so
{
	void Tile::Initialize()
	{
		GameObject::Initialize();
	}

	void Tile::Update()
	{
		GameObject::Update();
	}

	void Tile::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Tile::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Tile::SetPosition(int x, int y)
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos;
		pos.x = x * TilemapRenderer::TileSize.x;
		pos.y = y * TilemapRenderer::TileSize.y;
		tr->SetPos(pos);
	}
}