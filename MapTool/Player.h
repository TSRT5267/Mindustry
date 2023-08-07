#pragma once
#define MOVESPEED 22.5
#define MAXBULLET 30


class Player : public ObCircle
{
private: //��ü

	ObImage*	alpha;
	ObImage*	shadow;

	Vector2		movedir;
	bool		isMove;
	Vector2		attdir;
	float		firedelay;
	int			gunSwiching;


private: //����
	class Bullet* bullet[MAXBULLET];


public:

	Player();
	virtual ~Player();
	void Init();
	void Update(Color C) ;
	void Render() override;

	void Move();
	void Look();
	void Attack();

};

