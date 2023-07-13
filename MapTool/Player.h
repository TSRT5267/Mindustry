#pragma once
#define MOVESPEED 22.5
#define TILESCALE 32


class Player : public ObCircle
{
private:

	ObImage*	alpha;
	
	Vector2		movedir;
	bool		isMove;
	Vector2		attdir;
	

public:

	Player();
	virtual ~Player();
	void Init();
	void Update() override;
	void Render() override;

	void Move();
	void Look();


};

