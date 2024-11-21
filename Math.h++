#ifndef MATRIX_H
#define MATRIX_H
namespace Math{
    template<typename mType>
    class Matrix{
        private:
        unsigned int mRows;
        unsigned int mColumns;
        mType* values;

        public:
        Matrix(mType* values, unsigned int rows, unsigned int columns);//DONE
        Matrix(unsigned int rows, unsigned int columns);//DONE
        ~Matrix();//DONE

        double GaussianDeterminate();//DONE
        void operator=(Matrix& matrix);//DONE
    };

    double sqrt(int num);//DONE
    double sqrt(int num, unsigned char precision);//DONE
};
#endif