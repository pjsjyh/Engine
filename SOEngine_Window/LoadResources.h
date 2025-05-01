#pragma once
#include "../SO_SOURCE//Texture.h"
#include "Resources.h"
namespace so {
	void LoadResources()
	{
		Resources::Load<graphcis::Texture>(L"Cat", L"..\\Resources\\ChickenAlpha.bmp");
		Resources::Load<graphcis::Texture>(L"Player", L"..\\Resources\\Player.bmp");

		Resources::Load<graphcis::Texture>(L"Background", L"..\\Resources\\Kirby\\Background.png");
		Resources::Load<graphcis::Texture>(L"Island", L"..\\Resources\\Kirby\\Island.png");


		/*Resources::Load<graphcis::Texture>(L"Map", L"E:/study/c++study/SoEngine/Engine/Resources/img/map/map_pure.png");
		Resources::Load<graphcis::Texture>(L"PackMan", L"E:/study/c++study/SoEngine/Engine/Resources/img/pacman/0.png");
		Resources::Load<graphcis::Texture>(L"Bubble", L"..\\Resources\\Bubble.png");
		Resources::Load<graphcis::Texture>(L"MapleEffect", L"..\\Resources\\ezgif.com-gif-maker.png");*/
	};
}
