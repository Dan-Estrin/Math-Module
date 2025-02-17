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
void Math::Matrix<mType>::operator=(Matrix<mType>& mtx){
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
  //impossible to find the determinate, return nothing
  if(this->rows != this->cols || this->rows == 1) throw(700);
  double valsC[this->rows * this->cols];
  for(short z = 0; z < this->rows * this->cols; z++){
    //explicite cast to avoid bit loss
    valsC[z] = (double)this->vals[z];
  }
  //main row itteration step
  for(short row = 0; row < this->rows-1; row++){
    double* const pivot = valsC+(row*this->cols)+row;
    double* currFirst = pivot+this->cols;
    //pivot is 0 and the row must be swapped with the next one
    if(*pivot == 0){
      for(short column = 0; column+row < this->cols; column++){
        const double temp = *(pivot+column);
        *(pivot+column) = -*(currFirst+column);
        *(currFirst+column) = temp;
      }
    }
    //changing row itteration step
    for(short currRow = row+1; currRow < this->rows; currRow++){
      const double multiplier = *currFirst/(*pivot);
      //element itteration step
      for(short column = 0; column+row < this->cols; column++){
        *(currFirst+column) = *(currFirst+column) - (*(pivot+column)*multiplier);
      }
      currFirst = currFirst + this->cols;
    }
  }
  double det = 1;
  for(short diag = 0; diag < this->cols; diag++){
    det *= valsC[(diag*this->cols)+diag];
  }
  return det;
}

template <typename mType>
mType Math::Matrix<mType>::ElementAt(unsigned short index){
  if(index > this->rows*this->cols ||index <= 0) throw (700);
  return this->vals[index-1];
}

template <typename mType>
mType Math::Matrix<mType>::ElementAt(unsigned short row, unsigned short col){
  if(row > this->rows || col < this->col ||
    row <= 0 || col <= 0
  ) throw (700);
  return this->vals[(this->cols*row) + col - 1];
}

template <typename mType>
Math::Matrix<mType> Math::Matrix<mType>::operator*(Math::Matrix<mType>& mtx){
  if(this->cols != mtx.rows) throw (700);
  mType* const tArray = new mType[this->rows * mtx.cols];
  for(int iElem = 0; iElem < this->rows * mtx.cols; iElem++){
    int tSum = 0;
    int row = iElem/(mtx.cols);
    int col = iElem%(mtx.cols);
    //this can be done because the col & row of matrixies A and B are equal, so num of
    //elements can be assumed same
    for(int offset = 0; offset < this->cols; offset++){
        tSum += this->vals[(row * this->cols) + offset] * mtx.vals[(mtx.cols * offset) + col];
    }
    tArray[iElem] = tSum;
  }
  return Math::Matrix<mType>(tArray, this->rows, mtx.cols);
}

template<typename mType>
Math::Matrix<mType> Math::Matrix<mType>::operator+(Math::Matrix<mType>& mtx){
  if(this->rows != mtx.rows || this->cols != mtx.cols) throw(700);
  mType tArray[this->rows * this->cols];
  for(int i = 0; i < this->cols * this->rows; i++){
    tArray[i] = this->vals[i] + mtx.vals[i];
  }
  return Math::Matrix<mType>(tArray, this->rows, this->cols);
}

double Math::BasicComp::Sqrt(double num){
  if(num < 0) throw 101;
  double sqrt = 0;
  while(((sqrt+1)*(sqrt+1)) <= num){sqrt++;}
  while(((sqrt+0.1)*(sqrt+0.1)) < num){sqrt+=0.1;}
  while(((sqrt+0.01)*(sqrt+0.01)) < num){sqrt+=0.01;}
  while(((sqrt+0.001)*(sqrt+0.001)) < num){sqrt+=0.001;}
  return sqrt;
}

double Math::BasicComp::Sqrt(double num, unsigned char precision){
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

int Math::BasicComp::Pow(int base, int exponent){
  if(exponent == 0) return 1;
  int ans = 1;
  while(exponent > 0){
    if(exponent & 1) ans *= base;
  }
  base *= base;
  exponent = exponent >> 1;
  return ans;
}

double Math::BasicComp::Pow(double base, int exponent){
  if(exponent == 0) return 1;
  double ans = 1;
  while(exponent > 0){
    if(exponent & 1) ans *= base;
  }
  base *= base;
  exponent = exponent >> 1;
  return ans;
}

double Math::BasicComp::LinePoint(const double slope, const double yInt, const double xOffset){
  return (slope * xOffset) + yInt;
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

unsigned short Math::Equation::Priorities(unsigned short* const open, unsigned short* const close){
  short oI = 0;
  short cI = 0;
  for(short i = 0; i < this->len; i++){
    if(this->equation[i] == '('){
      open[oI] = i;
      oI++;
    }
    if(this->equation[i] == ')'){
      close[cI] = i;
      cI++;
    }
  }
  if(oI != cI || this->len == 0) return 0;
  else return oI + 1;
}

Math::Equation::Equation(char* equation){
  this->Normalize(equation);
}

Math::Equation::Equation(){
  this->len = 0;
  this->equation = nullptr;
}

Math::Equation::~Equation(){
  delete[] this->equation;
}

void Math::Equation::operator=(Equation* cEquation){
  this->Normalize(cEquation->equation);
}

// double Math::Equation::YIntercept(){
//   unsigned short opens[10];
//   unsigned short closes[10];
//   unsigned short len = this->Priorities(opens, closes) - 1;
// }