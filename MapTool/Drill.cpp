#include "stdafx.h"
#include "BF_framework.h"



Drill::~Drill()
{
}



void  Drill::Update(ObTileMap* M, BFM* bfm)
{
	Mining(); //capacity�� �� �������� ä��
    
	Scane(M); //�ֺ� �����̾ ��ĵ
	
	if (itemCapacity > 0 and findCV == true and TIMER->GetTick(sendDelay, 2.5f)) SendItem(bfm,M); //���ǿ� �����ϸ� ������ ����

}

void  Drill::Mining()
{
	if (itemCapacity < MaxCapacity and TIMER->GetTick(mineDelay, 2.5f)) itemCapacity++;
}

void  Drill::Scane(ObTileMap* M)
{
    for (int i = 0; i < 4; ++i)
    {
        Int2 scanLocation = location + directions[i];
        int scanState = M->GetTileState(scanLocation);

        if (scanState >= (int)blockState::CONVEYORUP && scanState <= (int)blockState::CONVEYORRIGHT)
        {
            scaneLocation = scanLocation;
            scaneState = scanState;
            findCV = true;
            return;
        }
    }

    // ��� ���⿡���� �����̾ ã�� ���ϸ� findCV�� false�� �����մϴ�.
    findCV = false;
}

void  Drill::SendItem(BFM* bfm, ObTileMap* M)
{
    switch (scaneState)
    {
    case (int)blockState::CONVEYORUP:
    {
        const vector<CV_UP*>& CVUpLocation = bfm->GetCVUpLocation();
        const auto it = find_if(CVUpLocation.begin(), CVUpLocation.end(),
            [this,&M](const CV_UP* cv) { return *cv == CV_UP(location, M); });

        if (it != CVUpLocation.end() && (*it)->GetitemCapacity() < 3)
        {
            itemCapacity--;
            (*it)->GetItem();
        }
    }
    default:
        break;
    }
}

