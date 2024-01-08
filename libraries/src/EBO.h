#pragma once
#include <glad/glad.h>

class EBO{
    public:
        EBO();
        void Bind();
        void Draw();
    private:
        unsigned int id;
};