#pragma once
namespace so {
	namespace enums {
		enum class eLayerType {
			None,
			BackGround,
			Tile,
			Animal,
			Player,
			Floor,
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
			Rigidbody,
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