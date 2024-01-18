#include "vertices.h"
#include <iostream>
#include <cmath>

//100 vertices
const int size = 500;
const int step = 5;
const int numVertices = size/step;

float plane[size];

int columns = 10;

void createPlane(){
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
                    plane[index] = (-5 + col)/5.0;
                    break;
                case 1:
                    plane[index] = 0;
                    break;
                case 2:
                    plane[index] = (-5 + i/(step*columns))/5.0;
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
    // for(int i = 0; i < 500; i+=5){
    //     std::cout << plane[i] << ", " << plane[i+1] << ", " << plane[i+2] << std::endl;
    // }
    //std::cout << "all vertices." << std::endl;
}

float* getVertices(){
    createPlane();
    return plane;
    //return vertices;
}

int vertSize(){
    return size;
    //return sizeof(pyrVerts)/sizeof(float);
}

int numVerts(){
    return numVertices;
}

void makeWave(float dT){
    for(int i = 0; i < numVertices; ++i){
        float x = plane[5*i];
        float z = plane[5*i+2];
        plane[5*i + 1] = (sin((dT+x+z))+cos(dT+z)+sin(.5*dT+3*x))/5.0;
    }
    //std::cout << plane[1] << std::endl;
}