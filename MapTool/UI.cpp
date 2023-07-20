#include "stdafx.h"
#include "UI.h"

UI::UI()
{
	//����
	UIcamera =		new Camera();
	UIbackground =	new ObRect();
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
			turretCol[i] -> SetParentRT(*UIbackground);
			turretBorder[i] = new ObRect();
			turretBorder[i] -> SetParentRT(*turretCol[i]);
			turretIM[i]->SetParentRT(*turretCol[i]);
		}
	}
	//ī�װ�(����)
	{
		productionIM[0] = new ObImage(L"2x2block/mechanical_drill.jpg");
		for (int i = 0;i < MAXTURRET;i++)
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
		distributionIM[0] = new ObImage();
		distributionIM[1] = new ObImage();
		distributionIM[2] = new ObImage();
		for (int i = 0;i < MAXTURRET;i++)
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
		defenseIM[0] = new ObImage();
		for (int i = 0;i < MAXTURRET;i++)
		{
			defenseCol[i] = new ObRect();
			defenseCol[i]->SetParentRT(*UIbackground);
			defenseBorder[i] = new ObRect();
			defenseBorder[i]->SetParentRT(*defenseCol[i]);
			defenseIM[i]->SetParentRT(*defenseCol[i]);
		}
	}


	//ũ��
	UIbackground->scale = Vector2(300, 250);
	UIoutline[0]->scale = Vector2(305, 5);//��
	UIoutline[1]->scale = Vector2(305, 5);//�Ʒ�
	UIoutline[2]->scale = Vector2(5, 255);//��
	UIoutline[3]->scale = Vector2(5, 255);//����
	UIoutline[4]->scale = Vector2(5, 250);//�и���
	for (int i = 0;i < MAXCATEGORY;i++)
	{
		categoryIm[i]->scale = Vector2(35, 35);
		categoryCol[i]->scale = categoryIm[i]->scale;
		categoryCol[i]->scale *= 1.3f;
		categoryBorder[i]->scale = categoryCol[i]->scale;
		categoryBorder[i]->scale *= 0.9;
	}


	//��
	UIbackground->color = Color(0.1f, 0.1f, 0.1f,0.3f);
	for (int i = 0;i < MAXUIOUTLINE;i++)
	{
		UIoutline[i]->color = Color(0.1f, 0.1f, 0.1f);
	}
	for (int i = 0;i < MAXCATEGORY;i++)
	{	
		categoryCol[i]->	color = Color(0.1f, 0.1f, 0.1f, 0);
		categoryBorder[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
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
	for (int i = 0;i < MAXCATEGORY;i++)
	{

		delete categoryCol[i];
		delete categoryBorder[i];
		delete categoryIm[i];
	}
}

void UI::Init()
{
	//��ġ
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
}

void UI::Update()
{	

	Vector2 UImousePos = INPUT->GetWorldMousePos() / CAM->scale;
	UImousePos.x -=   (CAM->position.x / CAM->scale);
	UImousePos.y -=  (CAM->position.y / CAM->scale);

	//ī�װ� ����
	for (int i = 0;i < MAXCATEGORY;i++)
	{
		if (selectCategory == i)
		{
			categoryCol[i]->color = Color(0.5f, 0.4f, 0.2f, 1);
			categoryBorder[i]->color = Color(0.0f, 0.0f, 0.0f, 1);
		}
		else
		{
			categoryBorder[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
			if (categoryCol[i]->Intersect(UImousePos))
			{
				categoryCol[i]->color = Color(0.1f, 0.1f, 0.1f, 1);
				if (INPUT->KeyDown(VK_LBUTTON))
				{
					selectCategory = i;
				}
			}
			else categoryCol[i]->color = Color(0.1f, 0.1f, 0.1f, 0);
		}
	}

	//ī�װ� ���빰










	UIbackground->	Update();
	for (int i = 0;i < 5;i++)
	{
		UIoutline[i]->Update();
	}
	for (int i = 0;i < MAXCATEGORY;i++)
	{
		categoryCol[i]->Update();
		categoryIm[i]->Update();
		categoryBorder[i]->Update();
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
	for (int i = 0;i < MAXCATEGORY;i++)
	{
		categoryCol[i]->Render(UIcamera);
		categoryBorder[i]->Render(UIcamera);
		categoryIm[i]->Render(UIcamera);
		

	}
}


