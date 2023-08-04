#pragma once
class Turret
{
private:
	Int2	location;
	int		itemCapacity;

	bool	findCV;
	Int2	scaneLocation;


public:
	Turret(Int2 location) : location(location) {}
	~Turret();
	void  Update(ObTileMap* M);


public:

	bool operator==(const Turret& other) const
	{
		return (this->location.x == other.location.x and this->location.y == other.location.y);
	};

};


