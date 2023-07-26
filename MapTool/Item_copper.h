#pragma once

class Item_copper : public ObRect
{
private:
	ObImage* IM;







public:
	Item_copper();
	~Item_copper();
	virtual void Init() ;
	virtual void Update() ;
	virtual void LateUpdate() ;
	virtual void Render() ;
	
public:






};

