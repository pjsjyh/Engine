#pragma once
#include "Component.h"
#include "Animation.h"
namespace so {
	class Animator:public Component
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func) {
				mEvent = std::move(func);
			}
			void operator()() {
				if (mEvent)
					mEvent();
			}
			std::function<void()> mEvent;
		};
		struct Events {
			Event startEvent;
			Event completeEvent;
			Event endEvent;
		};
		Animator();
		~Animator();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void CreateAnimation(const std::wstring& name, so::graphcis::Texture* spritesSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration);
		void CreateAnimationByFolder(const std::wstring& name
			, const std::wstring& path
			, Vector2 offset, float duration);


		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);
		bool IsComplete() { return mActiveAnimation->IsComplete(); }


		Events* FindEvents(const std::wstring& name);
		std::function<void()>& GetStartEvent(const std::wstring& name);
		std::function<void()>& GetCompleteEvent(const std::wstring& name);
		std::function<void()>& GetEndEvent(const std::wstring& name);
	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mbLoop;

		//Event
		std::map<std::wstring, Events*> mEvents;
	};


}
