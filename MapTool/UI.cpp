#include "stdafx.h"
#include "UI.h"

UI::UI()
{
	//�Ŵ�
	{
		menuBackground = new ObRect();
		menuBackground->scale = Vector2(900, 700);
		menuBackground->color = Color(0.01f, 0.01f, 0.01f, 0.4f);

		underline = new ObRect();
		underline->scale = Vector2(900, 3);
		underline->color = Color(0.5f, 0.4f, 0.2f, 1);

		backButtonCol = new ObRect();
		backButton = new ObImage(L"ui/button.png");
		backButton->SetParentRT(*backButtonCol);
		backButtonIM = new ObImage(L"ui/button.png");
		backButtonIM->SetParentRT(*backButtonCol);
		exitButtonCol = new ObRect();
		exitButton = new ObImage(L"ui/button.png");
		exitButton->SetParentRT(*exitButtonCol);
		exitButtonIM = new ObImage(L"ui/button.png");
		exitButtonIM->SetParentRT(*exitButtonCol);

		backButton->scale.x = backButton->imageSize.x;
		backButton->scale.y = backButton->imageSize.y;
		exitButton->scale.x = exitButton->imageSize.x;
		exitButton->scale.y = exitButton->imageSize.y;
	}
	
	

	//����
	{
		UIcamera = new Camera();
		UIbackground = new ObRect();
		for (int i = 0;i < MAXUIOUTLINE;i++)
		{
			UIoutline[i] = new ObRect();
			UIoutline[i]->SetParentRT(*UIbackground);
		}
		//ī�װ�
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
		//ī�װ�(�ͷ�)
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
		//ī�װ�(����)
		{
			productionIM[0] = new ObImage(L"2x2block/mechanical_drill.jpg");
			for (int i = 0;i < MAXPRODUCTION;i++)
			{
				productionCol[i] = new ObRect();
				productionCol[i]->SetParentRT(*UIbackground);
				productionBorder[i] = new ObRect();
				productionBorder[i]->SetParentRT(*productionCol[i]);
				productionIM[i]->SetParentRT(*productionCol[i]);
			}
		}
		//ī�װ�(�й�)
		{
			distributionIM[0] = new ObImage(L"1x1block/conveyor.png");
			distributionIM[1] = new ObImage(L"1x1block/junction.png");
			distributionIM[2] = new ObImage(L"1x1block/router.png");
			for (int i = 0;i < MAXDISTRIBUTION;i++)
			{
				distributionCol[i] = new ObRect();
				distributionCol[i]->SetParentRT(*UIbackground);
				distributionBorder[i] = new ObRect();
				distributionBorder[i]->SetParentRT(*distributionCol[i]);
				distributionIM[i]->SetParentRT(*distributionCol[i]);
			}
		}
		//ī�װ�(���)
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
	
	//ũ��
	{
		UIbackground->scale = Vector2(300, 250);
		UIoutline[0]->scale = Vector2(305, 5);//��
		UIoutline[1]->scale = Vector2(305, 5);//�Ʒ�
		UIoutline[2]->scale = Vector2(5, 255);//��
		UIoutline[3]->scale = Vector2(5, 255);//����
		UIoutline[4]->scale = Vector2(5, 250);//�и���
		//ī�װ�
		for (int i = 0;i < MAXCATEGORY;i++)
		{
			categoryIm[i]->scale = Vector2(35, 35);
			categoryCol[i]->scale = categoryIm[i]->scale;
			categoryCol[i]->scale *= 1.3f;
			categoryBorder[i]->scale = categoryCol[i]->scale;
			categoryBorder[i]->scale *= 0.9;
		}
		//�ͷ�
		for (int i = 0;i < MAXTURRET;i++)
		{
			turretIM[i]->scale = Vector2(30, 30);
			turretCol[i]->scale = turretIM[i]->scale;
			turretCol[i]->scale *= 1.3f;
			turretBorder[i]->scale = turretCol[i]->scale;
			turretBorder[i]->scale *= 0.8;
		}
		//����
		for (int i = 0;i < MAXPRODUCTION;i++)
		{
			productionIM[i]->scale = Vector2(30, 30);
			productionCol[i]->scale = productionIM[i]->scale;
			productionCol[i]->scale *= 1.3f;
			productionBorder[i]->scale = productionCol[i]->scale;
			productionBorder[i]->scale *= 0.8;
		}
		//�й�
		for (int i = 0;i < MAXDISTRIBUTION;i++)
		{
			distributionIM[i]->scale = Vector2(30, 30);
			distributionCol[i]->scale = distributionIM[i]->scale;
			distributionCol[i]->scale *= 1.3f;
			distributionBorder[i]->scale = distributionCol[i]->scale;
			distributionBorder[i]->scale *= 0.8;
		}
		//���
		for (int i = 0;i < MAXDEFENSE;i++)
		{
			defenseIM[i]->scale = Vector2(30, 30);
			defenseCol[i]->scale = defenseIM[i]->scale;
			defenseCol[i]->scale *= 1.3f;
			defenseBorder[i]->scale = defenseCol[i]->scale;
			defenseBorder[i]->scale *= 0.8;
		}
	}

	//��
	{
		UIbackground->color = Color(0.1f, 0.1f, 0.1f, 0.3f);
		for (int i = 0;i < MAXUIOUTLINE;i++)
		{
			UIoutline[i]->color = Color(0.1f, 0.1f, 0.1f);
		}
		//ī�װ�
		for (int i = 0;i < MAXCATEGORY;i++)
		{
			categoryCol[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
			categoryBorder[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
		}
		//�ͷ�
		for (int i = 0;i < MAXTURRET;i++)
		{
			turretCol[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
			turretBorder[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
		}
		//����
		for (int i = 0;i < MAXPRODUCTION;i++)
		{
			productionCol[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
			productionBorder[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
		}
		//�й�
		for (int i = 0;i < MAXDISTRIBUTION;i++)
		{
			distributionCol[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
			distributionBorder[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
		}
		//���
		for (int i = 0;i < MAXDEFENSE;i++)
		{
			defenseCol[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
			defenseBorder[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
		}
	}
	
}

UI::~UI()
{
	delete UIcamera;
	delete UIbackground;
	for (int i = 0;i < MAXUIOUTLINE;i++)
	{
		delete UIoutline[i];
	}
	//ī�װ�
	for (int i = 0;i < MAXCATEGORY;i++)
	{
		delete categoryCol[i];
		delete categoryBorder[i];
		delete categoryIm[i];
	}
	//�ͷ�
	for (int i = 0;i < MAXTURRET;i++)
	{
		delete turretCol[i];
		delete turretBorder[i];
		delete turretIM[i];
	}
	//����
	for (int i = 0;i < MAXPRODUCTION;i++)
	{
		delete productionCol[i];
		delete productionBorder[i];
		delete productionIM[i];
	}
	//�й�
	for (int i = 0;i < MAXDISTRIBUTION;i++)
	{
		delete distributionCol[i];
		delete distributionBorder[i];
		delete distributionIM[i];
	}
	//���
	for (int i = 0;i < MAXDEFENSE;i++)
	{
		delete defenseCol[i];
		delete defenseBorder[i];
		delete defenseIM[i];
	}
}

void UI::Init()
{
	menuBackground->SetWorldPos(Vector2(0, 0));
	underline->SetWorldPos(Vector2(0, 300));
	backButtonCol->SetWorldPos(Vector2(-130, 50));
	exitButtonCol->SetWorldPos(Vector2(130, 50));
	
	UIbackground->SetWorldPos(Vector2(280, -180));
	UIoutline[0]->SetLocalPos(Vector2(0, 125));//��
	UIoutline[1]->SetLocalPos(Vector2(0, -125));//�Ʒ�
	UIoutline[2]->SetLocalPos(Vector2(-150, 0));//��
	UIoutline[3]->SetLocalPos(Vector2(150, 0));//����
	UIoutline[4]->SetLocalPos(Vector2(50, 0));//�и���

	categoryCol[0]->SetLocalPos(Vector2(75, 100));
	categoryCol[1]->SetLocalPos(Vector2(125, 100));
	categoryCol[2]->SetLocalPos(Vector2(75, 50));
	categoryCol[3]->SetLocalPos(Vector2(125, 50));

	turretCol[0]->SetLocalPos(Vector2(-125,100));

	productionCol[0]->SetLocalPos(Vector2(-125, 100));

	distributionCol[0]->SetLocalPos(Vector2(-125, 100));
	distributionCol[1]->SetLocalPos(Vector2(-85, 100));;
	distributionCol[2]->SetLocalPos(Vector2(-45, 100));;

	defenseCol[0]->SetLocalPos(Vector2(-125, 100));
}

void UI::Update()
{	

	UImousePos = INPUT->GetWorldMousePos() / CAM->scale;
	UImousePos.x -=   (CAM->position.x / CAM->scale);
	UImousePos.y -=  (CAM->position.y / CAM->scale);

	//�Ŵ�
	if (INPUT->KeyDown(VK_ESCAPE))
	{
		if(menu_Activatetion == true) menu_Activatetion = false;
		else menu_Activatetion = true;
	}

	if (menu_Activatetion == true)
	{

	}
	else
	{
		//���� �ʱ�ȭ
		if (INPUT->KeyDown(VK_RBUTTON))
		{
			selectTurret = -1;
			selectProduction = -1;
			selectDistribution = -1;
			selectDefense = -1;
		}

		//���� 
		Select(MAXCATEGORY, categoryCol, categoryBorder, selectCategory);
		Select(MAXTURRET, turretCol, turretBorder, selectTurret);
		Select(MAXPRODUCTION, productionCol, productionBorder, selectProduction);
		Select(MAXDISTRIBUTION, distributionCol, distributionBorder, selectDistribution);
		Select(MAXDEFENSE, defenseCol, defenseBorder, selectDefense);
	}

	

	

	
		

		
	
	







	
	//������Ʈ
	{
		UIbackground->Update();
		for (int i = 0;i < 5;i++)
		{
			UIoutline[i]->Update();
		}
		//ī�װ�
		for (int i = 0;i < MAXCATEGORY;i++)
		{
			categoryCol[i]->Update();
			categoryIm[i]->Update();
			categoryBorder[i]->Update();
		}
		//�ͷ�
		for (int i = 0;i < MAXTURRET;i++)
		{
			turretCol[i]->Update();
			turretBorder[i]->Update();
			turretIM[i]->Update();
		}
		//����
		for (int i = 0;i < MAXPRODUCTION;i++)
		{
			productionCol[i]->Update();
			productionBorder[i]->Update();
			productionIM[i]->Update();
		}
		//�й�
		for (int i = 0;i < MAXDISTRIBUTION;i++)
		{
			 distributionCol[i]->Update();
			 distributionBorder[i]->Update();
			 distributionIM[i]->Update();
		}
		//���
		for (int i = 0;i < MAXDEFENSE;i++)
		{
			 defenseCol[i]->Update();
			 defenseBorder[i]->Update();
			 defenseIM[i]->Update();
		}
		//�Ŵ�
		{
			menuBackground->Update();
			underline->Update();
			backButtonCol->Update();
			backButton->Update();
			backButtonIM->Update();
			exitButtonCol->Update();
			exitButton->Update();
			exitButtonIM->Update();
		}
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
	//ī�װ�
	for (int i = 0;i < MAXCATEGORY;i++)
	{
		categoryCol[i]->Render(UIcamera);
		categoryBorder[i]->Render(UIcamera);
		categoryIm[i]->Render(UIcamera);
	}
	switch (selectCategory)
	{
	case 0:
		//�ͷ�
		for (int i = 0;i < MAXTURRET;i++)
		{
			turretCol[i]->Render(UIcamera);
			turretBorder[i]->Render(UIcamera);
			turretIM[i]->Render(UIcamera);
		}
		break;
	case 1:
		//����
		for (int i = 0;i < MAXPRODUCTION;i++)
		{
			productionCol[i]->Render(UIcamera);
			productionBorder[i]->Render(UIcamera);
			productionIM[i]->Render(UIcamera);
		}
		break;
	case 2:
		//�й�
		for (int i = 0;i < MAXDISTRIBUTION;i++)
		{
			distributionCol[i]->Render(UIcamera);
			distributionBorder[i]->Render(UIcamera);
			distributionIM[i]->Render(UIcamera);
		}
		break;
	case 3:
		//���
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
	
	if (menu_Activatetion == true)
	{
		menuBackground->Render(UIcamera);
		underline->Render(UIcamera);
		backButtonCol->Render(UIcamera);
		backButton->Render(UIcamera);
		//backButtonIM->Render(UIcamera);
		exitButtonCol->Render(UIcamera);
		exitButton-> Render(UIcamera);
		//exitButtonIM->Render(UIcamera);
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


