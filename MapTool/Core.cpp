#include "stdafx.h"
#include "BF_framework.h"


Core::Core(Int2 location, ObTileMap* M)
{
    this->location = location;
}

Core::~Core()
{

}

void Core::Update(ObTileMap* M, BFM* bfm,UI* ui)
{
    ui->SetcopperCapacity(itemCapacity);
}

void Core::GetItem(UI* ui)
{
    ui->SetcopperCapacity(1);
    //if (itemCapacity < MaxCapacity) itemCapacity++;
}
