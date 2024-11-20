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
    double* const first = valuesC;
    for(int row = 0; row < this->rows-1; row++){
        double* const pivot = first+((row*this->columns)+row);
        double* const underPivot = pivot+this->columns;
        std::cout<<"pivot: "<<*pivot<<std::endl;
        std::cout<<"under pivot: "<<*underPivot<<std::endl;
        double* currFirst = underPivot;
        for(int currRow = row+1; currRow < this->rows; currRow++){
            double multiplier = *currFirst/(*pivot);
            if(*currFirst < 0 && multiplier > 0) multiplier = -1 * multiplier;
            for(int column = 0; column+row < this->columns; column++){
                *(currFirst+column) = *(currFirst+column) - (*(pivot+column)*multiplier);
            }
            currFirst = currFirst + this->columns;
        }
        //if(row == 0)break;
    }
    for(int i = 1; i <= this->columns*this->rows; i++){std::cout<<valuesC[i-1]<<'\t'; if(i%4 == 0) std::cout<<std::endl;}//TESTING
    double determinate = 1;
    for(int bullshit = 0; bullshit < this->columns; bullshit++){
        determinate *= valuesC[bullshit*this->columns+bullshit];
    }
    std::cout << "determinate: " << determinate << std::endl;
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
    int temp[16] = {8,7,6,1,1,2,3,7,9,3,2,5,7,4,2,1};
    int* tempP = temp;
    Math::Matrix test = Math::Matrix(tempP, 4, 4);
    test.GaussianDeterminate();
    return 0;
}
