#pragma once
#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "Light.h"

class PointLight : public Light {
public:
    PointLight();  // Constructor
    virtual void EnableLight() override;
    virtual void DisableLight() override;
};

#endif
