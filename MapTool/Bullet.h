#pragma once
#define POWER 500

class Bullet : public ObCircle
{
private:
	ObImage*	bullet;

	bool		isfire = false;
	float		lifeTime = 0;
	Vector2		dir;

public:

	Bullet();
	virtual ~Bullet();
	void Init();
	void Update() override;
	void Render() override;

	void Fire(GameObject* shooter,int hand);
	bool Getisfire() { return isfire; };
	//void Release() { isfire = false; }
};

