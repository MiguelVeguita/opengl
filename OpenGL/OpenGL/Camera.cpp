#include "Camera.h"
#include "IncludeGL.h"
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Camera::Camera() : position(0.0f, 0.0f, 5.0f), yaw(0.0f), pitch(0.0f)  // Inicializa yaw y pitch
{
}


void Camera::SetPosition(Vector3 _position)
{
    position = _position;
}

Vector3 Camera::GetPosition()
{
    return position;
}

void Camera::SetDirection(Vector3 _direction)
{
    direction = _direction;
}

Vector3 Camera::GetDirection()
{
    return direction;
}

void Camera::Init()
{
    // Inicializa cualquier cosa necesaria para la c�mara aqu�
}

void Camera::Update()
{
    UpdateDirection(); // Actualiza la direcci�n basada en yaw y pitch

    gluLookAt(position.x,
        position.y,
        position.z,
        direction.x,
        direction.y,
        direction.z,
        0, 1, 0); // Vector "arriba" fijo en Y positivo
}

void Camera::UpdateDirection()
{
    // Calcula la direcci�n bas�ndose en yaw y pitch
    direction.x = cosf(yaw * M_PI / 180.0f) * cosf(pitch * M_PI / 180.0f);
    direction.y = sinf(pitch * M_PI / 180.0f);
    direction.z = sinf(yaw * M_PI / 180.0f) * cosf(pitch * M_PI / 180.0f);
    direction.normalize(); // Aseg�rate de normalizar la direcci�n
}

void Camera::LookAt(Vector3)
{
    // Implementa esta funci�n si es necesario
}

void Camera::KeyboardFunc(unsigned char key, int X, int Y)
{
    float cameraSpeed = 0.1f; // Ajusta la velocidad seg�n lo necesites

    switch (key) {
    case 'w': // Adelante
        position += direction * cameraSpeed;
        break;
    case 's': // Atr�s
        position -= direction * cameraSpeed;
        break;
    case 'a': // Izquierda
        position -= direction.cross(Vector3(0, 1, 0)).normalize() * cameraSpeed;
        break;
    case 'd': // Derecha
        position += direction.cross(Vector3(0, 1, 0)).normalize() * cameraSpeed;
        break;
    case 27: // Esc para salir
        exit(0);
    }
}

void Camera::MouseMovement(int x, int y)
{
    static int lastX = 400; // Cambia estos valores seg�n la resoluci�n de tu ventana
    static int lastY = 300;
    static bool firstMouse = true;

    if (firstMouse) {
        lastX = x;
        lastY = y;
        firstMouse = false;
    }

    int xOffset = x - lastX;
    int yOffset = lastY - y; // Invertir el movimiento vertical
    lastX = x;
    lastY = y;

    float sensitivity = 0.1f; // Ajusta la sensibilidad seg�n sea necesario
    xOffset *= sensitivity;
    yOffset *= sensitivity;

    yaw += xOffset;
    pitch += yOffset;

    // Limitar el �ngulo de pitch
    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    UpdateDirection(); // Actualiza la direcci�n de la c�mara
}
