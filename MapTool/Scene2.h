#pragma once
#define MAXLAYER 3
#define TILESIZE 20
#define TILESCALE 32
class Scene2 : public Scene
{
private:

	ObTileMap* map[MAXLAYER];
	//ObIso*	map;
	Int2		tileSize;
	ObRect* LineX, * LineY;
	int			layer;
	bool		lookall = true;

	int			brushImgIdx;
	Int2		brushFrame;
	int			brushState;
	Color		brushColor;

	Int2		MAXframe = Int2{ 1,1 };

	class Player* player;



public:
	Scene2();
	~Scene2();
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};