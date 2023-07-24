#pragma once
#define MAXLAYER 3
#define TILESIZE 50
#define TILESCALE 32
#define X1MAXFRAME_X 2
#define X1MAXFRAME_Y 3
#define X2MAXFRAME_X 2
#define X2MAXFRAME_Y 2


enum class LAYER
{
	GROUND,
	ENVIRONMENT,
	BLOCK,

};

enum class ImgIdx
{
	GROUND,
	ENVIRONMENT,
	BLOCK1x1,
	BLOCK2x2,

};

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
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;

public:
	void SAVE() { map[0]->Save(); map[1]->Save();map[2]->Save();};
	void SetTile(int Idx, int MAX_X, int MAX_Y);
};
