#pragma once
#include "../SO_SOURCE//Texture.h"
#include "Resources.h"
namespace so {
	void LoadResources()
	{
		Resources::Load<graphcis::Texture>(L"BG", L"E:/study/c++study/SoEngine/Engine/Resources/CloudOcean.png");
	};
}
