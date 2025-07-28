#pragma once

class VertexBuffer {
private:
    unsigned int ID;

public:
    VertexBuffer(const void* data, unsigned int size);
    void bind() const;
    void unbind() const;
    void deleteBuffer();
};


