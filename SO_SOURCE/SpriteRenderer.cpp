#pragma
#include "SpriteRenderer.h"
#include "Transform.h"
#include "GameObject.h"

namespace so
{
	SpriteRenderer::SpriteRenderer()
		: mImgae(nullptr)
		, mWidth(0)
		, mHeight(0)
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
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Gdiplus::Graphics graphcis(hdc);
		graphcis.DrawImage(mImgae, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
	}
	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		mImgae = Gdiplus::Image::FromFile(path.c_str());

		Gdiplus::Status result = mImgae->GetLastStatus();
		if (result != Gdiplus::Ok)
		{
			wchar_t buffer[256];
			swprintf_s(buffer, 256, L"[❌] 이미지 로딩 실패. 상태 코드: %d\n", (int)result);
			OutputDebugStringW(buffer);  // 디버그 출력창에 메시지 표시
		}

		mWidth = mImgae->GetWidth();
		mHeight = mImgae->GetHeight();
	}
}