//
// Created by jerome on 17/09/15.
//

#include <thread>
#include <vector>
#include <cmath>
#include "MatrixMultithreaded.h"


template <typename T>
Matrix<T> * MatrixMultithreaded<T>::product(const Matrix<T> *a, const Matrix<T> *b) {

    if (a->size_col != b->size_row) {
        throw 1;
    }

    int final_size = a->size_col;

    Matrix<T> *result = new Matrix(final_size, final_size);

    std::vector<std::thread> workers;

    for (int i=0; i<std::thread::hardware_concurrency(); i++)
    {
        workers.push_back(std::thread(&MatrixMultithreaded::worker, this, b, result, i));
    }

    for (auto& worker: workers) {
        worker.join();
    }

    return result;
}

template <typename T>
void MatrixMultithreaded<T>::worker(const Matrix<T> *b, Matrix<T> *newMatrix, int pid) {
    int step = std::ceil(this->getRow() / std::thread::hardware_concurrency());
    int min = step * pid;
    int max = min + step;

    workersProduct(b, newMatrix, min, max, this->getCol());
}


template<typename T>
void MatrixMultithreaded::workersProduct<T>(const Matrix<T> *b, Matrix<T> *newMatrix, unsigned int min, unsigned int max,
                                         unsigned int finalSize) {

    for (int row = min; row <max; row++) {
        for (int col = 0; col < b->size_col; col++) {
            for (int inner = 0; inner < finalSize; inner++) {
                newMatrix->set(row, col, newMatrix->get(row, col) + this->get(row, inner) * b->get(inner, col));
            }
        }
    }

}

