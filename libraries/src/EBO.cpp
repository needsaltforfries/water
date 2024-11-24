#include "EBO.h"
#include <iostream>

const int numIndices = 162 * 3;
GLuint indices[numIndices];

void generateIndices(){
	int index = 0;
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j){
			//tri1
			indices[index] = 10*i + j; //1
			indices[index+1] = 10*i + (j+1); //2
			indices[index+2] = 10*(i+1) + j; //11
			//tri2
			indices[index+3] = 10*i + (j+1); //2
			indices[index+4] = 10*(i+1) + j; //11
			indices[index+5] = 10*(i+1) + (j+1); //12
			index += 6;
		}
	}
	// for(GLuint i = 0; i < sizeof(indices); i+=3*sizeof(int)){
	// 	int j = i/sizeof(int);
	// 	std::cout << indices[j] << ", " << indices[j+1] << ", " << indices[j+2] << std::endl;
	// }
	// std::cout << "all indices." << std::endl;
}

EBO::EBO(){
    glGenBuffers(1, &id);
	generateIndices();
}
void EBO::Bind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}
void EBO::Unbind(){
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
void EBO::Draw(){
    glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT, 0);
}