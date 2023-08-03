#pragma once
class CV_RIGHT
{
private:
	Int2	location;
	int		itemCapacity;


public:
	CV_RIGHT(Int2 location) : location(location) {}
	~CV_RIGHT();
	void Update(ObTileMap* M);


public:

	bool operator==(const CV_RIGHT& other) const
	{
		return (this->location.x == other.location.x and this->location.y == other.location.y);
	};
};

