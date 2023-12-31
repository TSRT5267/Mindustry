#pragma once
class Turret
{
private:
	Int2		location;
	int	const	MaxCapacity = 3;
	int			itemCapacity = 0;

	bool		findCV = false;
	Int2		directions[1] = { {0, 1} };
	Int2		scanLocation;
	int			scanState = -1;

	ObImage* item;
	bool        hasItem;

	float		sendDelay = 0;
public:
	Turret(Int2 location, ObTileMap* M);
	~Turret();
	void Update(ObTileMap* M, BFM* bfm);
	void Render();


public:
	bool operator==(const Turret& other) const
	{
		return (this->location.x == other.location.x && this->location.y == other.location.y);
	}

	void Scan(ObTileMap* M);
	void SendItem(BFM* bfm, ObTileMap* M);
	void GetItem() { if (itemCapacity < MaxCapacity) itemCapacity++; };

	int GetitemCapacity() { return itemCapacity; };
};

