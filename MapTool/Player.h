#pragma once
#define MOVESPEED 22.5
#define MAXBULLET 30


class Player : public ObCircle
{
private: //��ü

	ObImage*	alpha;
	
	Vector2		movedir;
	bool		isMove;
	Vector2		attdir;
	
private: //����
	class Bullet bullet[MAXBULLET];


public:

	Player();
	virtual ~Player();
	void Init();
	void Update() override;
	void Render() override;

	void Move();
	void Look();


};

