#pragma once

class Main : public Scene
{
private:
	
	HCURSOR mh_scope_cursor, mh_prev_cursor;



public:
	Main();
	~Main();
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;
};
