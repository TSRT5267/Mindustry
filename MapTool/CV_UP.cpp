#include "stdafx.h"
#include "BF_framework.h"



CV_UP::CV_UP(Int2 location, ObTileMap* M)
{
	this->location = location;
	item = new ObImage(L"item_copper.png");
	item->scale.x = item->imageSize.x;
	item->scale.y = item->imageSize.y;
	item->scale *= 0.8f;	
	item->SetWorldPos(M->GetTilePosition(this->location)*32 + Vector2(-784,-784));
	
}

CV_UP::~CV_UP()
{
	delete item;
}

void CV_UP::Update(ObTileMap* M)
{
	if (itemCapacity > 0) hasItem = true;
	else hasItem = false;

	item->Update();
}

void CV_UP::Render()
{
	if(hasItem) item->Render();
}

void CV_UP::SandItem(BFM* bfm, ObTileMap* M)
{
	//if (itemCapacity > 0 and findCV == true and TIMER->GetTick(sendDelay, 2.5f))

}

void CV_UP::GetItem()
{
	if (itemCapacity < MaxCapacity) itemCapacity++;
}
