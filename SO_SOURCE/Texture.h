#pragma once
#include "Resource.h"
namespace so{
	namespace graphcis {
		
			class Texture : public Resource
			{
			public:
				enum class eTextureType {
					Bmp, Png, None,
				};
			public:
				Texture();
				~Texture();

				virtual HRESULT Load(const std::wstring& path) override;

				UINT GetWidth() { return mWidth; }
				UINT GetHeight() { return mHeight; }
				HDC GetHdc() { return mHdc; }
				eTextureType GetTextureType() { return mType; }
				Gdiplus::Image* GetImage() { return mImage; }


			private:
				eTextureType mType;
				Gdiplus::Image* mImage;
				HBITMAP mBitmap;
				HDC mHdc;

				UINT mWidth;
				UINT mHeight;
			};


		}
}
