#pragma once
class Scene1 : public Scene
{
private:
	ObImage*	logo;
	ObImage*	background;
	ObImage*	planet;

	ObRect*		bar;
	ObImage*	play;
	ObImage*	exit;
	ObRect*		playbox;
	ObRect*		exitbox;
	ObImage*	playtxt;
	ObImage*	exittxt;

public:
	Scene1();
	~Scene1();
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;



};

