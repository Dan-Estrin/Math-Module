#ifndef MATRIX_H
#define MATRIX_H
namespace Math{
    class Matrix{
        private:
        unsigned int rows;
        unsigned int columns;
        int* values;

        public:
        Matrix(int* values, unsigned int rows, unsigned int columns);//DONE
        Matrix(unsigned int rows, unsigned int columns);//DONE
        ~Matrix();//DONE

        double GaussianDeterminate();
        static double GaussianDeterminate(Matrix& matrix);
        void operator=(Matrix& matrix);//DONE
    };

    double sqrt(int num);//DONE
    double sqrt(int num, unsigned char precision);//DONE
};
#endif
