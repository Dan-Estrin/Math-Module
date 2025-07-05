#include "Math.h++"

template <typename mType>
Math::Matrix<mType>::Matrix(mType* vals, unsigned int rows, unsigned int columns){
   //refuses trivial matrix. encourages constant
   if(rows == 1 && columns == 1) throw 100;
   //refuses impossible dimensions for a matrix
   if(rows < 0 || columns < 0) throw 101;
   this->rows = rows;
   this->cols = columns;
   //populate matrix
   this->vals = new mType[rows*columns];
   for(int i = 0; i < rows*columns; i++){
      this->vals[i] = vals[i];
   }
}

template <typename mType>
Math::Matrix<mType>::Matrix(unsigned int rows, unsigned int columns){
   //refuses trivial matrix. encourages constant
   if(rows == 1 && columns == 1) throw 100;
   //refuses impossible dimensions for a matriX
   if(rows < 0 || columns < 0) throw 101;
   this->rows = rows;
   this->cols = columns;
   this->vals = new mType[rows * columns];
}

template <typename mType>
Math::Matrix<mType>::Matrix(char* str, char seperator){
   int i = 0;
   int num = 0;
   while(str[i] != '\0'){
      if(str[i] == seperator){
         num++;
      }
   }
   int temp[num];
   i = 0;
   num = 0;
   while(str[i] != '\0'){

   }
}

template<typename mType>
Math::Matrix<mType>::Matrix(Matrix<mType>& mtx){
   this->rows = mtx.rows;
   this->cols = mtx.cols;
   this->vals = new mType[this->rows * this->cols];
   for(int i = 0; i < this->rows * this->cols; i++){
      this->vals[i] = mtx[i];
   }
}

template <typename mType>
Math::Matrix<mType>::Matrix(){
   this->cols = 0;
   this->rows = 0;
   this->vals = nullptr;
}

template <typename mType>
Math::Matrix<mType>::~Matrix(){
   delete[] this->vals;
}

template <typename mType>
void Math::Matrix<mType>::ChangeAt(unsigned int index, mType val){
   this->vals[index] = val;
}

template <typename mType>
void Math::Matrix<mType>::ChangeAt(unsigned int row, unsigned int col, mType val){
   this->vals[(this->cols * row) + col] = val;
}

template <typename mType>
mType Math::Matrix<mType>::ElementAt(unsigned int index){
   if(index > this->rows * this->cols ||index <= 0) throw (700);
   return this->vals[index];
}

template <typename mType>
mType Math::Matrix<mType>::ElementAt(unsigned int row, unsigned int col){
   if(row > this->rows || col < this->cols ||
      row < 0 || col < 0
   ) throw (700);
   return this->vals[(this->cols * row) + col];
}

template <typename mType>
Math::Matrix<mType> Math::Matrix<mType>::Transpose(){
   mType tArray[this->rows * this->cols];
   for(int i = 0; i < this->rows; i++){
      for(int k = 0; k < this->cols; k++){
         tArray[i + (k * this->rows)] = this->vals[k + (i * this->cols)];
      }
   }
   return Math::Matrix<mType>(tArray, this->cols, this->rows);
}

template<typename mType>
Math::Matrix<double> Math::Matrix<mType>::UpperTriangular(){
   //temporary array for copying
   double valsC[this->rows * this->cols];
   for(int z = 0; z < this->rows * this->cols; z++){
      //explicite cast to avoid bit loss
      valsC[z] = this->vals[z];
   }
   //main row itteration step
   for(int row = 0; row < this->rows - 1; row++){
      double* const pivot = valsC + (row * this->cols) + row;
      double* currFirst = pivot + this->cols;
      //pivot is 0 and the next rows pivot would also be 0
      if(*pivot == 0 && *currFirst == 0 && this->cols == this->rows){
         //find a row where there is no 0
         while(*currFirst == 0 && currFirst < valsC + ((this->rows - row) * this->cols)){
            currFirst = currFirst + this->cols;
         }
         //there is no row with a 0 move on to the next col
         if(*currFirst == 0){
            continue;
         }
      }
      else if(*pivot == 0 && *currFirst == 0){
      
      }
    //pivot row correction
      if(*pivot == 0){
      for(int column = 0; column + row < this->cols; column++){
         const double temp = *(pivot + column);
         *(pivot + column) = -*(currFirst + column);
         *(currFirst + column) = temp;
      }
      }
      //changing row itteration step
      for(int currRow = row + 1; currRow < this->rows; currRow++){
         const double multiplier = *currFirst/(*pivot);
         //element itteration step
         for(int column = 0; column + row < this->cols; column++){
            *(currFirst + column) = *(currFirst + column) - (*(pivot + column) * multiplier);
         }
         currFirst = currFirst + this->cols;
      }
   }
   return Matrix<double>(valsC, this->rows, this->cols);
}

template <typename mType>
double Math::Matrix<mType>::GaussianDeterminate(){
   Matrix<double> temp = this->UpperTriangular();
   double det = 1;
   for(short diag = 0; diag < this->cols; diag++){
      det *= temp[(diag * this->cols) + diag];
   }
   return det;
}

template<typename mType>
int Math::Matrix<mType>::Rank(){
   Matrix<double> temp = this->UpperTriangular();
   int rank = 0;
   for(int r = 0; r < this->rows; r++){
      bool zrow = true;
      for(int c = 0; c < this->cols; c++){
         if(temp[(this->cols * r) + c] != 0){
            zrow = false;
            break;
         }
      }
      if(!zrow) rank++;
   }
   return rank;
}

template<typename mType>
void Math::Matrix<mType>::AddRow(mType* row, int len){
   if(this->cols != len) throw(700);
   mType* buff = new mType[(this->rows * this->cols) + this->cols];
   for(int i = 0; i < this->rows * this->cols; i++){
      buff[i] = this->vals[i];
   }
   for(int j = 0; j < this->cols; j++){
      buff[(this->rows * this->cols) + j] = row[j];
   }
   delete[] this->vals;
   ++this->rows;
   this->vals = buff;
}

template <typename mType>
void Math::Matrix<mType>::operator=(Matrix<mType>& mtx){
   this->rows = mtx.rows;
   this->cols = mtx.cols;
   this->vals = new mType[this->rows * this->cols];
   for(int i = 0; i < this->rows * this->cols; i++){
      this->vals[i] = mtx[i];
   }
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

template<typename mType>
mType Math::Matrix<mType>::operator[](int index){
   if(index > this->rows * this->cols || index < 0) throw (700);
   return this->vals[index];
}

double Math::Sqrt(double num){
   if(num < 0) throw 101;
   double sqrt = 0;
   while(((sqrt+1)*(sqrt+1)) <= num){sqrt++;}
   while(((sqrt+0.1)*(sqrt+0.1)) < num){sqrt+=0.1;}
   while(((sqrt+0.01)*(sqrt+0.01)) < num){sqrt+=0.01;}
   while(((sqrt+0.001)*(sqrt+0.001)) < num){sqrt+=0.001;}
   return sqrt;
}

double Math::Sqrt(double num, unsigned int precision){
   if(num < 0 || precision > 7) throw 101;
   double sqrt = 0;
   double precessor = 1;
   for(int i = 0; i <= precision; i++){
      while(((sqrt+precessor)*(sqrt+precessor)) <= num){sqrt+=precessor;}
      precessor = precessor/10;
   }
   return sqrt;
}

double Math::CircleArea(double radius){
   if(radius < 0) throw 100;
   return 3.142*radius*radius;
}

int Math::Pow(int base, int exponent){
   if(exponent == 0) return 1;
   int ans = 1;
   while(exponent > 0){
      if(exponent & 1) ans *= base;
   }
   base *= base;
   exponent = exponent >> 1;
   return ans;
}

double Math::Pow(double base, int exponent){
   if(exponent == 0) return 1;
   double ans = 1;
   while(exponent > 0){
      if(exponent & 1) ans *= base;
   }
   base *= base;
   exponent = exponent >> 1;
   return ans;
}

double Math::LinePoint(const double slope, const double yInt, const double xOffset){
   return (slope * xOffset) + yInt;
}

float Math::ExpectedValue(const float* const probabilities, const float* const values, const int size){
   float ex;
   for(int i = 0; i < size; i++){
      ex += probabilities[i] * values[i];
   }
   return ex;
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
   unsigned int offset = 0;
   for(int i = 0; i < index; i++){
      if(equation[i] != ' '){
         this->equation[offset] = equation[i];
         offset++;
      }
   }
   this->equation[nLen] = '\0';
   this->len = nLen+1;
}

unsigned int Math::Equation::Priorities(unsigned int* const open, unsigned int* const close){
   int oI = 0;
   int cI = 0;
   for(int i = 0; i < this->len; i++){
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
//   unsigned int opens[10];
//   unsigned int closes[10];
//   unsigned int len = this->Priorities(opens, closes) - 1;
// }