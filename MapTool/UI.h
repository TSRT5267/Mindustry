#pragma once
#define MAXUIOUTLINE 5
#define MAXCATEGORY 4

#define MAXTURRET 1
#define MAXPRODUCTION 2
#define MAXDISTRIBUTION 6
#define MAXDEFENSE 1

enum class CATEGORY
{
	NONE = -1,
	TURRET,
	PRODUCTION,
	DISTRIBUTION,
	DEFENSE,
};

class UI : public GameObject
{
private:
	Vector2			UImousePos;
	Camera*			UIcamera;

// �Ŵ�
	bool			menu_Activatetion;
	ObRect*			menuBackground;
	ObImage*		manutxt;
	ObRect*			underline;
	ObRect*			backButtonCol;
	ObImage*		backButton;
	ObImage*		backButtonOver;
	ObImage*		backButtonIM;
	ObImage*		backButtontxt;
	ObRect*			exitButtonCol;
	ObImage*		exitButton;
	ObImage*		exitButtonOver;
	ObImage*		exitButtonIM;
	ObImage*		exitButtontxt;

	bool			doSave;

//���๰����

	ObRect*			UIbackground;
	ObRect*			UIoutline[MAXUIOUTLINE];
	//ī�װ�
	ObRect*			categoryCol[MAXCATEGORY];
	ObRect*			categoryBorder[MAXCATEGORY];
	ObImage*		categoryIm[MAXCATEGORY];
	int				selectCategory =(int)CATEGORY::NONE;
	//�ͷ�
	ObRect*			turretCol[MAXTURRET];
	ObRect*			turretBorder[MAXTURRET];
	ObImage*		turretIM[MAXTURRET];
	int				selectTurret = (int)CATEGORY::NONE;
	//����
	ObRect*			productionCol[MAXPRODUCTION];
	ObRect*			productionBorder[MAXPRODUCTION];
	ObImage*		productionIM[MAXPRODUCTION];
	int				selectProduction = (int)CATEGORY::NONE;
	//�й�
	ObRect*			distributionCol[MAXDISTRIBUTION];
	ObRect*			distributionBorder[MAXDISTRIBUTION];
	ObImage*		distributionIM[MAXDISTRIBUTION];
	int				selectDistribution = (int)CATEGORY::NONE;
	//���
	ObRect*			defenseCol[MAXDEFENSE];
	ObRect*			defenseBorder[MAXDEFENSE];
	ObImage*		defenseIM[MAXDEFENSE];
	int				selectDefense = (int)CATEGORY::NONE;

//�κ��丮
	ObRect*			invenbackground;
	ObImage*		copperIcon;
	int				copperCapacity = 0;
	ObImage*		numberFont;

//�Ͻ�����
	ObRect*		pausebackground;
public:
	UI();
	~UI();
	virtual void Init() ;
	virtual void Update() ;
	virtual void LateUpdate() ;
	virtual void Render() ;
	
public:
	void Select(int C, ObRect* Col[], ObRect* Border[],int& select);
	bool Save() { return doSave; };
	bool UIIntersect();
	
	bool GetMN_Activate() { return menu_Activatetion; };
	int GetSelectedCategory() { return selectCategory; };
	int GetSelectedTurret() { return selectTurret; };
	int GetSelectedProduction() { return selectProduction; };
	int GetSelectedDistribution() { return selectDistribution; };
	int GetSelectedDefense() { return selectDefense; };
	

};

