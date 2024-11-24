#include "EBO.h"
#include <iostream>

EBO::EBO(std::vector<unsigned int>& inds){
    glGenBuffers(1, &id);
	indices = inds;
}
void EBO::Bind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
}
void EBO::Unbind(){
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
void EBO::Draw(){
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}