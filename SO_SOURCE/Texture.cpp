#include "Texture.h"
#include "soApplication.h"
#include "Resources.h"

extern so::Application app;

namespace so {
	namespace graphics {
		Texture::Texture()
			: Resource(enums::eResourceType::Texture)
			, mbAlpha(false)
		{
		}

		so::graphics::Texture::~Texture()
		{
		}
		Texture* Texture::Create(const std::wstring& name, UINT width, UINT height)
		{
			Texture* image = Resources::Find<Texture>(name);
			if (image)
				return image;

			image = new Texture();
			image->SetName(name);
			image->SetWidth(width);
			image->SetHeight(height);

			HDC hdc = app.GetHdc();
			HWND hwnd = app.GetHwnd();

			image->mBitmap = CreateCompatibleBitmap(hdc, width, height);
			image->mHdc = CreateCompatibleDC(hdc);

			HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
			HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);
			Rectangle(image->mHdc, -1, -1, image->GetWidth() + 1, image->GetHeight() + 1);
			SelectObject(hdc, oldBrush);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(image->mHdc, image->mBitmap);
			DeleteObject(oldBitmap);

			Resources::Insert(name + L"Image", image);

			return image;
		}

		HRESULT so::graphics::Texture::Load(const std::wstring& path)
		{

			std::wstring ext
				= path.substr(path.find_last_of(L".") + 1);

			//bmp �϶�
			if (ext == L"bmp")
			{
				mType = eTextureType::Bmp;
				mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP
					, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

				if (mBitmap == nullptr)
					return S_FALSE;

				BITMAP info = {};
				GetObject(mBitmap, sizeof(BITMAP), &info);

				mWidth = info.bmWidth;
				mHeight = info.bmHeight;

				HDC mainDC = app.GetHdc();
				mHdc = CreateCompatibleDC(mainDC);

				HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
				DeleteObject(oldBitmap);

			}
			else if (ext == L"png")
			{
				mType = eTextureType::Png;
				mImage = Gdiplus::Image::FromFile(path.c_str());
				if (mImage == nullptr)
					return S_FALSE;

				mWidth = mImage->GetWidth();
				mHeight = mImage->GetHeight();
			}

			return S_OK;
		}
		COLORREF Texture::GetPixel(int x, int y)
		{
			return ::GetPixel(mHdc, x, y);
		}
	}

}

