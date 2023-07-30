#pragma once



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
	void Update(map<Int2, int> location);
	void save(map<Int2, int> location);
	void build(map<Int2, int> location);
	





};



