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
		cv_up->Update(M, this);
	}
	for (auto& cv_down : CVDownLocation)
	{
		cv_down->Update(M, this);
	}
	for (auto& cv_left : CVLeftLocation)
	{
		cv_left->Update(M, this);
	}
	for (auto& cv_right : CVRightLocation)
	{
		cv_right->Update(M, this);
	}
	for (auto& junction : junctionLocation)
	{
		junction->Update(M, this);
	}
	for (auto& router : routerLocation)
	{
		router->Update(M, this);
	}
	for (auto& turret : turretLocation)
	{
		turret->Update(M, this);
	}
	for (auto& core : coreLocation)
	{
		core->Update(M, this);
	}
}

void BFM::Render()
{
	for (auto& cv_up : CVUpLocation)
	{
		cv_up->Render();
	}
	for (auto& cv_down : CVDownLocation)
	{
		cv_down->Render();
	}
	for (auto& cv_left : CVLeftLocation)
	{
		cv_left->Render();
	}
	for (auto& cv_right : CVRightLocation)
	{
		cv_right->Render();
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
		CVDownLocation.push_back(new CV_DOWN(idx, M));
		break;
	case (int)blockState::CONVEYORLEFT:
		CVLeftLocation.push_back(new CV_LEFT(idx, M));
		break;
	case (int)blockState::CONVEYORRIGHT:
		CVRightLocation.push_back(new CV_RIGHT(idx, M));
		break;
	case (int)blockState::JUNCTION:
		junctionLocation.push_back(new Junction(idx, M));
		break;
	case (int)blockState::ROUTER:
		routerLocation.push_back(new Router(idx, M));
		break;
	case (int)blockState::TURRET:
		turretLocation.push_back(new Turret(idx, M));
		break;
	case (int)blockState::DRILL:
		for (int i = 0;i < 2;i++)
		{
			for (int j = 0;j < 2;j++)
			{
				Int2 IDX = idx;
				IDX.x += j;
				IDX.y -= i;

				drillLocation.push_back(new Drill(IDX,M));
				
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

				coreLocation.push_back(new Core(IDX,M));
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
			[inx, M](const CV_DOWN* cv) { return *cv == CV_DOWN(inx,M); }), CVDownLocation.end());
		break;
	case (int)blockState::CONVEYORLEFT:
		CVLeftLocation.erase(std::remove_if(CVLeftLocation.begin(), CVLeftLocation.end(),
			[inx, M](const CV_LEFT* cv) { return *cv == CV_LEFT(inx, M); }), CVLeftLocation.end());
		break;
	case (int)blockState::CONVEYORRIGHT:
		CVRightLocation.erase(std::remove_if(CVRightLocation.begin(), CVRightLocation.end(),
			[inx, M](const CV_RIGHT* cv) { return *cv == CV_RIGHT(inx, M); }), CVRightLocation.end());
		break;
	case (int)blockState::JUNCTION:
		junctionLocation.erase(std::remove_if(junctionLocation.begin(), junctionLocation.end(),
			[inx, M](const Junction* cv) { return *cv == Junction(inx, M); }), junctionLocation.end());
		break;
	case (int)blockState::ROUTER:
		routerLocation.erase(std::remove_if(routerLocation.begin(), routerLocation.end(),
			[inx, M](const Router* cv) { return *cv == Router(inx, M); }), routerLocation.end());
		break;
	case (int)blockState::TURRET:
		turretLocation.erase(std::remove_if(turretLocation.begin(), turretLocation.end(),
			[inx, M](const Turret* cv) { return *cv == Turret(inx, M); }), turretLocation.end());
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
					[IDX,M](const Drill* drill) { return *drill == Drill(IDX,M); }), drillLocation.end());
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
					[IDX,M](const Core* cv) { return *cv == Core(IDX, M); }), coreLocation.end());
			}
		}
		break;
	default:
		break;
	}
}



