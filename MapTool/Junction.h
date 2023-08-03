#pragma once
class Junction
{
private:
	Int2	location;
	int		itemCapacity;


public:
	Junction(Int2 location) : location(location) {}
	~Junction();
	void Update(ObTileMap* M);


public:

	bool operator==(const Junction& other) const
	{
		return (this->location.x == other.location.x and this->location.y == other.location.y);
	};
};

