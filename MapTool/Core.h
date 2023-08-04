#pragma once
class Core
{
private:
private:
	Int2	location;
	int		itemCapacity;


public:
	Core(Int2 location) : location(location) {}
	~Core();
	void Update(ObTileMap* M);


public:

	bool operator==(const Core& other) const
	{
		return (this->location.x == other.location.x and this->location.y == other.location.y);
	};
};



