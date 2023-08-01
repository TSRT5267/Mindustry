#include "stdafx.h"
#include "Scene2.h"
#include "Drill.h"



Drill::~Drill()
{
}



void  Drill::Update(ObTileMap* M)
{
	if (itemCapacity < MAXIC) Mining(); //capacity가 다 찰때까지 채광

	Scane(M); //주변 컨배이어를 스캔
	
	if (itemCapacity > 0 and findCV == true) SendItem(); //조건에 부합하면 아이템 전송

}



void  Drill::Mining()
{
	float delay;
	if (TIMER->GetTick(delay, 2.5f)) itemCapacity++;
	if (itemCapacity > MAXIC) itemCapacity = MAXIC;
}


void  Drill::SendItem()
{
	float delay;
	if (TIMER->GetTick(delay, 2.5f))
	{


	}
}

void  Drill::Scane(ObTileMap* M)
{
	//본인 위치에서 + 모양으로 컨배이어가 있는지 스캔
	Int2 up = location;
	Int2 down = location;
	Int2 left = location;
	Int2 right = location;
	up.y += 1;
	down.y -= 1;
	left.x -= 1;
	right.x += 1;

	if ((M->GetTileState(up) >= 0 and M->GetTileState(up) <= 3))
	{
		scaneLocation = up;
		findCV = true;
	} 
	else if ((M->GetTileState(down) >= 0 and M->GetTileState(down) <= 3)) 
	{
		scaneLocation = down;
		findCV = true;
	}
	else if ((M->GetTileState(left) >= 0 and M->GetTileState(left) <= 3)) 
	{
		scaneLocation = left;
		findCV = true;
	}
	else if ((M->GetTileState(right) >= 0 and M->GetTileState(right) <= 3)) 
	{
		scaneLocation = right;
		findCV = true;
	}
	else findCV = false;
	

}

