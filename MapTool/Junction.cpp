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

	Scan(M); //�ֺ� �����̾ ��ĵ

	SendItem(bfm, M); //���ǿ� �����ϸ� ������ ����
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




