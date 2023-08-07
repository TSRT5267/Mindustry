#include "stdafx.h"
#include "BF_framework.h"

Router::Router(Int2 location, ObTileMap* M)
{
	this->location = location;
}

Router::~Router()
{
}

void Router::Update(ObTileMap* M, BFM* bfm)
{
    SendItem(bfm,M);
}



void Router::Scan(ObTileMap* M)
{
    for (int i = 0; i < 4; ++i)
    {
        Int2 scanLocation = location + directions[i];
        int scanState = -1;
        if (M->GetTileColor(scanLocation) != Color(0.5, 0.5, 0.5, 0))
            scanState = M->GetTileState(scanLocation);

        if (scanState >= (int)blockState::CONVEYORUP and scanState <= (int)blockState::TURRET)
        {
            this->scanLocation[i] = scanLocation;
            this->scanState[i] = scanState;
            findCV = true;

        }
    }
    //findCV = false;
}

void Router::SendItem(BFM* bfm, ObTileMap* M)
{
    if (TIMER->GetTick(sendDelay, 0.1f) and itemCapacity > 0)
    {
        switch (Roulette)
        {
        case (int)blockState::CONVEYORUP:
        {
            Roulette++;

            const vector<CV_UP*>& CVUpLocation = bfm->GetCVUpLocation();
            const auto it = find_if(CVUpLocation.begin(), CVUpLocation.end(),
                [this, &M](const CV_UP* cv) { return *cv == CV_UP(location + directions[0], M); });

            if (it != CVUpLocation.end() && (*it)->GetitemCapacity() < 3)
            {
                itemCapacity--;
                (*it)->GetItem();
            }
            break;
        }
        case (int)blockState::CONVEYORDOWN:
        {
            Roulette++;

            const vector<CV_DOWN*>& CVDownLocation = bfm->GetCVDownLocation();
            const auto it = find_if(CVDownLocation.begin(), CVDownLocation.end(),
                [this, &M](const CV_DOWN* cv) { return *cv == CV_DOWN(location + directions[1], M); });

            if (it != CVDownLocation.end() && (*it)->GetitemCapacity() < 3)
            {
                itemCapacity--;
                (*it)->GetItem();
            }
            break;
        }
        case (int)blockState::CONVEYORLEFT:
        {
            Roulette++;

            const vector<CV_LEFT*>& CVLeftLocation = bfm->GetCVLeftLocation();
            const auto it = find_if(CVLeftLocation.begin(), CVLeftLocation.end(),
                [this, &M](const CV_LEFT* cv) { return *cv == CV_LEFT(location + directions[2], M); });

            if (it != CVLeftLocation.end() && (*it)->GetitemCapacity() < 3)
            {
                itemCapacity--;
                (*it)->GetItem();
            }
            break;
        }
        case (int)blockState::CONVEYORRIGHT:
        {
            Roulette++;

            const vector<CV_RIGHT*>& CVRightLocation = bfm->GetCVRightLocation();
            const auto it = find_if(CVRightLocation.begin(), CVRightLocation.end(),
                [this, &M](const CV_RIGHT* cv) { return *cv == CV_RIGHT(location + directions[3], M); });

            if (it != CVRightLocation.end() && (*it)->GetitemCapacity() < 3)
            {
                itemCapacity--;
                (*it)->GetItem();
            }
            break;
        }

        default:
            break;
        }


        if (Roulette == 4) Roulette = 0;
    }

}

void Router::GetItem(BFM* bfm, ObTileMap* M)
{
    if (itemCapacity < MaxCapacity) itemCapacity++;
    

}
