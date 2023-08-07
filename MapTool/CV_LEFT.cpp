#include "stdafx.h"
#include "BF_framework.h"

CV_LEFT::CV_LEFT(Int2 location, ObTileMap* M)
{
	this->location = location;
	item = new ObImage(L"item_copper.png");
	item->scale.x = item->imageSize.x;
	item->scale.y = item->imageSize.y;
	item->scale *= 0.8f;
	item->SetWorldPos(M->GetTilePosition(this->location) * 32 + Vector2(-784, -784));
}

CV_LEFT::~CV_LEFT()
{
	delete item;
}

void CV_LEFT::Update(ObTileMap* M, BFM* bfm)
{
	if (itemCapacity > 0) hasItem = true;
	else hasItem = false;

	item->Update();

	Scan(M); //주변 컨배이어를 스캔

	SendItem(bfm, M); //조건에 부합하면 아이템 전송
}

void CV_LEFT::Render()
{
	if (hasItem) item->Render();
}

void CV_LEFT::Scan(ObTileMap* M)
{
    for (int i = 0; i < 1; ++i)
    {
        Int2 scanLocation = location + directions[i];
        int scanState = -1;
        if (M->GetTileColor(scanLocation) != Color(0.5, 0.5, 0.5, 0))
            scanState = M->GetTileState(scanLocation);

        if ((scanState >= (int)blockState::CONVEYORUP and scanState <= (int)blockState::TURRET) or
            scanState == (int)blockState::CORE)
        {
            this->scanLocation = scanLocation;
            this->scanState = scanState;
            findCV = true;
            return;
        }
    }
    findCV = false;
}

void CV_LEFT::SendItem(BFM* bfm, ObTileMap* M)
{
    if (itemCapacity > 0 and findCV == true and TIMER->GetTick(sendDelay, 0.25f))
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
            break;
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
            break;
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
            break;
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
            break;
        }
        case (int)blockState::JUNCTION:
        {
            const vector<Junction*>& JunctionLocation = bfm->GetJunctionLocation();
            const auto it = find_if(JunctionLocation.begin(), JunctionLocation.end(),
                [this, &M](const Junction* J) { return *J == Junction(scanLocation, M); });

            
                const vector<CV_LEFT*>& CVLeftLocation = bfm->GetCVLeftLocation();
                const auto CV = find_if(CVLeftLocation.begin(), CVLeftLocation.end(),
                    [this, &M](const CV_LEFT* cv) { return *cv == CV_LEFT(scanLocation + Int2(-1, 0), M); });

                if (CV != CVLeftLocation.end() && it != JunctionLocation.end() and 
                    (*CV)->GetitemCapacity() < 3)
                {
                    itemCapacity--;
                    (*it)->GetItem(bfm, M, (int)blockState::CONVEYORLEFT);
                }
                break;
            
        }
        case (int)blockState::ROUTER:
        {
            const vector<Router*>& RouterLocation = bfm->GetRouterLocation();
            const auto it = find_if(RouterLocation.begin(), RouterLocation.end(),
                [this, &M](const Router* cv) { return *cv == Router(scanLocation, M); });

            if (it != RouterLocation.end() && (*it)->GetitemCapacity() < 1)
            {
                itemCapacity--;
                (*it)->GetItem(bfm, M);
            }
            break;
        }
        case (int)blockState::TURRET:
        {
            const vector<Turret*>& TurretLocation = bfm->GetTurretLocation();
            const auto it = find_if(TurretLocation.begin(), TurretLocation.end(),
                [this, &M](const Turret* cv) { return *cv == Turret(scanLocation, M); });

            if (it != TurretLocation.end() && (*it)->GetitemCapacity() < 3)
            {
                itemCapacity--;
                (*it)->GetItem();
            }
            break;
        }
        default:
            break;
        }
    }

}