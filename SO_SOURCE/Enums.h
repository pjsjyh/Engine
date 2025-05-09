#pragma once
namespace so {
	namespace enums {
		enum class eLayerType {
			None,
			BackGround,
			Animal,
			Player,
			Particle,
			Max = 16,
		};
		enum class  eResourceType {
			Texture,
			AudioClip, 
			Animation,
			Prefab,
			End,
		};
		enum class  eComponentType {
			Transform,
			Colider,
			Script,
			SpriteRenderer,
			Animator,
			Camera,
			End,
		};
		enum class eColliderType
		{
			Circle2D,
			Rect2D,
			End,
		};
	}
	
}