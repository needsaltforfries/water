#include "EBO.h"
#include <iostream>

unsigned int indices[486];

void generateIndices(){
	int index = 0;
	for(int i = 0; i < 9; ++i){
		for(int j = 1; j < 10; ++j){
			//tri1
			indices[index] = 10*i + j;
			indices[index+1] = 10*i + (j+1);
			indices[index+2] = 10*(i+1) + j;
			//tri2
			indices[index+3] = 10*i + (j+1);
			indices[index+4] = 10*(i+1) + j;
			indices[index+5] = 10*(i+1) + (j+1);
			index += 6;
		}
	}
	// for(int i = 0; i < 486; i+=3){
	// 	std::cout << indices[i] << ", " << indices[i+1] << ", " << indices[i+2] << std::endl;
	// }
	//std::cout << "all indices." << std::endl;
}

EBO::EBO(){
    glGenBuffers(1, &id);
	generateIndices();
}
void EBO::Bind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}
void EBO::Draw(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glDrawElements(GL_TRIANGLES, 161*3, GL_UNSIGNED_INT, 0);
}