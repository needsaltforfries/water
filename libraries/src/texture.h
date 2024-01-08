#pragma once
#include <glad/glad.h>
#include <iostream>
#include <stb/stb_image.h>
class Texture{
    public:
        Texture(std::string path);
        void Bind();
    private:
        unsigned int id;
};