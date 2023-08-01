#pragma once



class BFM
{
private:

	


	
	vector<class CV_UP*> CVUpLocation;
	vector<class CV_DOWN*> CVDownLocation;
	vector<Int2> CVLeftLocation;
	vector<Int2> CVRightLocation;
	vector<Int2> junctionLocation;
	vector<Int2> routerLocation;
	vector<Int2> turretLocation;
	vector<class Drill*> drillLocation;
	vector<Int2> coreLocation;




public:
	void Update(ObTileMap *M);
	void SaveLocation(int imidx,int state , Int2 inx);
	void RemoveLocation(int imidx, int state, Int2 inx);
	
	





};



