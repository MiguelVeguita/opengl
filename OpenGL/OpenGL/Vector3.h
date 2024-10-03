#include <iostream>
#include <cmath>

class Vector3 {
public:
    float x, y, z; // Componentes del vector

    // Constructor por defecto
    Vector3() : x(0), y(0), z(0) {}

    // Constructor con parámetros
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    // Sobrecarga del operador +
    Vector3 operator+(const Vector3& v) const {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }

    // Sobrecarga del operador -
    Vector3 operator-(const Vector3& v) const {
        return Vector3(x - v.x, y - v.y, z - v.z);
    }

    // Sobrecarga del operador * para multiplicación por un escalar
    Vector3 operator*(float scalar) const {
        return Vector3(x * scalar, y * scalar, z * scalar);
    }

    // Sobrecarga del operador / para dividir por un escalar
    Vector3 operator/(float scalar) const {
        return Vector3(x / scalar, y / scalar, z / scalar);
    }

    // Función para calcular la magnitud del vector
    float magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    // Función para normalizar el vector
    Vector3 normalize() const {
        float mag = magnitude();
        if (mag > 0) {
            return Vector3(x / mag, y / mag, z / mag);
        }
        return Vector3(0, 0, 0); // Devuelve un vector nulo si la magnitud es 0
    }

    // Imprimir el vector
    void print() const {
        std::cout << "Vector3(" << x << ", " << y << ", " << z << ")" << std::endl;
    }

    // Función para calcular el producto cruzado entre dos vectores
    Vector3 cross(const Vector3& v) const {
        return Vector3(
            y * v.z - z * v.y,
            z * v.x - x * v.z,
            x * v.y - y * v.x
        );
    }

    // Sobrecarga del operador +=
    Vector3& operator+=(const Vector3& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this; // Devuelve la referencia al objeto actual
    }

    // Sobrecarga del operador -=
    Vector3& operator-=(const Vector3& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this; // Devuelve la referencia al objeto actual
    }
};
