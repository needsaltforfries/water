#pragma once

#include <glad/glad.h>
#include "VBO.h"

class VAO{
    public:
        VAO();
        void LinkAttribute(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
        void Bind(int numVerts, int stride, int offset, size_t size);
        void Draw(int numVerts);
    private:
        unsigned int id;
};