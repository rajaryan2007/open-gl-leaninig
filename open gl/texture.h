#pragma once
// Texture.h

#include <glad/glad.h>
#include <string>

class Texture {
public:
    GLuint ID;
    Texture(const std::string& path);
    
    void Bind() const;
};


