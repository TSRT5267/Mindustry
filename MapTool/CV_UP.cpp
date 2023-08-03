#include "stdafx.h"
#include "Scene2.h"
#include "BFM.h"
#include "CV_UP.h"



CV_UP::~CV_UP()
{
}

void CV_UP::Update(ObTileMap* M)
{
}

void CV_UP::GetItem()
{
	if (itemCapacity < MaxCapacity) itemCapacity++;
}
