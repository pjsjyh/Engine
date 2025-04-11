#include "GameObject.h"
#include "Input.h"
#include "Time.h"
so::GameObject::GameObject()
{
}

so::GameObject::~GameObject()
{
}

void so::GameObject::SetPosition(float x, float y)
{
	mX = x;
	mY = y;
}

void so::GameObject::Update()
{
	const int speed = 100.0f;
	if (Input::GetKey(eKeyCode::A)) {
		mX -= speed*Time::DeltaTime();
	}
	if (Input::GetKey(eKeyCode::D)) {
		mX += speed * Time::DeltaTime();
	}
	if (Input::GetKey(eKeyCode::W)) {
		mY -= speed * Time::DeltaTime();
	}
	if (Input::GetKey(eKeyCode::S)) {
		mY += speed * Time::DeltaTime();
	}
}

void so::GameObject::LateUpdate()
{
}

void so::GameObject::Render(HDC hdc)
{
	float x = mX;
	float y = mY;


	HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);
	Rectangle(hdc, 100 + x, 100 + y, 200 + x, 200 + y);
	(HBRUSH)SelectObject(hdc, oldBrush);
	Ellipse(hdc, 200, 200, 300, 300);
	DeleteObject(brush);
	Rectangle(hdc, 500, 500, 600, 600);
}

