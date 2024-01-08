#include "VBO.h"
#include "glad/glad.h"

VBO::VBO(){
    glGenBuffers(1, &id);
}

void VBO::Bind(float* verts, int numVerts){
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*numVerts, verts, GL_DYNAMIC_DRAW);
}