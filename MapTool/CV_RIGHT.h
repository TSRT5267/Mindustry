#pragma once
class CV_RIGHT
{
private:
	Int2		location;
	int	const	MaxCapacity = 3;
	int			itemCapacity = 0;

	bool		findCV = false;
	Int2		directions[1] = { {1, 0} };
	Int2		scanLocation;
	int			scanState = -1;

	ObImage* item;
	bool        hasItem;

	float		sendDelay = 0;
	float		junctionDelay = 0;
public:
	CV_RIGHT(Int2 location, ObTileMap* M);
	~CV_RIGHT();
	void Update(ObTileMap* M, BFM* bfm, UI* ui);
	void Render();


public:
	bool operator==(const CV_RIGHT& other) const
	{
		return (this->location.x == other.location.x && this->location.y == other.location.y);
	}

	void Scan(ObTileMap* M);
	void SendItem(BFM* bfm, ObTileMap* M, UI* ui);
	void GetItem() { if (itemCapacity < MaxCapacity) itemCapacity++; };

	int GetitemCapacity() { return itemCapacity; };
};

