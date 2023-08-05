#pragma once



class BFM
{
private:

	


	
	vector<class CV_UP*> CVUpLocation;
	vector<class CV_DOWN*> CVDownLocation;
	vector<class CV_LEFT*> CVLeftLocation;
	vector<class CV_RIGHT*> CVRightLocation;
	vector<class Junction*> junctionLocation;
	vector<class Router*> routerLocation;
	vector<class Turret*> turretLocation;
	vector<class Drill*> drillLocation;
	vector<class Core*> coreLocation;

	


public:
	void Update(ObTileMap *M);
	void Render();
	void SaveLocation(int imidx,int state , Int2 inx, ObTileMap* M);
	void RemoveLocation(int imidx, int state, Int2 inx, ObTileMap* M);
	
	const vector<class CV_UP*>& GetCVUpLocation() const { return CVUpLocation; }





};



