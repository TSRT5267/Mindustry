#include "stdafx.h"
#include "Drill.h"
#include "BFM.h"


void BFM::Update(unordered_map<Int2, int> location)
{
	




}

void BFM::save(unordered_map<Int2, int> location)
{
	/*prevMap.clear();
	prevMap.insert(location.begin(), location.end());*/
	
}

void BFM::build(unordered_map<Int2, int> location)
{
	//for (const auto& entry : location)
	//{
	//	Int2 key = entry.first;
	//	int value = entry.second;

	//	// ��ȭ�� �����Ͱ� ������ ó��
	//	if (prevMap.find(key) == prevMap.end() || prevMap[key] != value)
	//	{
	//		//�����
	//		if (value == NULL)
	//		{
	//			switch (prevMap[key])
	//			{
	//			case (int)blockState::CONVEYORUP:
	//				CVUpLocation.erase(std::remove(CVUpLocation.begin(), CVUpLocation.end(), key), CVUpLocation.end());
	//				break;
	//			default:
	//				break;
	//			}
	//		}
	//		//�߰��ϱ�
	//		else
	//		{
	//			switch (value)
	//			{
	//			case (int)blockState::CONVEYORUP:
	//				CVUpLocation.push_back(key);
	//				break;
	//			default:
	//				break;
	//			}
	//		}
	//	}
	//}

	//�׽�Ʈ
	ImGui::Text("FPS : %d", (int)CVUpLocation.size());
}

