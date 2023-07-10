#include "stdafx.h"
#include "Main.h"

Main::Main()
{
	for (int i = 0;i < MAXLAYER;i++)
	{
		map[i] = new ObTileMap();
		
		//map->Load();
		map[i]->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
		
	}
	
	//map[i]->file = "map2.txt";

	LineX = new ObRect();
	LineX->color = Color(1.0f, 0.0f, 0.0f, 1.0f);
	LineX->pivot = OFFSET_N;
	LineX->scale.x = 20000.0f;
	LineX->scale.y = 5.0f;

	LineY = new ObRect();
	LineY->color = Color(0.0f, 1.0f, 0.0f, 1.0f);
	LineY->pivot = OFFSET_N;
	LineY->scale.x = 5.0f;
	LineY->scale.y = 20000.0f;

	brushImgIdx = 0;
	brushFrame.x = 0;
	brushFrame.y = 0;
	brushColor = Color(0.5f, 0.5f, 0.5f, 0.5f);
	brushState = 0;

}

Main::~Main()
{
}

void Main::Init()
{
	layer = 0;
	/*for (int i = 0;i < MAXLAYER;i++)
	{
		map[i]->ResizeTile(Int2(50, 50));
	}*/
	map[0]->ResizeTile(Int2(TILESIZE, TILESIZE));
	map[0]->scale = Vector2(32,32);
	map[0]->SetWorldPos(Vector2(-TILESIZE*16,-TILESIZE * 16));
}

void Main::Release()
{
   
}

void Main::Update()
{
	ImGui::Text("FPS : %d", (int)TIMER->GetFramePerSecond());

	if (INPUT->KeyPress('W'))
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
	}

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
			wstring wImgFile = L"";
			wImgFile.assign(path.begin(), path.end());
			map[0]->tileImages[i] = new ObImage(wImgFile);
			break;
		}
		if (i < 3)
		{
			ImGui::SameLine();
		}
	}

	//"감바스";
	//L"감바스";
	//ImgIdx
	if (ImGui::InputInt("ImgIdx", &brushImgIdx))
	{
		brushImgIdx = Utility::Saturate(brushImgIdx, 0, 3);

		if (not map[0]->tileImages[brushImgIdx])
		{
			brushImgIdx = 0;
		}
	}
	//maxFrame
	ImGui::InputInt2("maxFrame", (int*)&map[0]->tileImages[brushImgIdx]->maxFrame);



	Int2 MF = map[0]->tileImages[brushImgIdx]->maxFrame;
	ImVec2 size;
	size.x = 300.0f / (float)MF.x;
	size.y = 300.0f / (float)MF.y;
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
			if (ImGui::ImageButton((void*)map[0]->tileImages[brushImgIdx]->GetSRV()
				, size, LT, RB))
			{
				brushFrame.x = j;
				brushFrame.y = i;
			}
			index++;
			ImGui::PopID();
		}
	}

	//TileState
	ImGui::SliderInt("TileState", &brushState, TILE_NONE, TILE_SIZE-1);
	//TileColor
	ImGui::ColorEdit4("TileColor", (float*)&brushColor, ImGuiColorEditFlags_PickerHueWheel);

	if (ImGui::Button("SAVE"))
	{
		map[0]->file = "map2.txt";
		map[0]->Save();
	}
	ImGui::SameLine();
	if (ImGui::Button("LOAD"))
	{
		map[0]->file = "map2.txt";
		map[0]->Load();
	}
	//SaveLoad
	//if (GUI->FileImGui("Save", "Save Map",
	//	".txt", "../Contents/TileMap"))
	//{
	///*	string path = ImGuiFileDialog::Instance()->GetFilePathName();
	//	Utility::Replace(&path, "\\", "/");
	//	size_t tok = path.find("/TileMap/") + 9;
	//	path = path.substr(tok, path.length());*/
	//	//path = "map1.txt";
	//	map->file = "map1.txt";
	//	map->Save();
	//}
	//ImGui::SameLine();
	//if (GUI->FileImGui("Load", "Load Map",
	//	".txt", "../Contents/TileMap"))
	//{


	//	/*string path = ImGuiFileDialog::Instance()->GetFilePathName();

	//	Utility::Replace(&path, "\\", "/");
	//	size_t tok = path.find("/TileMap/") + 9;
	//	path = path.substr(tok, path.length());
	//	map->file = path;*/
	//	map->file = "map1.txt";
	//	map->Load();
	//	tileSize = map->GetTileSize();
	//}

	if (INPUT->KeyPress(VK_LBUTTON))
	{
		Int2 Idx;
		//?
		if (map[0]->WorldPosToTileIdx(INPUT->GetWorldMousePos(), Idx))
		{
			map[0]->SetTile(Idx, brushFrame, brushImgIdx, brushState,brushColor);
		}

	}

	for (int i = 0;i < MAXLAYER;i++)
	{
		map[i]->Update();
	}
	LineX->Update();
	LineY->Update();
}

void Main::LateUpdate()
{
}

void Main::Render()
{
	/*for (int i = 0;i < MAXLAYER;i++)
	{
		map[i]->Render();
	}*/
	map[0]->Render();
	LineX->Render();
	LineY->Render();
}

void Main::ResizeScreen()
{
	
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
    app.SetAppName(L"MapTool");
    app.SetInstance(instance);
	app.InitWidthHeight(1600.f,900.0f);
    app.background = Color(0.3, 0.3, 0.3);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	SafeDelete(main);
	WIN->Destroy();
	WIN->DeleteSingleton();
	
	return wParam;
}