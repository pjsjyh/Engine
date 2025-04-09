#include "GameObject.h"

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
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		mX -= 0.01f;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		mX += 0.01f;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		mY -= 0.01f;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		mY += 0.01f;
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

