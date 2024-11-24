#include "vertices.h"

//100 vertices
const double stepSize = 0.05;
const double LEFT = -2.0;
const double RIGHT = 2.0;
const double UP = 2.0;
const double DOWN = -2.0;

int rows = (RIGHT - LEFT) / stepSize;
int cols = (UP - DOWN) / stepSize;

std::vector<float> verts;
std::vector<unsigned int> indices;

void createPlane(){
    //generate vertices  
    for(double x = LEFT; x <= RIGHT; x+=stepSize){
        for(double z = DOWN; z <= UP; z+=stepSize){    
            verts.push_back(float(x));
            verts.push_back(float(0.0));
            verts.push_back(float(z));
        }
    }
    //generate indices
    for(int i = 0; i < rows-1; ++i){
        for(int j = 0; j < cols-1; ++j){
            int ul = i * cols + j;
            int ur = ul + 1;
            int dl = (i + 1) * cols + j;
            int dr = dl + 1;

            indices.push_back(ul);
            indices.push_back(ur);
            indices.push_back(dr);

            indices.push_back(ul);
            indices.push_back(dr);
            indices.push_back(dl);
        }
    }
}

std::vector<unsigned int> getIndices(){
    return indices;
}

std::vector<float> getVertices(){
    createPlane();
    return verts;
    //return vertices;
}

int numVerts(){
    return verts.size()/3;
}

int vertSize(){
    return verts.size() * sizeof(float);
}
double getStepSize(){
    return stepSize;
}
int numRows(){
    return rows;
}
int numCols(){
    return cols;
}