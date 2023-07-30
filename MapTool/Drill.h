#pragma once
#define MAXIC 12



class Drill
{
private:
	Int2 location;
	int scaneLocation;
	int itemCapacity;



public:
	Drill(Int2 Location) : location(Location) {};
	~Drill();
	void  Update();

public:
	void Mining();
	void Scane();
};

