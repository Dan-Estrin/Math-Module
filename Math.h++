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
    inline Matrix(mType* vals, unsigned int rows, unsigned int columns);
    inline Matrix(unsigned int rows, unsigned int columns);
    inline Matrix(Matrix<mType>& mtx);
    inline Matrix();
    inline ~Matrix();

    //use methods
    inline Matrix<double> UpperTriangular();//
    inline int Rank();//UNTESTED
    inline double GaussianDeterminate();
    inline mType ElementAt(unsigned int index);
    inline mType ElementAt(unsigned int row, unsigned int col);
    inline void ChangeAt(unsigned int index, mType val);//UNTESTED
    inline void ChangeAt(unsigned int row, unsigned int col, mType val);//UNTESTED
    inline Matrix<mType> Transpose();

    //operator overloads
    inline Matrix<mType> operator+(Matrix<mType>& mxt);
    inline Matrix<mType> operator*(Matrix<mType>& mtx);
    inline mType operator[](int index);
    inline void operator=(Matrix<mType>& mtx);
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
#endif