#pragma once
#include "CommonInclude.h"
#include "BoxCollider2D.h"
#include "CircleCollider2D.h"


namespace so
{
	using namespace enums;
	union CollisionID
	{
		struct
		{
			UINT32 left;
			UINT32 right;
		};

		UINT64 id;
	};
	//유니온 공용으로 상용가능하게 해주는
	class CollisionManager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

		static void CollisionLayerCheck(eLayerType left, eLayerType right, bool enable);
		static void LayerCollision(class Scene* scene, eLayerType left, eLayerType right);
		static void ColliderCollision(Collider* left, Collider* right);
		static bool Intersect(Collider* left, Collider* right);
		static void Clear();
	private:
		static std::bitset<(UINT)eLayerType::Max> mCollisionLayerMatrix[(UINT)eLayerType::Max];
		static std::unordered_map<UINT64, bool> mCollisionMap;

	};
}