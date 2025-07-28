#pragma once
// Mesh.h


#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>

struct Vertex {
    glm::vec3 Position;
    glm::vec2 TexCoords;
};

class Mesh {
public:
    std::vector<Vertex> vertices;
    GLuint VAO, VBO;

    Mesh(const std::vector<Vertex>& vertices);

    void Draw();

private:
    void setupMesh();
};



