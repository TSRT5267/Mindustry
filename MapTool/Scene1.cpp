#include "stdafx.h"
#include "Scene1.h"
#include "resource.h"

Scene1::Scene1()
{
	logo = new ObImage(L"lobby/logo.png");
	logo->scale.x = logo->imageSize.x ;
	logo->scale.y = logo->imageSize.y ;

	background = new ObImage(L"lobby/space.png");
	background->scale.x = background->imageSize.x;
	background->scale.y = background->imageSize.y;
	
	planet = new ObImage(L"lobby/serpulo.png");
	planet->scale.x = planet->imageSize.x;
	planet->scale.y = planet->imageSize.y;

	bar = new ObRect();
	bar->scale = Vector2(250, 1000);	
	bar->color = Color(0.2,0.2,0.2,0.1);
}


Scene1::~Scene1()
{
	delete logo;
	delete background;
	delete planet;
}

void Scene1::Init()
{
	logo->SetWorldPos(Vector2(0,280));
	planet->SetWorldPos(Vector2(150,-30));
	bar->SetWorldPos(Vector2(-250,0 ));
}

void Scene1::Release()
{
}

void Scene1::Update()
{
	ImGui::Text("FPS : %d", (int)TIMER->GetFramePerSecond());
	app.background = Color(0.0, 0.0, 0.0);

	background->Update();
	logo->Update();
	planet->Update();
	bar->Update();

}

void Scene1::LateUpdate()
{
}

void Scene1::Render()
{
	background->Render();
	planet->Render();
	bar->Render();
	logo->Render();
}

void Scene1::ResizeScreen()
{
	
}


