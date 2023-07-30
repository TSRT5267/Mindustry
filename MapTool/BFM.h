#pragma once



class BFM
{
private:

	


	
	vector<Int2> CVUpLocation;
	vector<Int2> CVDownLocation;
	vector<Int2> CVLeftLocation;
	vector<Int2> CVRightLocation;
	vector<Int2> junctionLocation;
	vector<Int2> routerLocation;
	vector<Int2> turretLocation;
	vector<Drill> drillLocation;
	vector<Int2> coreLocation;




public:
	void Update();
	void SaveLocation(int imidx,int state , Int2 inx);
	void RemoveLocation(int imidx, int state, Int2 inx);
	
	





};



