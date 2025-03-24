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
    Matrix(mType* vals, unsigned int rows, unsigned int columns);//DONE
    Matrix(unsigned int rows, unsigned int columns);//DONE

    double GaussianDeterminate();//DONE
    mType ElementAt(unsigned int index);//DONE
    mType ElementAt(unsigned int row, unsigned int col);//DONE
    Matrix<mType> Transpose();//DONE
    Matrix();//DONE
    ~Matrix();//DONE

    Matrix<mType> operator+(Matrix<mType>& mxt);//DONE
    Matrix<mType> operator*(Matrix<mType>& mtx);//DONE
    mType operator[](unsigned int index);//DONE
    void operator=(Matrix<mType>& mtx);//DONE
  };

  class Equation{
    private:
    unsigned int len;
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

  namespace BasicComp{
    double Sqrt(double num);//DONE
    double Sqrt(double num, unsigned char precision);//DONE
    double CircleArea(double radius);//DONE
    int Pow(int base, int exponent);//DONE
    double Pow(double base, int exponent);//DONE
    double LinePoint(const double slope, const double yInt, const double xOffset);
  };
};
#endif