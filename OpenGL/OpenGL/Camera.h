#pragma once
#include "Vector3.h"

class Camera
{
private:
    Vector3 position;   // Posición de la cámara
    Vector3 direction;  // Dirección a la que mira la cámara
    float yaw;         // Rotación alrededor del eje Y
    float pitch;       // Rotación alrededor del eje X

public:
    Camera();
    void SetPosition(Vector3);
    Vector3 GetPosition();
    void SetDirection(Vector3);
    Vector3 GetDirection();
    void Init();
    void Update();
    void LookAt(Vector3);
    void SetYaw(float newYaw) { yaw = newYaw; }
    void SetPitch(float newPitch) { pitch = newPitch; }
    void KeyboardFunc(unsigned char key, int X, int Y);
    void MouseMovement(int x, int y);  // Para manejar el movimiento del mouse
    void UpdateDirection();              // Actualiza la dirección basándose en yaw y pitch
    float GetYaw() const { return yaw; }  // Devuelve el valor de yaw
    float GetPitch() const { return pitch; } // Devuelve el valor de pitch

};
