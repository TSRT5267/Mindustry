#include "stdafx.h"
#include "Item_copper.h"

Item_copper::Item_copper()
{
	IM = new ObImage(L"item_copper.png");
	IM->scale.x = IM->imageSize.x;
	IM->scale.y = IM->imageSize.y;
	IM->scale *= 0.8f;
	IM->SetParentRT(*this);
	this->scale = IM->scale;

	
}

Item_copper::~Item_copper()
{
	delete IM;
	delete this;
}

void Item_copper::Init()
{

}

void Item_copper::Update()
{
}

void Item_copper::LateUpdate()
{
}

void Item_copper::Render()
{
}
