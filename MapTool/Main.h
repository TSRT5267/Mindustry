#pragma once
#define MAXLAYER 3
#define TILESIZE 10
#define TILESCALE 32
class Main : public Scene
{
private:

	ObTileMap*	map[MAXLAYER];
	//ObIso*	map;
	Int2		tileSize;
	ObRect*		LineX, *LineY;
	int			layer;
	bool		lookall = true;

	int			brushImgIdx;
	Int2		brushFrame;
	int			brushState;
	Color		brushColor;

	Int2		MAXframe = Int2{1,1};





public:
	Main();
	~Main();
	virtual void Init() override;
	virtual void Release() override; //해제
	virtual void Update() override;
	virtual void LateUpdate() override;//갱신
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
