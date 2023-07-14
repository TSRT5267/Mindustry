#include "stdafx.h"
#include "Scene2.h"
#include "Player.h"
#include "Bullet.h"

Scene2::Scene2()
{
	for (int i = 0;i < MAXLAYER;i++)
	{
		map[i] = new ObTileMap();
		map[i]->color = Color(0.5f, 0.5f, 0.5f, 0.5f);

	}
	map[0]->file = "ground.txt";
	map[0]->Load();
	map[1]->file = "environment.txt";
	map[1]->Load();
	map[2]->file = "block.txt";
	map[2]->Load();


	LineX = new ObRect();
	LineX->color = Color(1.0f, 0.0f, 0.0f, 1.0f);
	LineX->pivot = OFFSET_N;
	LineX->scale.x = 20000.0f;
	LineX->scale.y = 2.0f;

	LineY = new ObRect();
	LineY->color = Color(0.0f, 1.0f, 0.0f, 1.0f);
	LineY->pivot = OFFSET_N;
	LineY->scale.x = 2.0f;
	LineY->scale.y = 20000.0f;

	brushImgIdx = 0;
	brushFrame.x = 0;
	brushFrame.y = 0;
	brushColor = Color(0.5f, 0.5f, 0.5f, 0.5f);
	brushState = 0;

	player = new Player();

}

Scene2::~Scene2()
{
	delete player;
}

void Scene2::Init()
{
	player->Init();


	layer = 0;
	for (int i = 0;i < MAXLAYER;i++)
	{
		map[i]->ResizeTile(Int2(TILESIZE, TILESIZE));
		map[i]->scale = Vector2(TILESCALE, TILESCALE);
		map[i]->SetWorldPos(Vector2(-TILESIZE * TILESCALE / 2, -TILESIZE * TILESCALE / 2));
	}

}

void Scene2::Release()
{

}

void Scene2::Update()
{
	ImGui::Text("FPS : %d", (int)TIMER->GetFramePerSecond());


	//CAM->position = player->GetWorldPivot();

	Vector2 minus = player->GetWorldPivot() - CAM->position;
	CAM->position += minus * DELTA * 2;


	/*if (INPUT->KeyPress('W'))
	{
		CAM->position += UP * 300.0f * DELTA;
	}
	if (INPUT->KeyPress('S'))
	{
		CAM->position += DOWN * 300.0f * DELTA;
	}
	if (INPUT->KeyPress('A'))
	{
		CAM->position += LEFT * 300.0f * DELTA;
	}
	if (INPUT->KeyPress('D'))
	{
		CAM->position += RIGHT * 300.0f * DELTA;
	}*/







	//저장,불러오기
	if (ImGui::Button("save"))
	{
		map[0]->Save();
		map[1]->Save();
		map[2]->Save();
	}



	//이미지 불러오기
	for (int i = 0; i < 4; i++)
	{
		string str = "Texture" + to_string(i);
		if (GUI->FileImGui(str.c_str(), str.c_str(),
			".jpg,.png,.bmp,.dds,.tga", "../Contents/Images"))
		{
			string path = ImGuiFileDialog::Instance()->GetFilePathName();
			Utility::Replace(&path, "\\", "/");
			size_t tok = path.find("/Images/") + 8;
			path = path.substr(tok, path.length());
			SafeDelete(map[0]->tileImages[i]);
			SafeDelete(map[1]->tileImages[i]);
			SafeDelete(map[2]->tileImages[i]);
			wstring wImgFile = L"";
			wImgFile.assign(path.begin(), path.end());
			map[0]->tileImages[i] = new ObImage(wImgFile);
			map[1]->tileImages[i] = new ObImage(wImgFile);
			map[2]->tileImages[i] = new ObImage(wImgFile);
			break;
		}
		if (i < 3)
		{
			ImGui::SameLine();
		}
	}



	//레이어 선택
	if (ImGui::Button("ground"))
	{
		layer = 0;
		brushImgIdx = 0;
	}
	ImGui::SameLine();
	if (ImGui::Button("environment"))
	{
		layer = 1;
		brushImgIdx = 1;
	}
	ImGui::SameLine();
	if (ImGui::Button("1x1 block"))
	{
		layer = 2;
		brushImgIdx = 2;
	}
	ImGui::SameLine();
	if (ImGui::Button("2x2 block"))
	{
		layer = 2;
		brushImgIdx = 3;
	}
	ImGui::SameLine();
	if (ImGui::Button("look all "))
	{
		if (lookall == true) lookall = false;
		else lookall = true;

	}

	ImGui::Text("now layer : %d", layer);
	ImGui::SameLine();
	ImGui::Text("now layer : %d", lookall);



	if (ImGui::InputInt("ImgIdx", &brushImgIdx))
	{
		brushImgIdx = Utility::Saturate(brushImgIdx, 0, 3);

		if (not map[0]->tileImages[brushImgIdx])
		{
			brushImgIdx = 0;
		}
	}
	//maxFrame
	//ImGui::InputInt2("maxFrame", (int*)&map[layer]->tileImages[brushImgIdx]->maxFrame);
	ImGui::InputInt2("maxFrame", (int*)&MAXframe);
	if (brushImgIdx == 3)
	{
		map[layer]->tileImages[brushImgIdx]->maxFrame.x = MAXframe.x * 2;
		map[layer]->tileImages[brushImgIdx]->maxFrame.y = MAXframe.y * 2;
	}
	else
	{
		map[layer]->tileImages[brushImgIdx]->maxFrame.x = MAXframe.x;
		map[layer]->tileImages[brushImgIdx]->maxFrame.y = MAXframe.y;
	}


	//NULL image
	if (INPUT->KeyDown(VK_ESCAPE))
	{
		brushColor = Color{ 0.5,0.5,0.5,0.0 };
		brushImgIdx = 1;
	}

	//브러시
	if (brushImgIdx == 3)
	{
		//브러시(2x2) 제작
		Int2 MF = map[layer]->tileImages[brushImgIdx]->maxFrame;
		MF.x /= 2;
		MF.y /= 2;
		ImVec2 size;
		size.x = 150.0f / (float)MF.x;
		size.y = 150.0f / (float)MF.y;
		ImVec2 LT, RB;
		int index = 0;
		for (UINT i = 0; i < MF.y; i++)
		{
			for (UINT j = 0; j < MF.x; j++)
			{
				if (j != 0)
				{
					//같은줄에 배치
					ImGui::SameLine();
				}
				//텍스쳐 좌표
				LT.x = 1.0f / MF.x * j;
				LT.y = 1.0f / MF.y * i;
				RB.x = 1.0f / MF.x * (j + 1);
				RB.y = 1.0f / MF.y * (i + 1);

				ImGui::PushID(index);
				if (ImGui::ImageButton((void*)map[layer]->tileImages[brushImgIdx]->GetSRV()
					, size, LT, RB))
				{
					brushFrame.x = j;
					brushFrame.y = i;
					brushColor = Color{ 0.5,0.5,0.5,0.5 };
				}

				index++;
				ImGui::PopID();
			}
		}






	}
	else
	{
		//브러시(1x1) 제작
		Int2 MF = map[layer]->tileImages[brushImgIdx]->maxFrame;
		ImVec2 size;
		size.x = 150.0f / (float)MF.x;
		size.y = 150.0f / (float)MF.y;
		ImVec2 LT, RB;
		int index = 0;
		for (UINT i = 0; i < MF.y; i++)
		{
			for (UINT j = 0; j < MF.x; j++)
			{
				if (j != 0)
				{
					//같은줄에 배치
					ImGui::SameLine();
				}
				//텍스쳐 좌표
				LT.x = 1.0f / MF.x * j;
				LT.y = 1.0f / MF.y * i;
				RB.x = 1.0f / MF.x * (j + 1);
				RB.y = 1.0f / MF.y * (i + 1);

				ImGui::PushID(index);
				if (ImGui::ImageButton((void*)map[layer]->tileImages[brushImgIdx]->GetSRV()
					, size, LT, RB))
				{
					brushFrame.x = j;
					brushFrame.y = i;
					brushColor = Color{ 0.5,0.5,0.5,0.5 };
				}
				index++;
				ImGui::PopID();
			}
		}
	}

	//브러시 테스트
	{
		//브러시(1x1) 제작
		Int2 MF = map[layer]->tileImages[brushImgIdx]->maxFrame;
		ImVec2 size;
		size.x = 150.0f / (float)MF.x;
		size.y = 150.0f / (float)MF.y;
		ImVec2 LT, RB;
		int index = 0;
		for (UINT i = 0; i < MF.y; i++)
		{
			for (UINT j = 0; j < MF.x; j++)
			{
				if (j != 0)
				{
					//같은줄에 배치
					ImGui::SameLine();
				}
				//텍스쳐 좌표
				LT.x = 1.0f / MF.x * j;
				LT.y = 1.0f / MF.y * i;
				RB.x = 1.0f / MF.x * (j + 1);
				RB.y = 1.0f / MF.y * (i + 1);

				ImGui::PushID(index);
				if (ImGui::ImageButton((void*)map[layer]->tileImages[brushImgIdx]->GetSRV()
					, size, LT, RB))
				{
					brushFrame.x = j;
					brushFrame.y = i;
					brushColor = Color{ 0.5,0.5,0.5,0.5 };
				}
				index++;
				ImGui::PopID();
			}
		}
	}





	//설치전 잔상 (보류)
	/*if (layer >= 1)
	{
		if (brushColor != Color{ 0.5,0.5,0.5,0.0 })
		{
			Int2 pos;
			if (map[layer]->WorldPosToTileIdx(INPUT->GetWorldMousePos(), pos))
			{
				Color C = { 0.5,0.5,0.5,0.2 };
				Color D = { 0.5,0.5,0.5,0.0 };
				Int2 range;
				for (int i = 0;i < 3;i++)
				{
					for (int j = 0;j < 3;j++)
					{
						range.x = pos.x - 1 + i;
						range.y = pos.y + 1 - j;

						if (map[layer]->GetTileColor(range) == C)
						{
							if(brushImgIdx ==3) map[layer]->SetTile2(range, brushFrame, brushImgIdx, brushState, D);
							else map[layer]->SetTile(range, brushFrame, brushImgIdx, brushState, D);
						}

					}
				}
				if (map[layer]->GetTileColor(pos) == D)
				{
					if (brushImgIdx == 3) map[layer]->SetTile2(pos, brushFrame, brushImgIdx, brushState, C);
					else map[layer]->SetTile(pos, brushFrame, brushImgIdx, brushState, C);
				}
			}
		}

	}*/

	//타일 수정
	if (INPUT->KeyPress(VK_LBUTTON))
	{
		Color BUILDED = { 0.5,0.5,0.5,0.5 };
		Int2 Idx;

		if (map[layer]->WorldPosToTileIdx(INPUT->GetWorldMousePos(), Idx))
		{
			if (brushImgIdx == 3)
			{
				int confirmB = 0;
				int confirmC = 0;
				//건설
				for (int i = 0;i < 2;i++)
				{
					for (int j = 0;j < 2;j++)
					{
						Int2 range;
						range.x = Idx.x + i;
						range.y = Idx.y - j;
						if (map[layer]->GetTileColor(range) != BUILDED) confirmB++;
					}
				}
				//지우기
				for (int i = 0;i < 2;i++)
				{
					for (int j = 0;j < 2;j++)
					{
						Int2 range;
						range.x = Idx.x + i;
						range.y = Idx.y - j;
						if (map[layer]->GetTileIdx(range) == 3) confirmC++;
					}
				}

				if (confirmB == 4)
					map[layer]->SetTile2(Idx, brushFrame, brushImgIdx, brushState, brushColor);
				if (map[layer]->GetTileIdx(Idx) == 3 and map[layer]->GetTileFrame(Idx) == Vector2{ 0.5,0.5 })
					map[layer]->SetTile2(Idx, brushFrame, brushImgIdx, brushState, brushColor);
			}
			else
			{
				if (map[layer]->GetTileColor(Idx) != BUILDED)
					map[layer]->SetTile(Idx, brushFrame, brushImgIdx, brushState, brushColor);
				if (brushColor == Color{ 0.5,0.5,0.5,0.0 })
					map[layer]->SetTile2(Idx, brushFrame, brushImgIdx, brushState, brushColor);
			}
		}
	}

	for (int i = 0;i < MAXLAYER;i++)
	{
		map[i]->Update();
	}
	LineX->Update();
	LineY->Update();
	player->Update();
}

void Scene2::LateUpdate()
{
}

void Scene2::Render()
{
	if (lookall == true)
	{
		for (int i = 0;i < MAXLAYER;i++)
		{
			map[i]->Render();
		}
	}
	else
	{
		map[layer]->Render();
	}


	LineX->Render();
	LineY->Render();
	player->Render();
}

void Scene2::ResizeScreen()
{

}

