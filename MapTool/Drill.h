#pragma once

class Drill
{
private:
	Int2		location;	
	int const	MaxCapacity=12;
	int			itemCapacity;

	bool	findCV;
	Int2	directions[4] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
	Int2	scaneLocation;
	int		scaneState;

	float	mineDelay;
	float	sendDelay;
public:
	Drill(Int2 location) : location(location) {}
	~Drill();
	void  Update(ObTileMap* M, BFM* bfm);
	

public:

	bool operator==(const Drill& other) const
	{
		return (this->location.x == other.location.x and this->location.y == other.location.y);
	};


	void  Mining();
	void  SendItem(BFM* bfm);
	void  Scane(ObTileMap* M);
};

