#pragma once

class VertexArray {
private:
    unsigned int ID;

public:
    VertexArray();
    void bind() const;
    void unbind() const;
    void deleteArray();
};


