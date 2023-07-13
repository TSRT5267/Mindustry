#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet()
{
	bullet = new ObImage(L"unit/Bullet.gif");
	bullet->maxFrame = Int2{ 1,1 };
	bullet->scale.x = bullet->imageSize.x;
	bullet->scale.y = bullet->imageSize.y;

	scale.x = bullet->imageSize.x;
	scale.y = bullet->imageSize.y;

	bullet->SetParentRT(*this);
	isFilled = false;

}

Bullet::~Bullet()
{
	delete bullet;
}

void Bullet::Init()
{
}

void Bullet::Update()
{
	if (not isfire) return;

	MoveWorldPos(dir * POWER * DELTA);
	rotation.z = atan2f(dir.y, dir.x);

	lifeTime -= DELTA;
	if (lifeTime <= 0.0f)
	{
		isfire = false;
	}

	ObCircle::Update();
	bullet->Update();
}

void Bullet::Render()
{
	if (not isfire) return;

	ObCircle::Render();
	bullet->Render();
}

void Bullet::Fire(GameObject* shooter)
{
	lifeTime = 10.0f;
	isfire = true;
	SetWorldPos(shooter->GetWorldPos()+ shooter->GetRight()*16);
	dir = shooter->GetRight();
}