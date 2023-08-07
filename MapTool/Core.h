#pragma once
class Core
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
	Core(Int2 location, ObTileMap* M);
	~Core();
	void Update(ObTileMap* M, BFM* bfm);
	


public:
	bool operator==(const Core& other) const
	{
		return (this->location.x == other.location.x && this->location.y == other.location.y);
	}
	
	void GetItem();

	int GetitemCapacity() { return itemCapacity; };
};



