#pragma once
#define MAXLAYER 3
#define TILESIZE 50
#define TILESCALE 32
class Scene2 : public Scene
{
private:

	ObTileMap* map[MAXLAYER];
	//ObIso*	map;
	Int2		tileSize;
	
	int			layer;
	bool		lookall = true;

	int			brushImgIdx;
	Int2		brushFrame;
	int			brushState;
	Color		brushColor;

	Int2		MAXframe = Int2{ 1,1 };

private:

	class Player* player;
	bool isTimeStop;
	class UI* ui;

public:
	Scene2();
	~Scene2();
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;

public:
	void SAVE() { map[0]->Save(); map[1]->Save();map[2]->Save();};
};
