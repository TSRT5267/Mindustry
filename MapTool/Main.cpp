#include "stdafx.h"
#include "Main.h"
#include "Scene1.h"
#include "Scene2.h"
#include "resource.h"


Main::Main()
{
	cursor = new ObImage(L"cursor.png");
	cursor->scale.x = cursor->imageSize.x ;
	cursor->scale.y = cursor->imageSize.y ;
	
	

}

Main::~Main()
{
	delete cursor;
}

void Main::Init()
{
	

	Scene1* sc1 = new Scene1();
	SCENE->AddScene("SC1", sc1);

	Scene2* sc2 = new Scene2();	
	SCENE->AddScene("SC2", sc2);

	SCENE->ChangeScene("SC1");
	
}

void Main::Release()
{
   
}

void Main::Update()
{
	cursor->SetWorldPos(INPUT->GetWorldMousePos());
	cursor->Update();
	
	HCURSOR cursor = LoadCursor(app.GetInstance(), MAKEINTRESOURCE(IDC_CURSOR1));
	SetCursor(cursor);

	


	SCENE->Update();
	
}

void Main::LateUpdate()
{
	
	SCENE->LateUpdate();
	
}

void Main::Render()
{
	
	SCENE->Render();
	//cursor->Render();
	
}

void Main::ResizeScreen()
{
	
	SCENE->ResizeScreen();
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
	

    app.SetAppName(L"MapTool");
    app.SetInstance(instance);
	app.InitWidthHeight(900.0f,700.0f);
    app.background = Color(0.2, 0.2, 0.2);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	SafeDelete(main);
	WIN->Destroy();
	WIN->DeleteSingleton();
	return wParam;
}