// Example3.h
#pragma once
#include "Example.h"

#include "FiguraGeometrica.h"
#include "Camera.h"

class Example3 : public Example
{
    Camera* camera;
  
public:
    Example3();

    virtual void init() override;
    virtual void Render() override;
    
    virtual void KeyboardFunc(unsigned char key, int X, int Y) override;
    virtual void Idle() override;
    void DrawGrid();
    void DrawAxes();
    void MouseMotionFunc(int x, int y);
    void RenderFigures();
   

private:
   
    FiguraGeometrica figura;

   
};
