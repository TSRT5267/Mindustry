#include "stdafx.h"
#include "BF_framework.h"

CV_DOWN::CV_DOWN(Int2 location, ObTileMap* M)
{
	this->location = location;
	item = new ObImage(L"item_copper.png");
	item->scale.x = item->imageSize.x;
	item->scale.y = item->imageSize.y;
	item->scale *= 0.8f;
	item->SetWorldPos(M->GetTilePosition(this->location) * 32 + Vector2(-784, -784));
}

CV_DOWN::~CV_DOWN()
{
	delete item;
}

void CV_DOWN::Update(ObTileMap* M)
{
	if (itemCapacity > 0) hasItem = true;
	else hasItem = false;

	item->Update();
}

void CV_DOWN::Render()
{
	if (hasItem) item->Render();
}

void CV_DOWN::GetItem()
{
	if (itemCapacity < MaxCapacity) itemCapacity++;
}
