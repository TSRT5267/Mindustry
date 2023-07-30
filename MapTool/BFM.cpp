#include "stdafx.h"
#include "Drill.h"
#include "Scene2.h"
#include "BFM.h"


void BFM::Update()
{
	




}

void BFM::SaveLocation(int imidx, int state, Int2 inx)
{
	/*prevMap.clear();
	prevMap.insert(location.begin(), location.end());*/
	
	switch (state)
	{
	case (int)blockState::CONVEYORUP:
		CVUpLocation.push_back(inx);
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

				drillLocation.push_back(IDX);
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
		CVUpLocation.erase(remove(CVUpLocation.begin(), CVUpLocation.end(), inx), CVUpLocation.end());
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

				drillLocation.erase(remove(drillLocation.begin(), drillLocation.end(), IDX), drillLocation.end());
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



