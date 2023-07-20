#pragma once
#define MAXUIOUTLINE 5
#define MAXCATEGORY 4


class UI : public GameObject
{
private:
	Camera*			UIcamera;

	ObRect*			UIbackground;
	ObRect*			UIoutline[MAXUIOUTLINE];

	ObRect*			categoryCol[MAXCATEGORY];
	ObRect*			categoryOutline[MAXCATEGORY];
	ObImage*		categoryIm[MAXCATEGORY];
	int				selectCategory;

public:
	UI();
	~UI();
	virtual void Init() ;
	virtual void Update() ;
	virtual void LateUpdate() ;
	virtual void Render() ;
	
};

