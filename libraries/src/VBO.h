#pragma once

class VBO{
    unsigned int id;
    public:
        VBO();
        void Bind(float* verts, int numVerts);
        void Unbind();
        unsigned int getId();
};