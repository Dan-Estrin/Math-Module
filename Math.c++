#include "Math.h++"
#include <iostream>

/// @brief 
/// @param values 
/// @param size 
Math::Matrix::Matrix(int* values, unsigned int size){
    this->size = size;
    this->rows = Math::sqrt(size);
    this->columns = this->rows;
    this->values = new int[size];
    for(int i = 0; i < size; i++){
        values[i] = values[i];
    }
}

Math::Matrix::~Matrix(){
    delete[] values;
}

float Math::sqrt(float num){
    if(num <= 0) return 0;
    float sqrt = 0;
    while(((sqrt+1)*(sqrt+1)) <= num){sqrt++;}
    while(((sqrt+0.1)*(sqrt+0.1)) < num){sqrt+=0.1;}
    while(((sqrt+0.01)*(sqrt+0.01)) < num){sqrt+=0.01;}
    while(((sqrt+0.001)*(sqrt+0.001)) < num){sqrt+=0.001;}
    return sqrt;
}