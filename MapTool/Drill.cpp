#include "stdafx.h"
#include "Main.h"
#include "Drill.h"



Drill::~Drill()
{
}

void  Drill::Update()
{
	
}



void Drill::Mining()
{
	float delay;
	if (TIMER->GetTick(delay, 2.5f)) itemCapacity++;
	if (itemCapacity > MAXIC) itemCapacity = MAXIC;
}

void Drill::Scane()
{
	//���� ��ġ���� + ������� �����̾ �ִ��� ��ĵ
	if()


}

