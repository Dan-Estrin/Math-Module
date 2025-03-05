#ifndef MATRIX_H
#define MATRIX_H
namespace Math{
  template<typename mType> class Matrix;
  template<typename mType>
  class Matrix{
    private:
    unsigned int rows;
    unsigned int cols;
    mType* vals;

    public:
    //constructors & destructor
    inline Matrix(mType* vals, unsigned int rows, unsigned int columns);//DONE
    inline Matrix(unsigned int rows, unsigned int columns);//DONE
    inline Matrix();//DONE
    inline ~Matrix();//DONE

    //use methods
    inline double GaussianDeterminate();//DONE
    inline mType ElementAt(unsigned int index);//DONE
    inline mType ElementAt(unsigned int row, unsigned int col);//DONE
    inline void ChangeAt(unsigned int index, mType val);//UNTESTED
    inline void ChangeAt(unsigned int row, unsigned int col, mType val);//UNTESTED

    //operator overloads
    inline Matrix<mType> operator+(Matrix<mType>& mxt);//DONE
    inline Matrix<mType> operator*(Matrix<mType>& mtx);//DONE
    inline mType operator[](int index);//DONE
    inline void operator=(Matrix<mType>& mtx);//DONE
  };

  class Equation{
    private:
    unsigned short len;
    char* equation;
    void Normalize(char* equation);//DONE
    unsigned int Priorities(unsigned int* const open, unsigned int* const close);

    public:
    //TODO: create a parser for use in all these equation funcs
    Equation(char* equation);//DONE
    Equation();//DONE
    ~Equation();//DONE
    void operator=(Equation* cEquation);//DONE
    double YIntercept();
    // char* Derivative(char vod);
    // char* InDefIntegral(char voi);
    // char* DefIntegral(char voi);
  };

  double Sqrt(double num);//DONE
  double Sqrt(double num, unsigned int precision);//DONE
  double CircleArea(double radius);//DONE
  int Pow(int base, int exponent);//DONE
  double Pow(double base, int exponent);//DONE
  double LinePoint(const double slope, const double yInt, const double xOffset);
  float ExpectedValue(const float* const probabilities, const float* const values, const int size);
};
#endif