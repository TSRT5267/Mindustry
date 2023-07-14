#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet()
{
	bullet = new ObImage(L"unit/Bullet.png");
	bullet->maxFrame = Int2{ 1,1 };
	bullet->scale.x = bullet->imageSize.x*0.5f;
	bullet->scale.y = bullet->imageSize.y*0.5f;

	scale.x = bullet->scale.x;
	scale.y = bullet->scale.y;
	color = Color{ 1,1,1,0 };

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
	rotation.z = atan2f(dir.y, dir.x) + HALFPI ;

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

void Bullet::Fire(GameObject* shooter,int hand)
{
	lifeTime = 1.0f;
	isfire = true;
	if (hand == 0)
	{
		Vector2 D = shooter->GetWorldPos() 
			+ shooter->GetUp() * 16 + shooter->GetRight() * 14;
		SetWorldPos(D);
		dir = INPUT->GetWorldMousePos() - D;
	}
	else
	{
		Vector2 D = shooter->GetWorldPos()
			+ shooter->GetUp() * 16 - shooter->GetRight() * 14;
			SetWorldPos(D);
		dir = INPUT->GetWorldMousePos() - D;
	}
	//dir = shooter->GetUp() ;
	
	dir.Normalize();
	
}