#include "Math.h++"
#include <iostream>

template <typename mType>
Math::Matrix<mType>::Matrix(mType* values, unsigned int rows, unsigned int columns){
    if(rows == 1 && columns == 1) throw 100;
    if(rows < 0 || columns < 0) throw 101;
    this->mRows = rows;
    this->mColumns = columns;
    this->values = new mType[rows*columns];
    for(int i = 0; i < rows*columns; i++){
        this->values[i] = values[i];
    }
}

template <typename mType>
Math::Matrix<mType>::Matrix(unsigned int rows, unsigned int columns){
    this->mRows = rows;
    this->mColumns = columns;
    this->values = new int[rows*columns];
}

template <typename mType>
void Math::Matrix<mType>::operator=(Matrix& matrix){
    this->mRows = matrix.mRows;
    this->mColumns = matrix.mColumns;
    this->values = new int[matrix.mRows*matrix.mColumns];
    for(int i = 0; i < matrix.mRows*matrix.mColumns; i++){
        this->values[i] = values[i];
    }
}

template <typename mType>
Math::Matrix<mType>::~Matrix(){
    delete[] this->values;
}

template <typename mType>
double Math::Matrix<mType>::GaussianDeterminate(){
    if(this->mRows != this->mColumns || this->mRows == 1) return 0;
    double valuesC[this->mRows * this->mColumns];
    for(int z = 0; z < this->mRows * this->mColumns; z++){
        valuesC[z] = this->values[z];
    }
    double* const first = valuesC;
    for(int row = 0; row < this->mRows-1; row++){
        double* const pivot = first+((row*this->mColumns)+row);
        double* currFirst = pivot+this->mColumns;
        for(int currRow = row+1; currRow < this->mRows; currRow++){
            double multiplier = *currFirst/(*pivot);
            if(*currFirst < 0 && multiplier > 0) multiplier = -1 * multiplier;
            for(int column = 0; column+row < this->mColumns; column++){
                *(currFirst+column) = *(currFirst+column) - (*(pivot+column)*multiplier);
            }
            currFirst = currFirst + this->mColumns;
        }
    }
    double determinate = 1;
    for(int bullshit = 0; bullshit < this->mColumns; bullshit++){
        determinate *= valuesC[bullshit*this->mColumns+bullshit];
    }
    return determinate;
}

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
    double temp[9] = {1,2,8,0,7,6,4,3,1};
    double* tempP = temp;
    Math::Matrix test = Math::Matrix(tempP, 3, 3);
    std::cout<<test.GaussianDeterminate();
    return 0;
}