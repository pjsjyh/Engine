#pragma
#include "SpriteRenderer.h"
#include "Transform.h"
#include "GameObject.h"
#include "Texture.h"
#include "Renderer.h"
#include "Camera.h"
namespace so
{
	SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, mTexture(nullptr)
		, mSize(Vector2::One)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{


	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}

	void SpriteRenderer::Render(HDC hdc)
	{
		//택스처 셋팅
		if (mTexture==nullptr)
			return;
		
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos = renderer::mainCamera->CaluatePosition(pos);

		if (mTexture->GetTextureType() == graphcis::Texture::eTextureType::Bmp) {
			TransparentBlt(hdc, pos.x, pos.y
				, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y
				, mTexture->GetHdc(), 0, 0, mTexture->GetWidth(), mTexture->GetHeight()
				, RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType() == graphcis::Texture::eTextureType::Png) {
			Gdiplus::Graphics graphcis(hdc);
			graphcis.DrawImage(mTexture->GetImage(), Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth()*mSize.x, mTexture->GetHeight()*mSize.y));
		}
		//Gdiplus::Graphics graphcis(hdc);
		//graphcis.DrawImage(mImgae, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
	}
	
}