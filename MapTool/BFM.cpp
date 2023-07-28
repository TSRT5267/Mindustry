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

	//	// 변화한 데이터가 있으면 처리
	//	if (prevMap.find(key) == prevMap.end() || prevMap[key] != value)
	//	{
	//		//지우기
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
	//		//추가하기
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

	//테스트
	ImGui::Text("FPS : %d", (int)CVUpLocation.size());
}

