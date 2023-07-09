#include "stdafx.h"
#include "Bullet.h"
#include "Player.h"
#include "Mutal.h"
#include "Scene1.h"

Scene1::Scene1()
{
	map = new ObIso();
	map->file = "map1.txt";
	map->Load();
	map->color = Color(0.5f, 0.5f, 0.5f, 0.5f);

	map->CreateTileCost();

	//pl = new Player();

	mutal = new Mutal();
	mutal->SetPos(Vector2(0, -225));
}

Scene1::~Scene1()
{
}

void Scene1::Init()
{
	pl->Init(Vector2(25, 25));
}

void Scene1::Release()
{
	LIGHT->lightColor.x = 0.5f;
		LIGHT->lightColor.y = 0.5f;
		LIGHT->lightColor.z = 0.5f;
}

void Scene1::Update()
{
	ImGui::Text("FPS : %d", (int)TIMER->GetFramePerSecond());


	if (INPUT->KeyDown(VK_F1))
	{
		if (map->PathFinding(mutal->col->GetWorldPos(),
			pl->GetWorldPivot(), mutal->way))
		{
			mutal->Move(mutal->way.back()->Pos);
			/*system("cls");
			cout << "±æ ÀÖÀ½" << endl;
			for (int i = 0; i < mutal->way.size(); i++)
			{
				cout << "X " << mutal->way[i]->Pos.x;
				cout << "Y " << mutal->way[i]->Pos.y;
				cout << endl;
			}*/
		}
	}
	if (INPUT->KeyDown('1'))
	{
		SCENE->ChangeScene("SC2",1.0f);
		fadeout = 1.0f;
	}

	if (fadeout > 0.0f)
	{
		fadeout -= DELTA;
		LIGHT->lightColor.x = fadeout / 2.0f;
		LIGHT->lightColor.y = fadeout / 2.0f;
		LIGHT->lightColor.z = fadeout / 2.0f;
	}


	pl->Update();
	map->Update();
	mutal->Update();
	CAM->position = pl->GetWorldPos();
}

void Scene1::LateUpdate()
{
	if (map->GetTileState(pl->GetFoot()) == TILE_WALL)
	{
		pl->GoBack();
	}
}

void Scene1::Render()
{
	map->Render();
	pl->Render();
	mutal->Render();
}

void Scene1::ResizeScreen()
{
}
