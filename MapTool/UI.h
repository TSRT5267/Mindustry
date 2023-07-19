#pragma once
class UI : public GameObject
{
private:
	ObRect*			UIbackground;
	ObRect*			UIoutline[5];

public:
	UI();
	~UI();
	virtual void Init() ;
	virtual void Update() ;
	virtual void LateUpdate() ;
	virtual void Render() ;
	
};

