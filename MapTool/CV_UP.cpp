#include "stdafx.h"
#include "Scene2.h"
#include "BFM.h"
#include "CV_UP.h"



CV_UP::CV_UP(Int2 location, ObTileMap* M)
{
	this->location = location;
	item = new ObImage(L"item_copper.png");
	item->scale.x = item->imageSize.x;
	item->scale.y = item->imageSize.y;
	item->scale *= 0.8f;
	item->SetWorldPos(M->GetTilePosition(location));
}

CV_UP::~CV_UP()
{
}

void CV_UP::Update(ObTileMap* M)
{
	if (itemCapacity > 0) item->isVisible = true;
	else item->isVisible = false;
}

void CV_UP::Render()
{
	item->Render();
}

void CV_UP::GetItem()
{
	if (itemCapacity < MaxCapacity) itemCapacity++;
}
