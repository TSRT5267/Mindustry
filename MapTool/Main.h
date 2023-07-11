#pragma once
#define MAXLAYER 3
#define TILESIZE 10

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


public:
	Main();
	~Main();
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
