#pragma once
#include <glad/glad.h>

class EBO{
    public:
        EBO();
        void Bind();
        void Unbind();
        void Draw();
    private:
        unsigned int id;
};