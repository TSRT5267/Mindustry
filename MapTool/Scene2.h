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

	vector<Int2> turretLocation;
	vector<Int2> CVUpLocation;
	vector<Int2> CVDownLocation;
	vector<Int2> CVLeftLocation;
	vector<Int2> CVRightLocation;
	vector<Int2> junctionLocation;
	vector<Int2> routerLocation;
	vector<Int2> drillLocation;
	vector<Int2> coreLocation;

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
	void SetTile(int Idx, int MAX_X, int MAX_Y);
	void RememberLocation(int state, vector<Int2> Location, Int2 Idx);
	void ForgetLocation(vector<Int2> Location, Int2 Idx);
	

};
