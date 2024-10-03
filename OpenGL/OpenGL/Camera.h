#pragma once
#include "Vector3.h"

class Camera
{
private:
    Vector3 position;   // Posici�n de la c�mara
    Vector3 direction;  // Direcci�n a la que mira la c�mara
    float yaw;         // Rotaci�n alrededor del eje Y
    float pitch;       // Rotaci�n alrededor del eje X

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
    void UpdateDirection();              // Actualiza la direcci�n bas�ndose en yaw y pitch
    float GetYaw() const { return yaw; }  // Devuelve el valor de yaw
    float GetPitch() const { return pitch; } // Devuelve el valor de pitch

};
