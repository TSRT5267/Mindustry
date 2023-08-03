#pragma once
class CV_LEFT
{
private:
	Int2	location;
	int		itemCapacity;


public:
	CV_LEFT(Int2 location) : location(location) {}
	~CV_LEFT();
	void Update(ObTileMap* M);


public:

	bool operator==(const CV_LEFT& other) const
	{
		return (this->location.x == other.location.x and this->location.y == other.location.y);
	};
};

