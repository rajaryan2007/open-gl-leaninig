#include "VertexBuffer.h"
#include <glad/glad.h>

VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::deleteBuffer() {
    glDeleteBuffers(1, &ID);
}
