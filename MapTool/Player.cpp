#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

Player::Player()
{
    //본체
    alpha = new ObImage(L"unit/alpha.gif");
    alpha->maxFrame = Int2{1,1};
    alpha->scale.x = alpha->imageSize.x;
    alpha->scale.y = alpha->imageSize.y;

    scale.x = alpha->imageSize.x;
    scale.y = alpha->imageSize.y;
    //scale *= 0.9f;

    alpha->SetParentRT(*this);
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
    for (int i = 0;i < MAXBULLET;i++)
    {
        delete bullet[i];
    }

}

void Player::Init()
{
    this->SetWorldPos(Vector2(0, 0));


}

void Player::Update()
{
	ObCircle::Update();
    Look();
    Move();
    alpha->Update();
    for (int i = 0;i < MAXBULLET;i++)
    {
        bullet[i]->Update();
    }
}

void Player::Render()
{
    ObCircle::Render();
    alpha->Render();
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

        for (int i = 0;i < MAXBULLET;i++)
        {
            if (bullet[i].Getisfire() == false)
            {
                bullet[i].Fire(this);
            }
        }
    }
    //이동
    else if(isMove)
    {
        float MD = atan2f(movedir.y, movedir.x) - HALFPI;
        this->rotation.z = MD;
    }

    
}
