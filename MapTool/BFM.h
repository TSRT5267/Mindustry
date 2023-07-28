#pragma once

enum class blockState
{
	CONVEYORUP,
	CONVEYORDOWN,
	CONVEYORLEFT,
	CONVEYORRIGHT,
	JUNCTION,
	ROUTER,
	TURRET,
	WALL,
	DRILL = 10,
	CORE,
};

class BFM
{
private:

	map<Int2,int> prevMap;


	vector<Int2> turretLocation;
	vector<Int2> CVUpLocation;
	vector<Int2> CVDownLocation;
	vector<Int2> CVLeftLocation;
	vector<Int2> CVRightLocation;
	vector<Int2> junctionLocation;
	vector<Int2> routerLocation;
	vector<Int2> drillLocation;
	vector<Int2> coreLocation;




public:
	void Update(unordered_map<Int2, int> location);
	void save(unordered_map<Int2, int> location);
	void build(unordered_map<Int2, int> location);
	





};



