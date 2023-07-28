#pragma once

enum class CONVEYERDIR
{
	conveyerUP,
	conveyerDOWN,
	conveyerLEFT,
	conveyerRIGHT,
};

class Conveyer
{
private:





public:
	Conveyer();
	~Conveyer();
	void Update();
	void addItem();
	void moveItem();



};

