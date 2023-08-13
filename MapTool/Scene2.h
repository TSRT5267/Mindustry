#pragma once
#define MAXLAYER 3
#define TILESIZE 50
#define TILESCALE 32
#define X1MAXFRAME_X 4
#define X1MAXFRAME_Y 2
#define X2MAXFRAME_X 4
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

enum class blockState
{
	CONVEYORUP,
	CONVEYORDOWN,
	CONVEYORLEFT,
	CONVEYORRIGHT,
	JUNCTION,
	ROUTER,
	TURRET,
	WALL,
	DRILL = 10,
	CORE,
};

class Scene2 : public Scene
{
private:

	ObTileMap* Tmap[MAXLAYER];
	Int2		tileSize;
	
	int			layer;
	bool		lookall = true;

	int			brushImgIdx;
	Int2		brushFrame;
	int			brushState;
	Color		brushColor;

	Int2		MAXframe = Int2{ 1,1 };

	//map<Int2, int> blockLocation;
	class BFM*	bfm;

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
	void SAVE() { Tmap[0]->Save(); Tmap[1]->Save();Tmap[2]->Save();};
	void SetTile(int Idx, int MAX_X, int MAX_Y);
	int GetTileState(Int2 IDX) { return Tmap[(int)LAYER::BLOCK]->GetTileState(IDX); };
	
	void generateRandomMap(int width, int height, int seed);

};
