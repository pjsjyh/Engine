#pragma once
#include "CommonInclude.h"
namespace so {
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetNmae() { return mName; }
	private:
		std::wstring mName;
	};
}


