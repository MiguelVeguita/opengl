#pragma once
#ifndef SPOT_LIGHT_H
#define SPOT_LIGHT_H

#include "Light.h"

class SpotLight : public Light {
public:
    SpotLight();  // Constructor
    void SetSpotDirection(float x, float y, float z);
    virtual void EnableLight() override;
    virtual void DisableLight() override;

private:
    float spotDirection[3];
};

#endif
