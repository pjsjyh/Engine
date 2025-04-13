#include "Shooting.h"
#include "Input.h"
#include "Time.h"
so::Shooting::Shooting(float spawnx, float spawny)
	:speed(1)
{
	shotX = spawnx;
	shotY = spawny;
}

so::Shooting::~Shooting()
{
}

void so::Shooting::Update()
{
	const int speed = 100.0f;
	shotY -= speed * Time::DeltaTime();
}

void so::Shooting::LateUpdate()
{
}

void so::Shooting::Render(HDC hdc)
{
	//(hdc)
	int radius = 10;
	Ellipse(hdc,
		shotX - radius, shotY - radius,
		shotX + radius, shotY + radius);
	
}
