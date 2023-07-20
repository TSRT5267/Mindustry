#pragma once
#define MAXUIOUTLINE 5
#define MAXCATEGORY 4

#define MAXTURRET 2
#define MAXPRODUCTION 1
#define MAXDISTRIBUTION 3
#define MAXDEFENSE 1

class UI : public GameObject
{
private:
	Camera*			UIcamera;

	ObRect*			UIbackground;
	ObRect*			UIoutline[MAXUIOUTLINE];
	//카테고리
	ObRect*			categoryCol[MAXCATEGORY];
	ObRect*			categoryBorder[MAXCATEGORY];
	ObImage*		categoryIm[MAXCATEGORY];
	int				selectCategory;
	//터렛
	ObRect*			turretCol[MAXTURRET];
	ObRect*			turretBorder[MAXTURRET];
	ObImage*		turretIM[MAXTURRET];
	int				selectTurret;
	//생산
	ObRect*			productionCol[MAXPRODUCTION];
	ObRect*			productionBorder[MAXPRODUCTION];
	ObImage*		productionIM[MAXPRODUCTION];
	int				selectProduction;
	//분배
	ObRect*			distributionCol[MAXDISTRIBUTION];
	ObRect*			distributionBorder[MAXDISTRIBUTION];
	ObImage*		distributionIM[MAXDISTRIBUTION];
	int				selectDistribution;
	//방어
	ObRect*			defenseCol[MAXDEFENSE];
	ObRect*			defenseBorder[MAXDEFENSE];
	ObImage*		defenseIM[MAXDEFENSE];
	int				selectDefense;

public:
	UI();
	~UI();
	virtual void Init() ;
	virtual void Update() ;
	virtual void LateUpdate() ;
	virtual void Render() ;
	
};

