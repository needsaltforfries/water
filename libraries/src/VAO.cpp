#include "VAO.h"

VAO::VAO(){
    glGenVertexArrays(1, &id);
}

void VAO::Bind(int numVerts, int stride, int offset, size_t size){
    glBindVertexArray(id);
    //vertex coordinates
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride*size, (void*)0);
    glEnableVertexAttribArray(0);
    //colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride*size, (void*)(offset*size));
    glEnableVertexAttribArray(1);
    //textures
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride*size, (void*)(offset*size));
    glEnableVertexAttribArray(2);
}

void VAO::Unbind(){
    glBindVertexArray(0);
}

void VAO::Draw(int numVerts){
    glDrawArrays(GL_TRIANGLES, 0, numVerts);
}