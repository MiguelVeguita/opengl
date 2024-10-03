#pragma once
#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTIONAL_LIGHT_H

#include "Light.h"

class DirectionalLight : public Light {
public:
    DirectionalLight();  // Constructor
    void SetDirection(float x, float y, float z); // Agregar este m�todo
    virtual void EnableLight() override;
    virtual void DisableLight() override;

private:
    float direction[3]; // Para almacenar la direcci�n de la luz
};

#endif 
