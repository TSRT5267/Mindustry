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
	//본인 위치에서 + 모양으로 컨배이어가 있는지 스캔
	if()


}

