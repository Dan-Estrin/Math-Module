#include "Math.h++"

template <typename mType>
Math::Matrix<mType>::Matrix(mType* vals, unsigned int rows, unsigned int columns){
    if(rows == 1 && columns == 1) throw 100;
    if(rows < 0 || columns < 0) throw 101;
    this->rows = rows;
    this->cols = columns;
    this->vals = new mType[rows*columns];
    for(int i = 0; i < rows*columns; i++){
        this->vals[i] = vals[i];
    }
}

template <typename mType>
Math::Matrix<mType>::Matrix(unsigned int rows, unsigned int columns){
    this->rows = rows;
    this->cols = columns;
    this->vals = new int[rows*columns];
}

template <typename mType>
Math::Matrix<mType>::Matrix(){
    this->cols = 0;
    this->rows = 0;
    this->vals = nullptr;
}

template <typename mType>
void Math::Matrix<mType>::operator=(Matrix& mtx){
    this->rows = mtx.rows;
    this->cols = mtx.cols;
    this->vals = new mType[this->rows*this->cols];
    for(int i = 0; i < this->rows*this->cols; i++){
        this->vals[i] = mtx.vals[i];
    }
}

template <typename mType>
Math::Matrix<mType>::~Matrix(){
    delete[] this->vals;
}

template <typename mType>
double Math::Matrix<mType>::GaussianDeterminate(){
  if(this->rows != this->cols || this->rows == 1) return 0;
  double valsC[this->rows * this->cols];
  for(int z = 0; z < this->rows * this->cols; z++){
    valsC[z] = (double)this->vals[z];
  }
  double det = 1;
  for(int row = 0; row < this->rows-1; row++){
    double* pivot = valsC+(row*this->cols)+row;
    double* currFirst = pivot+this->cols;
    if(*pivot == 0){
      double temp;
      for(int column = 0; column+row < this->cols; column++){
        temp = *(pivot+column);
        *(pivot+column) = *(currFirst+column);
        *(currFirst+column) = temp;
      }
      det *= -1;
    }
    for(int currRow = row+1; currRow < this->rows; currRow++){
      double multiplier = *currFirst/(*pivot);
      if(*currFirst < 0 && multiplier > 0 && det > 0) multiplier = -1 * multiplier;
      for(int column = 0; column+row < this->cols; column++){
        *(currFirst+column) = *(currFirst+column) - (*(pivot+column)*multiplier);
      }
      currFirst = currFirst + this->cols;
    }
  }
  for(int diag = 0; diag < this->cols; diag++){
    det *= valsC[diag*this->cols+diag];
  }
  return det;
}

template <typename mType>
Math::Matrix<mType> Math::Matrix<mType>::operator*(Math::Matrix<mType>& mtxB){
    if(this->cols != mtxB.rows) throw (700);
    mType* const tArray = new mType[this->rows * mtxB.cols];
    for(int iElem = 0; iElem < this->rows * mtxB.cols; iElem++){
        int tSum = 0;
        int row = iElem/(mtxB.cols);
        int col = iElem%(mtxB.cols);
        //this can be done because the col & row of matrixies A and B are equal, so num of
        //elements can be assumed same
        for(int offset = 0; offset < this->cols; offset++){
            tSum += this->vals[(row * this->cols) + offset] * mtxB.vals[(mtxB.cols * offset) + col];
        }
        tArray[iElem] = tSum;
    }
    return Math::Matrix<mType>(tArray, this->rows, mtxB.cols);
}

double Math::BasicComp::sqrt(double num){
    if(num < 0) throw 101;
    double sqrt = 0;
    while(((sqrt+1)*(sqrt+1)) <= num){sqrt++;}
    while(((sqrt+0.1)*(sqrt+0.1)) < num){sqrt+=0.1;}
    while(((sqrt+0.01)*(sqrt+0.01)) < num){sqrt+=0.01;}
    while(((sqrt+0.001)*(sqrt+0.001)) < num){sqrt+=0.001;}
    return sqrt;
}

double Math::BasicComp::sqrt(double num, unsigned char precision){
    if(num < 0 || precision > 7) throw 101;
    double sqrt = 0;
    double precessor = 1;
    for(int i = 0; i <= precision; i++){
        while(((sqrt+precessor)*(sqrt+precessor)) <= num){sqrt+=precessor;}
        precessor = precessor/10;
    }
    return sqrt;
}

double Math::BasicComp::CircleArea(double radius){
    if(radius < 0) throw 100;
    return 3.142*radius*radius;
}

int Math::BasicComp::pow(int base, int exponent){
    if(exponent == 0) return 1;
    int ans = 1;
    while(exponent > 0){
        if(exponent & 1) ans *= base;
    }
    base *= base;
    exponent = exponent >> 1;
    return ans;
}

double Math::BasicComp::pow(double base, int exponent){
    if(exponent == 0) return 1;
    double ans = 1;
    while(exponent > 0){
        if(exponent & 1) ans *= base;
    }
    base *= base;
    exponent = exponent >> 1;
    return ans;
}

void Math::Equation::Normalize(char* equation){
    unsigned int index = 0;
    unsigned int nLen = 0;
    while(equation[index] != '\0'){
        if(equation[index] != ' '){
            nLen++;
        }
        index++;
    }
    this->equation = new char[nLen+1];
    unsigned short offset = 0;
    for(int i = 0; i < index; i++){
        if(equation[i] != ' '){
            this->equation[offset] = equation[i];
            offset++;
        }
    }
    this->equation[nLen] = '\0';
    this->len = nLen+1;
}

Math::Equation::Equation(char* equation){
    Normalize(equation);
}

Math::Equation::Equation(){
    this->len = 0;
    this->equation = nullptr;
}

Math::Equation::~Equation(){
    delete[] this->equation;
}

void Math::Equation::operator=(Equation& cEquation){
    this->Normalize(cEquation.equation);
}

// double Math::Equation::YIntercept(){
//   //add checking to make sure that the equation can actually be
//   //interpriated in a proper way either here or in Normalize
//   int opens[10] = {};
//   int openS = 0;
//   int closes[10] = {};
//   int closeS = 0;
//   for(int i = 0; i < this->len; i++){
//     if(this->equation[i] == '(') {opens[openS] = i; openS++;}
//     if(this->equation[i] == ')') {closes[closeS] = i; closeS++;}
//   }
  
// }