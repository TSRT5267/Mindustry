#pragma once
#define MAXUIOUTLINE 5
#define MAXCATEGORY 4

#define MAXTURRET 1
#define MAXPRODUCTION 1
#define MAXDISTRIBUTION 3
#define MAXDEFENSE 1

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
	int				selectCategory;
	//�ͷ�
	ObRect*			turretCol[MAXTURRET];
	ObRect*			turretBorder[MAXTURRET];
	ObImage*		turretIM[MAXTURRET];
	int				selectTurret;
	//����
	ObRect*			productionCol[MAXPRODUCTION];
	ObRect*			productionBorder[MAXPRODUCTION];
	ObImage*		productionIM[MAXPRODUCTION];
	int				selectProduction;
	//�й�
	ObRect*			distributionCol[MAXDISTRIBUTION];
	ObRect*			distributionBorder[MAXDISTRIBUTION];
	ObImage*		distributionIM[MAXDISTRIBUTION];
	int				selectDistribution;
	//���
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
	
public:
	void Select(int C, ObRect* Col[], ObRect* Border[],int& select);
	bool GetMN_Activate() { return menu_Activatetion; };
	bool Save() { return doSave; };
};

