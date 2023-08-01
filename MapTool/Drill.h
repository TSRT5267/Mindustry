#pragma once
#define MAXIC 12

class Drill
{
private:
	Int2	location;	
	int		itemCapacity;

	bool	findCV;
	Int2	scaneLocation;


public:
	Drill(Int2 location) : location(location) {}
	~Drill();
	void  Update(ObTileMap* M);
	

public:

	bool operator==(const Drill& other) const
	{
		return (this->location.x == other.location.x and this->location.y == other.location.y);
	};


	void  Mining();
	void  SendItem();
	void  Scane(ObTileMap* M);
};

