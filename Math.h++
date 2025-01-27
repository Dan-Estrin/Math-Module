#ifndef MATRIX_H
#define MATRIX_H
namespace Math{
    template<typename mType>
    class Matrix{
        // TODO: make private after testing is done
        public:
        unsigned int rows;
        unsigned int cols;
        mType* vals;

        public:
        Matrix(mType* vals, unsigned int rows, unsigned int columns);//DONE
        Matrix(unsigned int rows, unsigned int columns);//DONE
        Matrix();//DONE
        ~Matrix();//DONE

        double GaussianDeterminate();//DONE
        Matrix<mType> operator*(Matrix<mType>& mtxB);//DONE
        void operator=(Matrix<mType>& mtx);//DONE
    };

    class Equation{
        // TODO: make private after testing
        public:
        unsigned short len;
        char* equation;
        void Normalize(char* equation);//DONE

        public:
        Equation(char* equation);//DONE
        Equation();//DONE
        ~Equation();//DONE
        void operator=(Equation& cEquation);//DONE
        // double YIntercept();
        // char* Derivative(char vod);
        // char* InDefIntegral(char voi);
        // char* DefIntegral(char voi);
    };

    namespace BasicComp{
        double sqrt(double num);//DONE
        double sqrt(double num, unsigned char precision);//DONE
        double CircleArea(double radius);//DONE
        int pow(int base, int exponent);//DONE
        double pow(double base, int exponent);//DONE
    };
};
#endif

/*some random additions for testing*/