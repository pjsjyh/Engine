#pragma once
#include "../SO_SOURCE//Texture.h"
#include "Resources.h"
namespace so {
	void LoadResources()
	{
		Resources::Load<graphcis::Texture>(L"Map", L"E:/study/c++study/SoEngine/Engine/Resources/img/map/map_pure.png");
		Resources::Load<graphcis::Texture>(L"PackMan", L"E:/study/c++study/SoEngine/Engine/Resources/img/pacman/0.png");
	};
}
