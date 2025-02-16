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
    Matrix(mType* vals, unsigned int rows, unsigned int columns);//DONE
    Matrix(unsigned int rows, unsigned int columns);//DONE

    double GaussianDeterminate();//DONE
    mType ElementAt(unsigned short index);
    mType ElementAt(unsigned short row, unsigned short col);
    Matrix();//DONE
    ~Matrix();//DONE

    Matrix<mType> operator+(Matrix<mType>& mxt);//DONE
    Matrix<mType> operator*(Matrix<mType>& mtx);//DONE
    void operator=(Matrix<mType>& mtx);//DONE
  };

  class Equation{
    private:
    unsigned short len;
    char* equation;
    void Normalize(char* equation);//DONE
    unsigned short Priorities(unsigned short* const open, unsigned short* const close);

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