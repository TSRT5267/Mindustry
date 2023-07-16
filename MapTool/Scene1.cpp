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

	play = new ObImage(L"lobby/play.png");
	play->scale.x = play->imageSize.x;
	play->scale.y = play->imageSize.y;
	play->scale *= 3;

	exit = new ObImage(L"lobby/exit.png");
	exit->scale.x = exit->imageSize.x;
	exit->scale.y = exit->imageSize.y;
	exit->scale *= 3;

	playbox = new ObRect();
	playbox->scale = Vector2(250, 50);
	playbox->color = Color(0.2, 0.2, 0.2, 0.0);

	exitbox = new ObRect();
	exitbox->scale = Vector2(250, 50);
	exitbox->color = Color(0.2, 0.2, 0.2, 0.0);

	bar = new ObRect();
	bar->scale = Vector2(250, 1000);
	bar->color = Color(0.2, 0.2, 0.2, 0.1);
}


Scene1::~Scene1()
{
	delete logo;
	delete background;
	delete planet;
	delete bar;
	delete exitbox;
	delete playbox;
	delete play;
	delete exit;
}

void Scene1::Init()
{
	logo->SetWorldPos(Vector2(0,280));
	planet->SetWorldPos(Vector2(150,-30));

	bar->SetWorldPos(Vector2(-250,0 ));
	play->SetWorldPos(Vector2(-340,150));
	exit->SetWorldPos(Vector2(-340,50));
	playbox->SetWorldPos(Vector2(-250,150));
	exitbox->SetWorldPos(Vector2(-250,50));



}

void Scene1::Release()
{
}

void Scene1::Update()
{
	ImGui::Text("FPS : %d", (int)TIMER->GetFramePerSecond());
	app.background = Color(0.0, 0.0, 0.0);

	if (playbox->Intersect(INPUT->GetWorldMousePos()))
	{
		playbox->color = Color(0.5, 0.5, 0.5, 0.1);
		//if (INPUT->KeyPress(VK_LBUTTON));
	}
	else playbox->color = Color(0.2, 0.2, 0.2, 0.0);

	if (exitbox->Intersect(INPUT->GetWorldMousePos()))
	{
		exitbox->color = Color(0.5, 0.5, 0.5, 0.1);
		if (INPUT->KeyPress(VK_LBUTTON)) PostQuitMessage(0);;
	}
	else exitbox->color = Color(0.2, 0.2, 0.2, 0.0);




	background->Update();
	logo->Update();
	planet->Update();
	
	bar->Update();
	playbox->Update();
	exitbox->Update();
	play->Update();
	exit->Update();

}

void Scene1::LateUpdate()
{
}

void Scene1::Render()
{
	background->Render();
	planet->Render();

	bar->Render();
	playbox->Render();
	exitbox->Render();
	play->Render();
	exit->Render();

	logo->Render();
}

void Scene1::ResizeScreen()
{
	
}


