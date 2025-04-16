#pragma once
#include "Entity.h"
namespace so {
	class Resource : public Entity
	{
	public:
		Resource(enums::eResourceType type);

		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }
	private:
		std::wstring mPath;
		enums::eResourceType mType;
	};

}
