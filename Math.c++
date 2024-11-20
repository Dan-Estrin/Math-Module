#include "Math.h++"
#include <iostream>

Math::Matrix::Matrix(int* values, unsigned int rows, unsigned int columns){
    this->rows = rows;
    this->columns = columns;
    this->values = new int[rows*columns];
    for(int i = 0; i < rows*columns; i++){
        this->values[i] = values[i];
    }
}

Math::Matrix::Matrix(unsigned int rows, unsigned int columns){
    this->rows = rows;
    this->columns = columns;
    this->values = new int[rows*columns];
}

void Math::Matrix::operator=(Matrix& matrix){
    this->rows = matrix.rows;
    this->columns = matrix.columns;
    this->values = new int[matrix.rows*matrix.columns];
    for(int i = 0; i < matrix.rows*matrix.columns; i++){
        this->values[i] = values[i];
    }
}

Math::Matrix::~Matrix(){
    delete[] values;
}

double Math::Matrix::GaussianDeterminate(){
    double valuesC[this->rows * this->columns];
    for(int z = 0; z < this->rows * this->columns; z++){
        valuesC[z] = this->values[z];
    }
    for(int k = 0; k < this->columns; k++){
        double* pivot = &valuesC[(k*this->columns)+k];
        for(int f = 1; f < this->columns-k; f++){
            double* next = pivot+(this->columns * f);
            double multiplier = *next/(*pivot);
            if (multiplier > 0) multiplier *= -1;
            for(int i = k; i < this->rows; i++){
                *(next+i) = *(next+i) + (*(pivot+i) * multiplier);
            }
        }
    }
    for(int i = 1; i <= this->columns*this->rows; i++){std::cout<<valuesC[i-1]<<"       "; if(i%4 == 0) std::cout<<std::endl;}//TESTING
    return 0;
}

// double Math::Matrix::GaussianDeterminate(Matrix& matrix){

// }

double Math::sqrt(int num){
    if(num <= 0) return 0;
    double sqrt = 0;
    while(((sqrt+1)*(sqrt+1)) <= num){sqrt++;}
    while(((sqrt+0.1)*(sqrt+0.1)) < num){sqrt+=0.1;}
    while(((sqrt+0.01)*(sqrt+0.01)) < num){sqrt+=0.01;}
    while(((sqrt+0.001)*(sqrt+0.001)) < num){sqrt+=0.001;}
    return sqrt;
}

double Math::sqrt(int num, unsigned char precision){
    double sqrt = 0;
    double precessor = 1;
    for(int i = 0; i <= precision; i++){
        while(((sqrt+precessor)*(sqrt+precessor)) <= num){sqrt+=precessor;}
        precessor = precessor/10;
    }
    return sqrt;
}

int main(){
    int temp[16] = {8,7,6,1,1,2,3,7,9,2,1,3,5,4,9,8};
    int* tempP = temp;
    Math::Matrix test = Math::Matrix(tempP, 4, 4);
    test.GaussianDeterminate();
    return 0;
}
