#pragma once
class CV_LEFT
{
private:
	Int2		location;
	int	const	MaxCapacity = 3;
	int			itemCapacity = 0;

	ObImage*	item;
	bool        hasItem;
public:
	CV_LEFT(Int2 location, ObTileMap* M);
	~CV_LEFT();
	void Update(ObTileMap* M);
	void Render();

public:
	bool operator==(const CV_LEFT& other) const
	{
		return (this->location.x == other.location.x and this->location.y == other.location.y);
	};

	void GetItem();
	int GetitemCapacity() { return itemCapacity; };
};

