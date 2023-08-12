#include "stdafx.h"
#include "Scene2.h"
#include "UI.h"


UI::UI()
{
	//매뉴
	{
		menuBackground = new ObRect();
		menuBackground->scale = Vector2(900, 700);
		menuBackground->color = Color(0.01f, 0.01f, 0.01f, 0.4f);

		manutxt = new ObImage(L"ui/manu_txt.png");
		manutxt->scale.x = manutxt->imageSize.x;
		manutxt->scale.y = manutxt->imageSize.y;
		

		underline = new ObRect();
		underline->scale = Vector2(900, 3);
		underline->color = Color(0.5f, 0.4f, 0.2f, 1);

		backButtonCol = new ObRect();
		backButton = new ObImage(L"ui/button.png");
		backButton->SetParentRT(*backButtonCol);
		backButtonOver = new ObImage(L"ui/button_over.png");
		backButtonOver->SetParentRT(*backButtonCol);
		backButtonIM = new ObImage(L"ui/back.png");
		backButtonIM->SetParentRT(*backButtonCol);
		backButtontxt = new ObImage(L"ui/back_txt.png");
		backButtontxt->SetParentRT(*backButtonCol);
		exitButtonCol = new ObRect();
		exitButton = new ObImage(L"ui/button.png");
		exitButton->SetParentRT(*exitButtonCol);
		exitButtonOver = new ObImage(L"ui/button_over.png");
		exitButtonOver->SetParentRT(*exitButtonCol);
		exitButtonIM = new ObImage(L"ui/exit.png");
		exitButtonIM->SetParentRT(*exitButtonCol);
		exitButtontxt = new ObImage(L"ui/exit_txt.png");
		exitButtontxt->SetParentRT(*exitButtonCol);

		backButton->scale.x = backButton->imageSize.x;
		backButton->scale.y = backButton->imageSize.y;
		backButtonOver->scale.x = backButtonOver->imageSize.x;
		backButtonOver->scale.y = backButtonOver->imageSize.y;
		backButtonIM->scale.x = backButtonIM->imageSize.x;
		backButtonIM->scale.y = backButtonIM->imageSize.y;
		backButtonIM->scale *= 2;
		backButtontxt->scale.x = backButtontxt->imageSize.x;
		backButtontxt->scale.y = backButtontxt->imageSize.y;
		exitButton->scale.x = exitButton->imageSize.x;
		exitButton->scale.y = exitButton->imageSize.y;
		exitButtonOver->scale.x = exitButtonOver->imageSize.x;
		exitButtonOver->scale.y = exitButtonOver->imageSize.y;
		exitButtonIM->scale.x = exitButtonIM->imageSize.x;
		exitButtonIM->scale.y = exitButtonIM->imageSize.y;
		exitButtonIM->scale *= 2;
		exitButtontxt->scale.x = exitButtontxt->imageSize.x;
		exitButtontxt->scale.y = exitButtontxt->imageSize.y;

		backButtonCol->scale = backButton->scale;
		exitButtonCol->scale = exitButton->scale;
	}
	
	

	//생성
	{
		UIcamera = new Camera();
		UIbackground = new ObRect();
		for (int i = 0;i < MAXUIOUTLINE;i++)
		{
			UIoutline[i] = new ObRect();
			UIoutline[i]->SetParentRT(*UIbackground);
		}
		//카테고리
		{
			categoryIm[0] = new ObImage(L"ui/turret.png");
			categoryIm[1] = new ObImage(L"ui/production.png");
			categoryIm[2] = new ObImage(L"ui/distribution.png");
			categoryIm[3] = new ObImage(L"ui/defense.png");
			for (int i = 0;i < MAXCATEGORY;i++)
			{
				categoryCol[i] = new ObRect();
				categoryCol[i]->SetParentRT(*UIbackground);
				categoryBorder[i] = new ObRect();
				categoryBorder[i]->SetParentRT(*categoryCol[i]);
				categoryIm[i]->SetParentRT(*categoryCol[i]);
			}
		}
		//카테고리(터렛)
		{
			turretIM[0] = new ObImage(L"1x1block/duo.png");
			for (int i = 0;i < MAXTURRET;i++)
			{
				turretCol[i] = new ObRect();
				turretCol[i]->SetParentRT(*UIbackground);
				turretBorder[i] = new ObRect();
				turretBorder[i]->SetParentRT(*turretCol[i]);
				turretIM[i]->SetParentRT(*turretCol[i]);
			}
		}
		//카테고리(생산)
		{
			productionIM[0] = new ObImage(L"2x2block/mechanical_drill.png");
			productionIM[1] = new ObImage(L"2x2block/core.png");
			for (int i = 0;i < MAXPRODUCTION;i++)
			{
				productionCol[i] = new ObRect();
				productionCol[i]->SetParentRT(*UIbackground);
				productionBorder[i] = new ObRect();
				productionBorder[i]->SetParentRT(*productionCol[i]);
				productionIM[i]->SetParentRT(*productionCol[i]);
			}
		}
		//카테고리(분배)
		{
			distributionIM[0] = new ObImage(L"1x1block/conveyor_up.png");
			distributionIM[1] = new ObImage(L"1x1block/conveyor_down.png");
			distributionIM[2] = new ObImage(L"1x1block/conveyor_left.png");
			distributionIM[3] = new ObImage(L"1x1block/conveyor_right.png");
			distributionIM[4] = new ObImage(L"1x1block/junction.png");
			distributionIM[5] = new ObImage(L"1x1block/router.png");
			for (int i = 0;i < MAXDISTRIBUTION;i++)
			{
				distributionCol[i] = new ObRect();
				distributionCol[i]->SetParentRT(*UIbackground);
				distributionBorder[i] = new ObRect();
				distributionBorder[i]->SetParentRT(*distributionCol[i]);
				distributionIM[i]->SetParentRT(*distributionCol[i]);
			}
		}
		//카테고리(방어)
		{
			defenseIM[0] = new ObImage(L"1x1block/copper_wall.png");
			for (int i = 0;i < MAXDEFENSE;i++)
			{
				defenseCol[i] = new ObRect();
				defenseCol[i]->SetParentRT(*UIbackground);
				defenseBorder[i] = new ObRect();
				defenseBorder[i]->SetParentRT(*defenseCol[i]);
				defenseIM[i]->SetParentRT(*defenseCol[i]);
			}
		}
	}
	
	//크기
	{
		UIbackground->scale = Vector2(300, 250);
		UIoutline[0]->scale = Vector2(305, 5);//위
		UIoutline[1]->scale = Vector2(305, 5);//아래
		UIoutline[2]->scale = Vector2(5, 255);//왼
		UIoutline[3]->scale = Vector2(5, 255);//오른
		UIoutline[4]->scale = Vector2(5, 250);//분리선
		//카테고리
		for (int i = 0;i < MAXCATEGORY;i++)
		{
			categoryIm[i]->scale = Vector2(35, 35);
			categoryCol[i]->scale = categoryIm[i]->scale;
			categoryCol[i]->scale *= 1.3f;
			categoryBorder[i]->scale = categoryCol[i]->scale;
			categoryBorder[i]->scale *= 0.9;
		}
		//터렛
		for (int i = 0;i < MAXTURRET;i++)
		{
			turretIM[i]->scale = Vector2(30, 30);
			turretCol[i]->scale = turretIM[i]->scale;
			turretCol[i]->scale *= 1.3f;
			turretBorder[i]->scale = turretCol[i]->scale;
			turretBorder[i]->scale *= 0.8;
		}
		//생산
		for (int i = 0;i < MAXPRODUCTION;i++)
		{
			productionIM[i]->scale = Vector2(30, 30);
			productionCol[i]->scale = productionIM[i]->scale;
			productionCol[i]->scale *= 1.3f;
			productionBorder[i]->scale = productionCol[i]->scale;
			productionBorder[i]->scale *= 0.8;
		}
		//분배
		for (int i = 0;i < MAXDISTRIBUTION;i++)
		{
			distributionIM[i]->scale = Vector2(30, 30);
			distributionCol[i]->scale = distributionIM[i]->scale;
			distributionCol[i]->scale *= 1.3f;
			distributionBorder[i]->scale = distributionCol[i]->scale;
			distributionBorder[i]->scale *= 0.8;
		}
		//방어
		for (int i = 0;i < MAXDEFENSE;i++)
		{
			defenseIM[i]->scale = Vector2(30, 30);
			defenseCol[i]->scale = defenseIM[i]->scale;
			defenseCol[i]->scale *= 1.3f;
			defenseBorder[i]->scale = defenseCol[i]->scale;
			defenseBorder[i]->scale *= 0.8;
		}
	}

	//색
	{
		UIbackground->color = Color(0.1f, 0.1f, 0.1f, 0.3f);
		for (int i = 0;i < MAXUIOUTLINE;i++)
		{
			UIoutline[i]->color = Color(0.1f, 0.1f, 0.1f);
		}
		//카테고리
		for (int i = 0;i < MAXCATEGORY;i++)
		{
			categoryCol[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
			categoryBorder[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
		}
		//터렛
		for (int i = 0;i < MAXTURRET;i++)
		{
			turretCol[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
			turretBorder[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
		}
		//생산
		for (int i = 0;i < MAXPRODUCTION;i++)
		{
			productionCol[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
			productionBorder[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
		}
		//분배
		for (int i = 0;i < MAXDISTRIBUTION;i++)
		{
			distributionCol[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
			distributionBorder[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
		}
		//방어
		for (int i = 0;i < MAXDEFENSE;i++)
		{
			defenseCol[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
			defenseBorder[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
		}
	}

	//인벤토리
	invenbackground = new ObRect();
	invenbackground->scale = Vector2(250, 32);
	invenbackground->color = Color(0.01f, 0.01f, 0.01f, 0.4f);
	for (int i = 0;i < 4;i++)
	{
		numberFont[i] = new ObImage(L"ui/numberFont.png");
		numberFont[i]->scale.x = numberFont[i]->imageSize.x /10.0f;
		numberFont[i]->scale.y = numberFont[i]->imageSize.y;
		numberFont[i]->maxFrame.x = 10;
		numberFont[i]->SetParentRT(*invenbackground);
	}
	
	
	copperIcon = new ObImage(L"item_copper.png");
	copperIcon->scale.x = copperIcon->imageSize.x;
	copperIcon->scale.y = copperIcon->imageSize.y;
	copperIcon->scale *= 0.5f;
	copperIcon->SetParentRT(*invenbackground);

	//일시정지
	pausebackground = new ObRect();
	pausebackground->scale = Vector2(250, 32);
	pausebackground->color = Color(0.01f, 0.01f, 0.01f, 0.4f);
	pauseImage = new ObImage(L"ui/pause.png");
	pauseImage->scale.x = pauseImage->imageSize.x;
	pauseImage->scale.y = pauseImage->imageSize.y;
	pauseImage->scale *= 0.5;
	pauseImage->SetParentRT(*pausebackground);
}

UI::~UI()
{
	delete UIcamera;	
	delete UIbackground;
	//메뉴
	delete menuBackground;
	delete manutxt;
	delete underline;
	delete backButtonCol;
	delete backButton;
	delete backButtonIM;
	delete backButtontxt;
	delete exitButtonCol;
	delete exitButton;
	delete exitButtonIM;
	delete exitButtontxt;
	for (int i = 0;i < MAXUIOUTLINE;i++)
	{
		delete UIoutline[i];
	}
	//카테고리
	for (int i = 0;i < MAXCATEGORY;i++)
	{
		delete categoryCol[i];
		delete categoryBorder[i];
		delete categoryIm[i];
	}
	//터렛
	for (int i = 0;i < MAXTURRET;i++)
	{
		delete turretCol[i];
		delete turretBorder[i];
		delete turretIM[i];
	}
	//생산
	for (int i = 0;i < MAXPRODUCTION;i++)
	{
		delete productionCol[i];
		delete productionBorder[i];
		delete productionIM[i];
	}
	//분배
	for (int i = 0;i < MAXDISTRIBUTION;i++)
	{
		delete distributionCol[i];
		delete distributionBorder[i];
		delete distributionIM[i];
	}
	//방어
	for (int i = 0;i < MAXDEFENSE;i++)
	{
		delete defenseCol[i];
		delete defenseBorder[i];
		delete defenseIM[i];
	}

	//인벤토리
	delete invenbackground;
	delete copperIcon;
	for (int i = 0;i < 4;i++)
	{
		delete numberFont[i];
	}
	//일시정지
	delete pausebackground;
	delete pauseImage;

}

void UI::Init()
{
	menuBackground->SetWorldPos(Vector2(0, 0));
	manutxt->SetWorldPos(Vector2(0, 320));
	underline->SetWorldPos(Vector2(0, 300));
	backButtonCol->SetWorldPos(Vector2(-130, 0));
	backButtonIM->SetLocalPos(Vector2(-90, 0));
	backButtontxt->SetLocalPos(Vector2(20, 0));
	exitButtonCol->SetWorldPos(Vector2(130, 0));
	exitButtonIM->SetLocalPos(Vector2(-90, 0));
	exitButtontxt->SetLocalPos(Vector2(20, 0));
	
	UIbackground->SetWorldPos(Vector2(280, -180));
	UIoutline[0]->SetLocalPos(Vector2(0, 125));//위
	UIoutline[1]->SetLocalPos(Vector2(0, -125));//아래
	UIoutline[2]->SetLocalPos(Vector2(-150, 0));//왼
	UIoutline[3]->SetLocalPos(Vector2(150, 0));//오른
	UIoutline[4]->SetLocalPos(Vector2(50, 0));//분리선

	categoryCol[0]->SetLocalPos(Vector2(75, 100));
	categoryCol[1]->SetLocalPos(Vector2(125, 100));
	categoryCol[2]->SetLocalPos(Vector2(75, 50));
	categoryCol[3]->SetLocalPos(Vector2(125, 50));

	turretCol[0]->SetLocalPos(Vector2(-125,100));

	productionCol[0]->SetLocalPos(Vector2(-125, 100));
	productionCol[1]->SetLocalPos(Vector2(-85, 100));

	distributionCol[0]->SetLocalPos(Vector2(-125, 100));
	distributionCol[1]->SetLocalPos(Vector2(-85, 100));;
	distributionCol[2]->SetLocalPos(Vector2(-45, 100));;
	distributionCol[3]->SetLocalPos(Vector2(-5, 100));;
	distributionCol[4]->SetLocalPos(Vector2(-125, 60));;
	distributionCol[5]->SetLocalPos(Vector2(-85, 60));;

	defenseCol[0]->SetLocalPos(Vector2(-125, 100));

	//인벤토리
	invenbackground->SetLocalPos(Vector2(0, 330));
	copperIcon->SetWorldPos(Vector2(20, 0));
	for (int i = 0;i < 4;i++)
	{
		numberFont[i]->SetLocalPos(Vector2(-20*i, 0));
	}
	//일시정지
	pausebackground->SetLocalPos(Vector2(0, 300));;
}

void UI::Update()
{	

	UImousePos = INPUT->GetWorldMousePos() / CAM->scale;
	UImousePos.x -=   (CAM->position.x / CAM->scale);
	UImousePos.y -=  (CAM->position.y / CAM->scale);

	//매뉴
	if (INPUT->KeyDown(VK_ESCAPE))
	{
		if(menu_Activatetion == true) menu_Activatetion = false;
		else menu_Activatetion = true;
	}

	if (menu_Activatetion == true)
	{
		if (backButtonCol->Intersect(UImousePos) and INPUT->KeyDown(VK_LBUTTON))
		{
			SOUND->Stop("game");
			SOUND->Play("lobby");
			CAM->position = Vector2(0, 0);
			WIN->zoomsize = 1.0f;
			menu_Activatetion = false;
			SCENE->ChangeScene("SC1");
		}

		if (exitButtonCol->Intersect(UImousePos) and INPUT->KeyDown(VK_LBUTTON))
		{
			doSave = true;
		}
	}
	else
	{
		//선택 초기화
		if (INPUT->KeyDown(VK_RBUTTON))
		{
			selectCategory = (int)CATEGORY::NONE;
			selectTurret = (int)CATEGORY::NONE;
			selectProduction = (int)CATEGORY::NONE;
			selectDistribution = (int)CATEGORY::NONE;
			selectDefense = (int)CATEGORY::NONE;
		}
		
		//선택 
		Select(MAXCATEGORY, categoryCol, categoryBorder, selectCategory);
		Select(MAXTURRET, turretCol, turretBorder, selectTurret);
		Select(MAXPRODUCTION, productionCol, productionBorder, selectProduction);
		Select(MAXDISTRIBUTION, distributionCol, distributionBorder, selectDistribution);
		Select(MAXDEFENSE, defenseCol, defenseBorder, selectDefense);
	}

	//인벤토리
	int CC = copperCapacity;
	for (int i = 0;i < 4;i++)
	{
		numberFont[i]->frame.x = CC % 10;
		CC /= 10;
	}

	

	//일시정지
	if (INPUT->KeyDown(VK_SPACE))
	{
		if (ispause == true) ispause = false;
		else ispause = true;
	}

	

	
		

		
	
	







	
	//업데이트
	{
		UIbackground->Update();
		for (int i = 0;i < 5;i++)
		{
			UIoutline[i]->Update();
		}
		//카테고리
		for (int i = 0;i < MAXCATEGORY;i++)
		{
			categoryCol[i]->Update();
			categoryIm[i]->Update();
			categoryBorder[i]->Update();
		}
		//터렛
		for (int i = 0;i < MAXTURRET;i++)
		{
			turretCol[i]->Update();
			turretBorder[i]->Update();
			turretIM[i]->Update();
		}
		//생산
		for (int i = 0;i < MAXPRODUCTION;i++)
		{
			productionCol[i]->Update();
			productionBorder[i]->Update();
			productionIM[i]->Update();
		}
		//분배
		for (int i = 0;i < MAXDISTRIBUTION;i++)
		{
			 distributionCol[i]->Update();
			 distributionBorder[i]->Update();
			 distributionIM[i]->Update();
		}
		//방어
		for (int i = 0;i < MAXDEFENSE;i++)
		{
			 defenseCol[i]->Update();
			 defenseBorder[i]->Update();
			 defenseIM[i]->Update();
		}
		//매뉴
		{
			menuBackground->Update();
			manutxt->Update();
			underline->Update();
			backButtonCol->Update();
			backButton->Update();
			backButtonOver->Update();
			backButtonIM->Update();
			backButtontxt->Update();
			exitButtonCol->Update();
			exitButton->Update();
			exitButtonOver->Update();
			exitButtonIM->Update();
			exitButtontxt->Update();
		}
		//인벤토리
		invenbackground->Update();
		copperIcon->Update();
		for (int i = 0;i < 4;i++)
		{
			numberFont[i]->Update();	
		}
		//일시정지
		pausebackground->Update();
		pauseImage->Update();
	}
	
}

void UI::LateUpdate()
{
}

void UI::Render()
{
	UIcamera->Set();
	UIbackground->	Render(UIcamera);
	for (int i = 0;i < 5;i++)
	{
		UIoutline[i]->Render(UIcamera);
	}
	//카테고리
	for (int i = 0;i < MAXCATEGORY;i++)
	{
		categoryCol[i]->Render(UIcamera);
		categoryBorder[i]->Render(UIcamera);
		categoryIm[i]->Render(UIcamera);
	}
	switch (selectCategory)
	{
	case 0:
		//터렛
		for (int i = 0;i < MAXTURRET;i++)
		{
			turretCol[i]->Render(UIcamera);
			turretBorder[i]->Render(UIcamera);
			turretIM[i]->Render(UIcamera);
		}
		break;
	case 1:
		//생산
		for (int i = 0;i < MAXPRODUCTION;i++)
		{
			productionCol[i]->Render(UIcamera);
			productionBorder[i]->Render(UIcamera);
			productionIM[i]->Render(UIcamera);
		}
		break;
	case 2:
		//분배
		for (int i = 0;i < MAXDISTRIBUTION;i++)
		{
			distributionCol[i]->Render(UIcamera);
			distributionBorder[i]->Render(UIcamera);
			distributionIM[i]->Render(UIcamera);
		}
		break;
	case 3:
		//방어
		for (int i = 0;i < MAXDEFENSE;i++)
		{
			defenseCol[i]->Render(UIcamera);
			defenseBorder[i]->Render(UIcamera);
			defenseIM[i]->Render(UIcamera);
		}
		break;
	default:
		break;
	}
	
	//인벤토리
	invenbackground->Render(UIcamera);
	copperIcon->Render(UIcamera);
	int CC = copperCapacity;
	if (numberFont[3]->frame.x != 0)numberFont[3]->Render(UIcamera);
	if (numberFont[3]->frame.x != 0 or numberFont[2]->frame.x != 0)numberFont[2]->Render(UIcamera);
	if (numberFont[3]->frame.x != 0 or numberFont[2]->frame.x != 0 
		or numberFont[1]->frame.x != 0)numberFont[1]->Render(UIcamera);
	numberFont[0]->Render(UIcamera);
	//일시정지
	if (ispause == true)
	{
		pausebackground->Render(UIcamera);
		pauseImage->Render(UIcamera);
	}
	//메뉴
	if (menu_Activatetion == true)
	{
		menuBackground->Render(UIcamera);
		manutxt->Render(UIcamera);
		underline->Render(UIcamera);		

		if (backButtonCol->Intersect(UImousePos))
		{
			backButtonOver->Render(UIcamera);
		}
		else backButton->Render(UIcamera);

		if (exitButtonCol->Intersect(UImousePos))
		{
			exitButtonOver->Render(UIcamera);
		}
		else exitButton->Render(UIcamera);

		backButtonIM->Render(UIcamera);
		backButtontxt->Render(UIcamera);
		exitButtonIM->Render(UIcamera);
		exitButtontxt->Render(UIcamera);
	}
	
	
	

}

void UI::Select(int C, ObRect* Col[],ObRect* Border[],int& select)
{
	
	for (int i = 0;i < C;i++)
	{
		if (select == i)
		{
			Col[i]->color = Color(0.5f, 0.4f, 0.2f, 1);
			Border[i]->color = Color(0.0f, 0.0f, 0.0f, 1);
		}
		else
		{
			Border[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
			if (Col[i]->Intersect(UImousePos))
			{
				Col[i]->color = Color(0.1f, 0.1f, 0.1f, 1);
				if (INPUT->KeyDown(VK_LBUTTON))
				{
					select = i;
				}
			}
			else Col[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
		}
	}
	
}

bool UI::UIIntersect()
{
	if (UIbackground->Intersect(UImousePos)) return true;
	else return false;
	
}


