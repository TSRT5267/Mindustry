#include "stdafx.h"
#include "BF_framework.h"



Drill::~Drill()
{
}



void  Drill::Update(ObTileMap* M, BFM* bfm)
{
	if (itemCapacity < MAXIC) Mining(); //capacity가 다 찰때까지 채광

	Scane(M); //주변 컨배이어를 스캔
	
	if (itemCapacity > 0 and findCV == true and TIMER->GetTick(senddelay, 2.5f)) SendItem(bfm); //조건에 부합하면 아이템 전송

}



void  Drill::Mining()
{
	float delay;
	if (TIMER->GetTick(delay, 2.5f)) itemCapacity++;
	if (itemCapacity > MAXIC) itemCapacity = MAXIC;
}


void  Drill::SendItem(BFM* bfm)
{
    switch (scaneState)
    {
    case (int)blockState::CONVEYORUP:
    {
        const vector<CV_UP*>& CVUpLocation = bfm->GetCVUpLocation();
        const auto it = find_if(CVUpLocation.begin(), CVUpLocation.end(),
            [this](const CV_UP* cv) { return *cv == scaneLocation; });

        if (it != CVUpLocation.end() && (*it)->GetitemCapacity() < 3)
        {
            (*it)->GetItem();
        }
    }       
    default:
        break;
    }
}

void  Drill::Scane(ObTileMap* M)
{
    for (int i = 0; i < 4; ++i)
    {
        Int2 scanLocation = location + directions[i];
        int scanState = M->GetTileState(scanLocation);

        if (scanState >= (int)blockState::CONVEYORUP && scanState <= (int)blockState::CONVEYORRIGHT)
        {
            scaneLocation = scanLocation;
            scaneState = scanState;
            findCV = true;
            return;
        }
    }

    // 어느 방향에서도 컨베이어를 찾지 못하면 findCV를 false로 설정합니다.
    findCV = false;
}

