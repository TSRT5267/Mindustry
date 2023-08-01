#pragma once
class CV_DOWN
{
private:
	Int2	location;
	int		itemCapacity;

	
public:
	CV_DOWN(Int2 location) : location(location) {}
	~CV_DOWN();
	void Update(ObTileMap* M);
	

public:

	bool operator==(const CV_DOWN& other) const
	{
		return (this->location.x == other.location.x and this->location.y == other.location.y);
	};
};

