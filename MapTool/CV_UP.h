#pragma once
class CV_UP
{
private:
	Int2		location;
	int	const	MaxCapacity = 3;
	int			itemCapacity=0;

	ObImage*	item;
	bool        hasItem;
public:
	CV_UP(Int2 location, ObTileMap* M);
	~CV_UP();
	void Update(ObTileMap* M);
	void Render();
	
	
public:
	bool operator==(const CV_UP& other) const
	{
		return (this->location.x == other.location.x && this->location.y == other.location.y);
	}
	
	void SandItem(BFM* bfm, ObTileMap* M);
	void GetItem();	

	int GetitemCapacity() { return itemCapacity; };
};

