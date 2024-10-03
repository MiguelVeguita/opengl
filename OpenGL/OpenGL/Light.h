#ifndef LIGHT_H
#define LIGHT_H

class Light {
public:
    // Constructor de la clase base
    Light();

    // Métodos virtuales para que las clases derivadas los sobreescriban
    virtual void SetPosition(float x, float y, float z);
    virtual void SetAmbient(float r, float g, float b, float a);
    virtual void SetDiffuse(float r, float g, float b, float a);
    virtual void SetSpecular(float r, float g, float b, float a);

    virtual void EnableLight() = 0; // Método puro para habilitar la luz
    virtual void DisableLight() = 0; // Método puro para deshabilitar la luz

protected:
    // Atributos comunes para todas las luces
    float position[4];
    float ambient[4];
    float diffuse[4];
    float specular[4];
public:
    float* getPosition() {
        return position;
    }

};

#endif
