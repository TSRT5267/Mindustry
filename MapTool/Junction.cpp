#include "stdafx.h"
#include "BF_framework.h"

Junction::Junction(Int2 location, ObTileMap* M)
{
	this->location = location;
}

Junction::~Junction()
{
}

void Junction::Update(ObTileMap* M, BFM* bfm)
{
	if (itemCapacity > 0) hasItem = true;
	else hasItem = false;

	Scan(M); //주변 컨배이어를 스캔

	SendItem(bfm, M); //조건에 부합하면 아이템 전송
}

void Junction::Render()
{
}

void Junction::Scan(ObTileMap* M)
{
}

void Junction::SendItem(BFM* bfm, ObTileMap* M)
{
}




