#pragma once
#include <glad/glad.h>
#include <vector>
class EBO{
    public:
        EBO(std::vector<unsigned int>& inds);
        void Bind();
        void Unbind();
        void Draw();
    private:
        std::vector<unsigned int> indices;
        unsigned int id;
};