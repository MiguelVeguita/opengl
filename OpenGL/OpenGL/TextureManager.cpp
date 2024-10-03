#include "TextureManager.h"

TextureManager::~TextureManager() {
    // Libera todas las texturas
    for (auto& texture : textures) {
        glDeleteTextures(1, &texture.second); // Borra la textura de OpenGL
    }
}

GLuint TextureManager::loadTexture(const std::string& fileName) {
    // Verificar si la textura ya está cargada
    if (textures.find(fileName) != textures.end()) {
        return textures[fileName]; // Retorna la textura existente
    }

    BMPTextureLoader loader; // Crea un cargador BMP
    GLuint texture = loader.LoadBMP(fileName.c_str()); // Carga la textura

    if (texture != (GLuint)-1) { // Si se carga correctamente
        textures[fileName] = texture; // Guarda la textura en el mapa
        return texture;
    }

    return (GLuint)-1; // Retorna un valor inválido si falla
}

void TextureManager::unloadTexture(const std::string& fileName) {
    auto it = textures.find(fileName);
    if (it != textures.end()) {
        glDeleteTextures(1, &it->second); // Borra la textura de OpenGL
        textures.erase(it); // Elimina la textura del mapa
    }
}

GLuint TextureManager::getTexture(const std::string& fileName) {
    auto it = textures.find(fileName);
    if (it != textures.end()) {
        return it->second; // Retorna la textura
    }
    return (GLuint)-1; // Retorna un valor inválido si no se encuentra
}
