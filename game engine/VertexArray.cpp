#include "VertexArray.h"
#include <glad/glad.h>

VertexArray::VertexArray() {
    glGenVertexArrays(1, &ID);
}

void VertexArray::bind() const {
    glBindVertexArray(ID);
}

void VertexArray::unbind() const {
    glBindVertexArray(0);
}

void VertexArray::deleteArray() {
    glDeleteVertexArrays(1, &ID);
}
