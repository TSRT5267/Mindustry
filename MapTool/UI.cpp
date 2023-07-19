#include "stdafx.h"
#include "UI.h"

UI::UI()
{
	//����
	UIbackground =	new ObRect();
	for (int i = 0;i < 5;i++)
	{
		UIoutline[i] = new ObRect();
		UIoutline[i]->SetParentRT(*UIbackground);
	}
	//ũ�� (�ӽ�)
	UIbackground->	scale = Vector2(300, 250);
	for (int i = 0;i < 5;i++)
	{
		UIoutline[i]->scale = Vector2(300, 250);
	}
	
	//��
	UIbackground->color = Color(0.1, 0.1, 0.1,0.3);
	for (int i = 0;i < 5;i++)
	{
		UIoutline[i]->color = Color(0.1, 0.1, 0.1);
	}
	


}

UI::~UI()
{
	delete UIbackground;
	for (int i = 0;i < 5;i++)
	{
		delete UIoutline[i];
	}
}

void UI::Init()
{
	
}

void UI::Update()
{
	//UI ũ�� ����	
	UIbackground->	scale = Vector2(300, 250) * CAM->scale;
	UIoutline[0]->scale = Vector2(305, 5) * CAM->scale;//��
	UIoutline[1]->scale = Vector2(305, 5) * CAM->scale;//�Ʒ�
	UIoutline[2]->scale = Vector2(5, 255) * CAM->scale;//��
	UIoutline[3]->scale = Vector2(5, 255) * CAM->scale;//����
	UIoutline[4]->scale = Vector2(5, 250) * CAM->scale;//�и���

	//UI ��ġ ����
	UIbackground->SetWorldPos((CAM->position / CAM->scale + Vector2(280, -180)) * CAM->scale);
	UIoutline[0]->SetLocalPos(Vector2(0,125) * CAM->scale);//��
	UIoutline[1]->SetLocalPos(Vector2(0, -125) * CAM->scale);//�Ʒ�
	UIoutline[2]->SetLocalPos(Vector2(-150, 0) * CAM->scale);//��
	UIoutline[3]->SetLocalPos(Vector2(150, 0) * CAM->scale);//����
	UIoutline[4]->SetLocalPos(Vector2(50, 0) * CAM->scale);//�и���
	//UIoutline[4]->SetLocalPos((CAM->position / CAM->scale + Vector2(0, 0)) * CAM->scale);//�и���



	UIbackground->	Update();
	for (int i = 0;i < 5;i++)
	{
		UIoutline[i]->Update();
	}
}

void UI::LateUpdate()
{
}

void UI::Render()
{
	UIbackground->	Render();
	for (int i = 0;i < 5;i++)
	{
		UIoutline[i]->Render();
	}
}


