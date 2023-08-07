#pragma once
class Junction //±³Â÷±â
{
private:
	Int2		location;
	int	const	MaxCapacity = 3;
	int			itemCapacity = 0;

	bool		findCV = false;
	Int2		directions[4] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
	int			CVState[4] = { 1,0,3,2};
	Int2		scanLocation[4];
	int			scanState[4] ;

	bool        hasItem;

	float		sendDelay = 0;


public:
	Junction(Int2 location, ObTileMap* M);
	~Junction();
	void Update(ObTileMap* M, BFM* bfm);


public:
	bool operator==(const Junction& other) const
	{
		return (this->location.x == other.location.x and this->location.y == other.location.y);
	};

	void Scan(ObTileMap* M);
	void SendItem(BFM* bfm, ObTileMap* M);
	void GetItem(BFM* bfm, ObTileMap* M, int SendState);

	int GetitemCapacity() { return itemCapacity; };
};

