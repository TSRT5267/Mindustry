#pragma once
class Core
{
private:
	Int2	location;
	int		itemCapacity;

	bool	findCV;
	Int2	scaneLocation;


public:
	Core(Int2 location) : location(location) {}
	~Core();
	void  Update(ObTileMap* M);


public:

	bool operator==(const Core& other) const
	{
		return (this->location.x == other.location.x and this->location.y == other.location.y);
	};


	void  Mining();
	void  SendItem(ObTileMap* M);
	void  Scane(ObTileMap* M);
};

