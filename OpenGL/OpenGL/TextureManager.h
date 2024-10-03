#pragma once
#include <map>
#include <string>
#include "BMPTextureLoader.h" // Incluye el cargador de texturas BMP

class TextureManager {
private:
    std::map<std::string, GLuint> textures; // Mapa para almacenar texturas por nombre

public:
    TextureManager() {}
    ~TextureManager();

    GLuint loadTexture(const std::string& fileName); // Función para cargar una textura
    void unloadTexture(const std::string& fileName); // Función para liberar una textura
    GLuint getTexture(const std::string& fileName); // Función para obtener una textura
};
