//
// Created by jerome on 17/09/15.
//

#ifndef THREADS_MATRIXMULTITHREADED_H
#define THREADS_MATRIXMULTITHREADED_H


#include <mutex>
#include "Matrix.h"


template <typename T>
class MatrixMultithreaded: public Matrix<T> {

public:
    MatrixMultithreaded(int x, int y) : Matrix<T>(x, y) { }

    void worker(const Matrix<T>* b, Matrix<T>* newMatrix, int pid);

private:
    virtual Matrix<T> *product(const Matrix<T> *a, const Matrix<T> *b);
    void workersProduct(const Matrix<T>* b, Matrix<T>* newMatrix, unsigned int min, unsigned int max, unsigned int finalSize);
    static std::mutex lock;
};


#endif //THREADS_MATRIXMULTITHREADED_H
