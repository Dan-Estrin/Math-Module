#ifndef MATRIX_H
#define MATRIX_H
namespace Math{
    class Matrix{
        private:
        unsigned int size;
        unsigned int rows;
        unsigned int columns;
        int* values;

        public:
        Matrix(int* values, unsigned int size);
        Matrix(int* values);
        Matrix();
        ~Matrix();
        int GaussianDeterminate();
        static int GaussianDeterminate(Matrix& matrix);
        void operator=(Matrix& matrix);
    };

    float sqrt(float num);
};
#endif