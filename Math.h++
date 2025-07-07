#ifndef MATRIX_H
#define MATRIX_H
namespace Math{
   template<typename mType>
   class Matrix{
      private:
      unsigned int rows;
      unsigned int cols;
      mType* vals;

      public:
      //constructors & destructor
      Matrix(mType* vals, unsigned int rows, unsigned int columns);
      Matrix(unsigned int rows, unsigned int columns);
      Matrix(char* str, char seperator);
      Matrix(Matrix<mType>& mtx);
      Matrix();
      ~Matrix();

      //use methods
      Matrix<double> UpperTriangular();
      int Rank();//UNTESTED
      double GaussianDeterminate();
      mType ElementAt(unsigned int index);
      mType ElementAt(unsigned int row, unsigned int col);
      void ChangeAt(unsigned int index, mType val);
      void ChangeAt(unsigned int row, unsigned int col, mType val);
      Matrix<mType> Transpose();
      void AddRow(mType* row, int len);
      void AddColumn(mType* column, int len);

      //operator overloads
      Matrix<mType> operator+(Matrix<mType>& mxt);
      Matrix<mType> operator*(Matrix<mType>& mtx);
      mType operator[](int index);
      void operator=(Matrix<mType>& mtx);
   };

   class Equation{
      private:
      unsigned int len;
      char* equation;
      void Normalize(char* equation);
      unsigned int Priorities(unsigned int* const open, unsigned int* const close);

      public:
      //TODO: create a parser for use in all these equation funcs
      Equation(char* equation);
      Equation();
      ~Equation();
      void operator=(Equation* cEquation);
      double YIntercept();
      // char* Derivative(char vod);
      // char* InDefIntegral(char voi);
      // char* DefIntegral(char voi);
   };

   double Sqrt(double num);
   double Sqrt(double num, unsigned int precision);
   double CircleArea(double radius);
   int Pow(int base, int exponent);
   double Pow(double base, int exponent);
   double LinePoint(const double slope, const double yInt, const double xOffset);
   float ExpectedValue(const float* const probabilities, const float* const values, const int size);
};

//standard use materxies for dynamic compilation
template class Math::Matrix<unsigned int>;
template class Math::Matrix<unsigned char>;
template class Math::Matrix<unsigned short>;
template class Math::Matrix<unsigned long long>;
template class Math::Matrix<int>;
template class Math::Matrix<char>;
template class Math::Matrix<short>;
template class Math::Matrix<long long>;
template class Math::Matrix<double>;
template class Math::Matrix<float>;
#endif