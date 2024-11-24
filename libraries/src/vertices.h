#pragma once
#include <iostream>
#include <cmath>
#include <vector>

std::vector<float> getVertices();
std::vector<unsigned int> getIndices();
int numVerts();
int vertSize();
double getStepSize();
int numRows();
int numCols();
void makeWave(float value);