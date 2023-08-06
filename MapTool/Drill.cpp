#include "stdafx.h"
#include "BF_framework.h"



Drill::Drill(Int2 location, ObTileMap* M)
{
    this->location = location;
}

Drill::~Drill()
{
}



void  Drill::Update(ObTileMap* M, BFM* bfm)
{
	Mining(); //capacity가 다 찰때까지 채광
    
	Scan(M); //주변 컨배이어를 스캔
	
	SendItem(bfm,M); //조건에 부합하면 아이템 전송

}

void  Drill::Mining()
{
	if (itemCapacity < MaxCapacity and TIMER->GetTick(mineDelay, 2.5f)) itemCapacity++;
}

void  Drill::Scan(ObTileMap* M)
{
    for (int i = 0; i < 4; ++i)
    {
        Int2 scanLocation = location + directions[i];
        int scanState = -1;
        if(M->GetTileColor(scanLocation) != Color(0.5,0.5,0.5,0))
            scanState = M->GetTileState(scanLocation);

        if (scanState >= (int)blockState::CONVEYORUP and scanState <= (int)blockState::CONVEYORRIGHT)
        {
            this->scanLocation = scanLocation;
            this->scanState = scanState;
            findCV = true;
            return;
        }
    }

    // 어느 방향에서도 컨베이어를 찾지 못하면 findCV를 false로 설정합니다.
    findCV = false;
}

void  Drill::SendItem(BFM* bfm, ObTileMap* M)
{
    if (itemCapacity > 0 and findCV == true and TIMER->GetTick(sendDelay, 2.5f))
    {
        switch (scanState)
        {
        case (int)blockState::CONVEYORUP:
        {
            const vector<CV_UP*>& CVUpLocation = bfm->GetCVUpLocation();
            const auto it = find_if(CVUpLocation.begin(), CVUpLocation.end(),
                [this, &M](const CV_UP* cv) { return *cv == CV_UP(scanLocation, M); });

            if (it != CVUpLocation.end() && (*it)->GetitemCapacity() < 3)
            {
                itemCapacity--;
                (*it)->GetItem();
            }
        }
        case (int)blockState::CONVEYORDOWN:
        {
            const vector<CV_DOWN*>& CVDownLocation = bfm->GetCVDownLocation();
            const auto it = find_if(CVDownLocation.begin(), CVDownLocation.end(),
                [this, &M](const CV_DOWN* cv) { return *cv == CV_DOWN(scanLocation, M); });

            if (it != CVDownLocation.end() && (*it)->GetitemCapacity() < 3)
            {
                itemCapacity--;
                (*it)->GetItem();
            }
        }
        case (int)blockState::CONVEYORLEFT:
        {
            const vector<CV_LEFT*>& CVLeftLocation = bfm->GetCVLeftLocation();
            const auto it = find_if(CVLeftLocation.begin(), CVLeftLocation.end(),
                [this, &M](const CV_LEFT* cv) { return *cv == CV_LEFT(scanLocation, M); });

            if (it != CVLeftLocation.end() && (*it)->GetitemCapacity() < 3)
            {
                itemCapacity--;
                (*it)->GetItem();
            }
        }
        case (int)blockState::CONVEYORRIGHT:
        {
            const vector<CV_RIGHT*>& CVRightLocation = bfm->GetCVRightLocation();
            const auto it = find_if(CVRightLocation.begin(), CVRightLocation.end(),
                [this, &M](const CV_RIGHT* cv) { return *cv == CV_RIGHT(scanLocation, M); });

            if (it != CVRightLocation.end() && (*it)->GetitemCapacity() < 3)
            {
                itemCapacity--;
                (*it)->GetItem();
            }
        }
        default:
            break;
        }
    }
   
}

