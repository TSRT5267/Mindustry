#pragma once
class Camera : public Singleton<Camera>
{
private:
    Viewport            viewport;  
    Matrix              V, P, VP;     

public:
    //카메라위치
    Vector2             position;
    float               scale;
public:
    Camera();
   
    void          Set();
    void          Set(float S);
    void          ResizeScreen();
    const Matrix& GetP() { return P; };
    const Matrix& GetVP() { return VP; };
};