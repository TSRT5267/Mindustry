#include "stdafx.h"
#include "Scene2.h"
#include "Drill.h"



Drill::~Drill()
{
}



void  Drill::Update(ObTileMap* M)
{
	if (itemCapacity < MAXIC) Mining(); //capacity�� �� �������� ä��

	Scane(M); //�ֺ� �����̾ ��ĵ
	
	if (itemCapacity > 0 and findCV == true) SendItem(); //���ǿ� �����ϸ� ������ ����

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
	//���� ��ġ���� + ������� �����̾ �ִ��� ��ĵ
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

