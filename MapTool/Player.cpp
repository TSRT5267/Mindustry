#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

Player::Player()
{
    //본체
    alpha = new ObImage(L"unit/alpha.png");
    alpha->maxFrame = Int2{1,1};
    alpha->scale.x = alpha->imageSize.x;
    alpha->scale.y = alpha->imageSize.y;
    //그림자
    shadow = new ObImage(L"unit/alpha.png");
    shadow->maxFrame = Int2{ 1,1 };
    shadow->scale.x = shadow->imageSize.x * 0.8;
    shadow->scale.y = shadow->imageSize.y * 0.8;
    shadow->color = Color{ 0, 0, 0, 0.3 };

    scale.x = alpha->imageSize.x;
    scale.y = alpha->imageSize.y;
    color = Color{ 1,1,1 ,0};

    alpha->SetParentRT(*this);
    shadow->SetParentT(*this);
    isFilled = false;

    //총알
    for (int i = 0;i < MAXBULLET;i++)
    {
        bullet[i] = new Bullet();
    }

}

Player::~Player()
{
    delete alpha;
    delete shadow;
    for (int i = 0;i < MAXBULLET;i++)
    {
        delete bullet[i];
    }

}

void Player::Init()
{
    this->SetWorldPos(Vector2(0, 0));
    shadow->SetWorldPos(Vector2(-30, -30));

}

void Player::Update()
{
	ObCircle::Update();
    if(app.deltaScale)
    { 
        Look();
        Move();
        Attack();
    } 
    shadow->rotation.z = this->rotation.z;


    alpha->Update();
    shadow->Update();
    for (int i = 0;i < MAXBULLET;i++)
    {
        bullet[i]->Update();
    }
}

void Player::Render()
{
    ObCircle::Render();
    alpha->Render();
    shadow->Render();
    for (int i = 0;i < MAXBULLET;i++)
    {
        bullet[i]->Render();
    }
}

void Player::Move()
{
    movedir = Vector2();

    //계속 누를때
    if (INPUT->KeyPress('W'))
    {
        movedir.y = 1.0f;
    }
    if (INPUT->KeyPress('S'))
    {
        movedir.y = -1.0f;
    }
    if (INPUT->KeyPress('A'))
    {
        movedir.x = -1.0f;
    }
    if (INPUT->KeyPress('D'))
    {
        movedir.x = 1.0f;
    }
    movedir.Normalize();

    if (movedir == Vector2{ 0,0 }) isMove = false;
    else isMove = true;

    MoveWorldPos(movedir * DELTA * MOVESPEED*16);
}

void Player::Look()
{
    //보는 방향 우선순위
    //건축
    if (false)
    {
        
    }
    //공격
    else if(INPUT->KeyPress(VK_LBUTTON))
    {
        attdir = this->GetWorldPivot() - INPUT->GetWorldMousePos();
        this->rotation.z = atan2f(attdir.y, attdir.x) + HALFPI;
        
        
        
    }
    //이동
    else if(isMove)
    {
        float MD = atan2f(movedir.y, movedir.x) - HALFPI;
        this->rotation.z = MD;
    }

    
}

void Player::Attack()
{
    
    if (TIMER->GetTick(firedelay, 0.2f) and INPUT->KeyPress(VK_LBUTTON))
    {
        for (int i = 0;i < MAXBULLET;i++)
        {
            if (bullet[i]->Getisfire() == false)
            {
                if (gunSwiching == 0)
                {
                    bullet[i]->Fire(this, gunSwiching);
                    gunSwiching = 1;
                }
                else 
                {
                    bullet[i]->Fire(this, gunSwiching);
                    gunSwiching = 0;
                } 
                break;
            }
        }
    }
}
