#pragma
#include "Entity.h"
#include "Component.h"
#include "Texture.h"
namespace so
{
	class TilemapRenderer : public Component
	{
	public:
		TilemapRenderer();
		~TilemapRenderer();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetTexture(graphics::Texture* texture) { mTexture = texture; }
		void SetSize(math::Vector2 size) { mSize = size; }
		void SetIndex(Vector2 index) { mIndex = index; }
		Vector2 GetIndex() { return mIndex; }
	
	public:
		static Vector2 TileSize;
		static Vector2 OriginTileSize;
		static Vector2 SelectedIndex;

	private:
		Vector2 mTileSize;
		graphics::Texture* mTexture;
		Vector2 mSize;
		Vector2 mIndex;
	};
}