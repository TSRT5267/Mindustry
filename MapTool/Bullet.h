#pragma once
#define POWER 100

class Bullet : public ObCircle
{
private:
	ObImage*	bullet;

	bool		isfire;
	float		lifeTime;
	Vector2		dir;

public:

	Bullet();
	virtual ~Bullet();
	void Init();
	void Update() override;
	void Render() override;

	void Fire(GameObject* shooter);
	bool Getisfire() { return isfire; };
	//void Release() { isfire = false; }
};

