#pragma once
#include "Example.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "DirectionalLight.h"

class Example4 : public Example {
public:
    Example4();
    virtual ~Example4(); // Declarar el destructor
    virtual void init() override;
    virtual void Render() override;
    virtual void KeyboardFunc(unsigned char key, int X, int Y) override;
    virtual void Idle() override;

private:
    void ConfigurarMaterial();
    void DrawGrid();

    PointLight* pointLight;
    DirectionalLight* directionalLight;
    SpotLight* spotLight;
    Light* currentLight;
};