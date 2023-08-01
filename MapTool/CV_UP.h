#pragma once
class CV_UP
{
private:
	Int2	location;
	int		itemCapacity;


public:
	CV_UP(Int2 location) : location(location) {}
	~CV_UP();
	void Update(ObTileMap* M);
	
	
public:

	bool operator==(const CV_UP& other) const
	{
		return (this->location.x == other.location.x and this->location.y == other.location.y);
	};
};

