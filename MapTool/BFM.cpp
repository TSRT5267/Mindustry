#include "stdafx.h"
#include "Scene2.h"
#include "BFM.h"
#include "Drill.h"
#include "CV_UP.h"

void BFM::Update(ObTileMap* M)
{
	for (auto& drill : drillLocation) 
	{
		drill->Update(M);
	}
	





}

void BFM::SaveLocation(int imidx, int state, Int2 inx)
{
	/*prevMap.clear();
	prevMap.insert(location.begin(), location.end());*/
	
	switch (state)
	{
	case (int)blockState::CONVEYORUP:
		CVUpLocation.push_back(new CV_UP(inx));
		break;
	case (int)blockState::CONVEYORDOWN:
		CVDownLocation.push_back(inx);
		break;
	case (int)blockState::CONVEYORLEFT:
		CVLeftLocation.push_back(inx);
		break;
	case (int)blockState::CONVEYORRIGHT:
		CVRightLocation.push_back(inx);
		break;
	case (int)blockState::JUNCTION:
		junctionLocation.push_back(inx);
		break;
	case (int)blockState::ROUTER:
		routerLocation.push_back(inx);
		break;
	case (int)blockState::TURRET:
		turretLocation.push_back(inx);
		break;
	case (int)blockState::DRILL:
		for (int i = 0;i < 2;i++)
		{
			for (int j = 0;j < 2;j++)
			{
				Int2 IDX = inx;
				IDX.x += j;
				IDX.y -= i;

				drillLocation.push_back(new Drill(IDX));
				
			}
		}

		break;
	case (int)blockState::CORE:
		for (int i = 0;i < 2;i++)
		{
			for (int j = 0;j < 2;j++)
			{
				Int2 IDX = inx;
				IDX.x += j;
				IDX.y -= i;

				coreLocation.push_back(IDX);
			}
		}
		break;
	default:
		break;
	}
}

void BFM::RemoveLocation(int imidx, int state, Int2 inx)
{
	

	switch (state)
	{
	case (int)blockState::CONVEYORUP:
		auto it = remove_if(CVUpLocation.begin(), CVUpLocation.end(),
			[inx](const unique_ptr<CV_UP>& cv) { return *cv == CV_UP(inx); });
		if (it != CVUpLocation.end())
			CVUpLocation.erase(it);		
		break;
	case (int)blockState::CONVEYORDOWN:
		CVDownLocation.erase(remove(CVDownLocation.begin(), CVDownLocation.end(), inx), CVDownLocation.end());
		break;
	case (int)blockState::CONVEYORLEFT:
		CVLeftLocation.erase(remove(CVLeftLocation.begin(), CVLeftLocation.end(), inx), CVLeftLocation.end());
		break;
	case (int)blockState::CONVEYORRIGHT:
		CVRightLocation.erase(remove(CVRightLocation.begin(), CVRightLocation.end(), inx), CVRightLocation.end());
		break;
	case (int)blockState::JUNCTION:
		junctionLocation.erase(remove(junctionLocation.begin(), junctionLocation.end(), inx), junctionLocation.end());
		break;
	case (int)blockState::ROUTER:
		routerLocation.erase(remove(routerLocation.begin(), routerLocation.end(), inx), routerLocation.end());
		break;
	case (int)blockState::TURRET:
		turretLocation.erase(remove(turretLocation.begin(), turretLocation.end(), inx), turretLocation.end());
		break;
	case (int)blockState::DRILL:
		for (int i = 0;i < 2;i++)
		{
			for (int j = 0;j < 2;j++)
			{
				Int2 IDX = inx;
				IDX.x += j;
				IDX.y -= i;

				auto it = remove_if(drillLocation.begin(), drillLocation.end(),
					[IDX](const unique_ptr<Drill>& drill) { return *drill == Drill(IDX); });
				if (it != drillLocation.end())
					drillLocation.erase(it);
			}
		}
		break;
	case (int)blockState::CORE:
		for (int i = 0;i < 2;i++)
		{
			for (int j = 0;j < 2;j++)
			{
				Int2 IDX = inx;
				IDX.x += j;
				IDX.y -= i;

				coreLocation.erase(remove(coreLocation.begin(), coreLocation.end(), IDX), coreLocation.end());
			}
		}
		break;
	default:
		break;
	}
}



