#include "stdafx.h"
#include "BF_framework.h"


void BFM::Update(ObTileMap* M)
{
	for (auto& drill : drillLocation) 
	{
		drill->Update(M,this);
	}
	
	for (auto& cv_up : CVUpLocation)
	{
		cv_up->Update(M);
	}

	if (drillLocation.size() > 0)
		ImGui::Text("CV test  : %d", drillLocation[0]->GetitemCapacity());
	if (CVUpLocation.size() > 0)
		ImGui::Text("CV test  : %d", CVUpLocation[0]->GetitemCapacity());
	
	

	
}

void BFM::Render()
{
	for (auto& cv_up : CVUpLocation)
	{
		cv_up->Render();
	}

	
}

void BFM::SaveLocation(int imidx, int state, Int2 idx, ObTileMap* M)
{
	
	switch (state)
	{
	case (int)blockState::CONVEYORUP:
		CVUpLocation.push_back(new CV_UP(idx,M));
		break;
	case (int)blockState::CONVEYORDOWN:
		CVDownLocation.push_back(new CV_DOWN(idx));
		break;
	case (int)blockState::CONVEYORLEFT:
		CVLeftLocation.push_back(new CV_LEFT(idx));
		break;
	case (int)blockState::CONVEYORRIGHT:
		CVRightLocation.push_back(new CV_RIGHT(idx));
		break;
	case (int)blockState::JUNCTION:
		junctionLocation.push_back(new Junction(idx));
		break;
	case (int)blockState::ROUTER:
		routerLocation.push_back(new Router(idx));
		break;
	case (int)blockState::TURRET:
		turretLocation.push_back(new Turret(idx));
		break;
	case (int)blockState::DRILL:
		for (int i = 0;i < 2;i++)
		{
			for (int j = 0;j < 2;j++)
			{
				Int2 IDX = idx;
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
				Int2 IDX = idx;
				IDX.x += j;
				IDX.y -= i;

				coreLocation.push_back(new Core(IDX));
			}
		}
		break;
	default:
		break;
	}
}

void BFM::RemoveLocation(int imidx, int state, Int2 inx, ObTileMap* M)
{

	switch (state)
	{
	case (int)blockState::CONVEYORUP:
		CVUpLocation.erase(std::remove_if(CVUpLocation.begin(), CVUpLocation.end(),
			[inx,M](const CV_UP* cv) { return *cv == CV_UP(inx,M); }), CVUpLocation.end());
		break;
	case (int)blockState::CONVEYORDOWN:
		CVDownLocation.erase(std::remove_if(CVDownLocation.begin(), CVDownLocation.end(),
			[inx](const CV_DOWN* cv) { return *cv == CV_DOWN(inx); }), CVDownLocation.end());
		break;
	case (int)blockState::CONVEYORLEFT:
		CVLeftLocation.erase(std::remove_if(CVLeftLocation.begin(), CVLeftLocation.end(),
			[inx](const CV_LEFT* cv) { return *cv == CV_LEFT(inx); }), CVLeftLocation.end());
		break;
	case (int)blockState::CONVEYORRIGHT:
		CVRightLocation.erase(std::remove_if(CVRightLocation.begin(), CVRightLocation.end(),
			[inx](const CV_RIGHT* cv) { return *cv == CV_RIGHT(inx); }), CVRightLocation.end());
		break;
	case (int)blockState::JUNCTION:
		junctionLocation.erase(std::remove_if(junctionLocation.begin(), junctionLocation.end(),
			[inx](const Junction* cv) { return *cv == Junction(inx); }), junctionLocation.end());
		break;
	case (int)blockState::ROUTER:
		routerLocation.erase(std::remove_if(routerLocation.begin(), routerLocation.end(),
			[inx](const Router* cv) { return *cv == Router(inx); }), routerLocation.end());
		break;
	case (int)blockState::TURRET:
		turretLocation.erase(std::remove_if(turretLocation.begin(), turretLocation.end(),
			[inx](const Turret* cv) { return *cv == Turret(inx); }), turretLocation.end());
		break;
	case (int)blockState::DRILL:
	{
		
		for (int i = 0;i < 2;i++)
		{
			for (int j = 0;j < 2;j++)
			{
				Int2 IDX = inx;
				IDX.x += j;
				IDX.y -= i;

				drillLocation.erase(remove_if(drillLocation.begin(), drillLocation.end(),
					[IDX](const Drill* drill) { return *drill == Drill(IDX); }), drillLocation.end());
			}
		}
		break;
	}		
	case (int)blockState::CORE:
		for (int i = 0;i < 2;i++)
		{
			for (int j = 0;j < 2;j++)
			{
				Int2 IDX = inx;
				IDX.x += j;
				IDX.y -= i;

				coreLocation.erase(std::remove_if(coreLocation.begin(), coreLocation.end(),
					[inx](const Core* cv) { return *cv == Core(inx); }), coreLocation.end());
			}
		}
		break;
	default:
		break;
	}
}



