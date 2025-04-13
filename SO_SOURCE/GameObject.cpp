#include "GameObject.h"
#include "Input.h"
#include "Time.h"
so::GameObject::GameObject()
	:mX(0)
	,mY(0)
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


	HBRUSH brush = CreateSolidBrush(RGB(rand()%255, rand() % 255, rand() % 255));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);
	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
	HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
	SelectObject(hdc, oldPen);
	Ellipse(hdc, x,  y, 100 + x, 100 + y);

	(HBRUSH)SelectObject(hdc, oldBrush);
	Ellipse(hdc, 200, 200, 300, 300);
	DeleteObject(brush);
	DeleteObject(redPen);
	//Rectangle(hdc, 500, 500, 600, 600);
}

