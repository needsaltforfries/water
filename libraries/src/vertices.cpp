#include "vertices.h"
#include <iostream>

//500 floats, 100 vertices
const int size = 500;

// float vertices1[] = {
//     //verts                 //cols              //texture
//     //first face
//     0.5f,   0.5f,    0.0f,  1.0f, 0.0f, 0.0f,   1.0f, 1.0f,
//     0.5f,   -0.5f,   0.0f,  0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
//     -0.5f,  -0.5f,   0.0f,  0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
//     -0.5f,  0.5f,    0.0f,  1.0f, 1.0f, 0.0f,   0.0f, 1.0f,
// };

// float cubeVerts[] = {
//     //vert              //texture
//     0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
//     0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
//     0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//     0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//     -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
//     -0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
//     -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//     0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
//     0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
//     0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
//     -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
//     -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//     -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//     -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//     -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//     -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//     -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//     -0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//     0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//     0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//     0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//     0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//     0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//     0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//     -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//     0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
//     0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
//     0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
//     -0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
//     -0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
//     -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
//     0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
//     0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//     0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
//     -0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
//     -0.5f, 0.5f, -0.5f, 0.0f, 1.0f
// };

// float pyrVerts[] =
// { //     COORDINATES      TexCoord  //
//     //base
// 	-0.5f, 0.0f,  0.5f,   0.0f, 0.0f,
// 	-0.5f, 0.0f, -0.5f,   0.0f, 1.0f,
//     0.5f, 0.0f, -0.5f,   1.0f, 1.0f,

//     0.5f, 0.0f, -0.5f,   1.0f, 1.0f,
//     0.5f, 0.0f,  0.5f,   1.0f, 0.0f,
//     0.5f, 0.0f,  0.5f,   0.0f, 0.0f,

//     //f1
//     -0.5f, 0.0f, 0.5f,  0.2f, 0.5f,
//     0.0f, 0.8f,  0.0f,  0.5f, 1.0f,
//     0.5f, 0.0f, 0.5f,   0.8f, 0.5f,
//     //f2
//     -0.5f, 0.0f, -0.5f, 0.2f, 0.5f,
//     0.0f, 0.8f, 0.0f, 0.5f, 1.0f,
//     0.5f, 0.0f, -0.5f, 0.8f, 0.5f,
//     //f3
//     0.5f, 0.0f, 0.5f, 0.2f, 0.5f,
//     0.0f, 0.8f, 0.0f, 0.5f, 1.0f,
//     0.5f, 0.0f, -0.5f, 0.8f, 0.5f,
//     //f4
//     -0.5f, 0.0f, 0.5f, 0.2f, 0.5f,
//     0.0f, 0.8f, 0.0f, 0.5f, 1.0f,
//     -0.5f, 0.0f, -0.5f, 0.8f, 0.5f,
	 
// };

float plane[size];

int columns = 10;

void createPlane(){
    int step = 5;
    int index = 0;
    int col = 0;
    for(int i = 0; i < size; i+=step){
        col = col%columns;
        //std::cout << std::endl << i << std::endl;
        //one vertex
        for(int j = 0; j < step; ++j){
            index = i + j;
            switch(j){
                case 0:
                    plane[index] = (-5 + col)/(float)5;
                    break;
                case 1:
                    plane[index] = 0;
                    break;
                case 2:
                    plane[index] = (-5 + i/(step*columns))/(float)5;
                    break;
                case 3:
                case 4:
                    plane[index] = 1.0f;
                    break;
            }           
        }
        col++;
        //vertex made, make triangle
    }
}

float* getVertices(){
    createPlane();
    return plane;
    //return vertices;
}

int numVerts(){
    return size;
    //return sizeof(pyrVerts)/sizeof(float);
}