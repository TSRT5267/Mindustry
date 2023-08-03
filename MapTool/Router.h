#pragma once
class Router
{
private:
	Int2	location;
	int		itemCapacity;


public:
	Router(Int2 location) : location(location) {}
	~Router();
	void Update(ObTileMap* M);


public:

	bool operator==(const Router& other) const
	{
		return (this->location.x == other.location.x and this->location.y == other.location.y);
	};
};

