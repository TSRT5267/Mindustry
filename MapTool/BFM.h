#pragma once



class BFM
{
private:

	


	
	vector<class CV_UP*>	CVUpLocation;
	vector<class CV_DOWN*>	CVDownLocation;
	vector<class CV_LEFT*>	CVLeftLocation;
	vector<class CV_RIGHT*> CVRightLocation;
	vector<class Junction*> junctionLocation;
	vector<class Router*>	routerLocation;
	vector<class Turret*>	turretLocation;
	vector<class Drill*>	drillLocation;
	vector<class Core*>		coreLocation;

	


public:
	void Update(ObTileMap *M, UI *ui);
	void Render();
	void SaveLocation(int imidx,int state , Int2 inx, ObTileMap* M);
	void RemoveLocation(int imidx, int state, Int2 inx, ObTileMap* M);
	
	const vector<class CV_UP*>&		GetCVUpLocation()		const { return CVUpLocation; }
	const vector<class CV_DOWN*>&	GetCVDownLocation()		const { return CVDownLocation; }
	const vector<class CV_LEFT*>&	GetCVLeftLocation()		const { return CVLeftLocation; }
	const vector<class CV_RIGHT*>&	GetCVRightLocation()	const { return CVRightLocation; }
	const vector<class Junction*>&	GetJunctionLocation()	const { return junctionLocation; }
	const vector<class Router*>&	GetRouterLocation()		const { return routerLocation; }
	const vector<class Turret*>&	GetTurretLocation()		const { return turretLocation; }
	const vector<class Drill*>&		GetDrillLocation()		const { return drillLocation; }
	const vector<class Core*>&		GetCoreLocation()		const { return coreLocation; }





};



