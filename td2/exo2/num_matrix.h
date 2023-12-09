//
// Created by Baptiste WETTERWALD on 09/12/2023.
//

#ifndef ECOLE_CPP_F_NUM_MATRIX_H
#define ECOLE_CPP_F_NUM_MATRIX_H

#include <cmath>
#include "matrix.h"

template<typename T>
class MatrixNumerical : public MatrixBase<T> {
    static_assert(std::is_same<T, int>::value || std::is_same<T, double>::value || std::is_same<T, float>::value,
                  "Available types: int, double, and float");
public:
    using MatrixBase<T>::MatrixBase;

    [[maybe_unused]] MatrixNumerical(size_t rows, size_t cols);

    MatrixNumerical(size_t rows, size_t cols, T value);

    T getDeterminant() const;

    // define + operator
    MatrixNumerical<T> operator+(const MatrixNumerical<T> &matrix) const;

    MatrixNumerical<T> operator-(const MatrixNumerical<T> &matrix) const;

    MatrixNumerical<T> operator*(const MatrixNumerical<T> &matrix) const;

    MatrixNumerical<T> operator/(const MatrixNumerical<T> &matrix) const;

    static MatrixNumerical<T> getIdentity(int size);

    MatrixNumerical<T> getInverse() const;
};

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getIdentity(int size) {
    MatrixNumerical<T> identity(size, size, 0);
    for (size_t i = 0; i < size; i++) {
        identity.addElement(i, i, 1);
    }
    return identity;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator/(const MatrixNumerical<T> &matrix) const {
    return *this * matrix.getInverse(); // because A / B = A * B^(-1)
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::getInverse() const {
    if (this->getRows() != this->getCols()) {
        throw std::invalid_argument("Matrix must be square");
    }
    // get cofactor matrix
    MatrixNumerical<T> cofactorMatrix(this->getRows(), this->getCols(), 0);
    for (size_t i = 0; i < this->getRows(); i++) {
        for (size_t j = 0; j < this->getCols(); j++) {
            MatrixNumerical<T> subMatrix(this->getRows() - 1, this->getCols() - 1, 0);
            for (size_t k = 0; k < this->getRows(); k++) {
                for (size_t l = 0; l < this->getCols(); l++) {
                    if (k < i && l < j) {
                        subMatrix.addElement(k, l, this->getElement(k, l));
                    } else if (k < i && l > j) {
                        subMatrix.addElement(k, l - 1, this->getElement(k, l));
                    } else if (k > i && l < j) {
                        subMatrix.addElement(k - 1, l, this->getElement(k, l));
                    } else if (k > i && l > j) {
                        subMatrix.addElement(k - 1, l - 1, this->getElement(k, l));
                    }
                }
            }
            cofactorMatrix.addElement(i, j, pow(-1, i + j) * subMatrix.getDeterminant());
        }
    }
    // transpose cofactor matrix
    MatrixNumerical<T> transposeCofactorMatrix(this->getRows(), this->getCols(), 0);
    for (size_t i = 0; i < this->getRows(); i++) {
        for (size_t j = 0; j < this->getCols(); j++) {
            transposeCofactorMatrix.addElement(i, j, cofactorMatrix.getElement(j, i));
        }
    }
    // divide by determinant
    MatrixNumerical<T> inverseMatrix(this->getRows(), this->getCols(), 0);
    T determinant = this->getDeterminant();
    for (size_t i = 0; i < this->getRows(); i++) {
        for (size_t j = 0; j < this->getCols(); j++) {
            inverseMatrix.addElement(i, j, transposeCofactorMatrix.getElement(i, j) / determinant);
        }
    }
    return inverseMatrix;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator*(const MatrixNumerical<T> &matrix) const {
    if (this->getCols() != matrix.getRows()) {
        throw std::invalid_argument(
                "Number of columns of the first matrix must be equal to the number of rows of the second matrix");
    }
    MatrixNumerical<T> result(this->getRows(), matrix.getCols());
    for (size_t i = 0; i < this->getRows(); i++) {
        for (size_t j = 0; j < matrix.getCols(); j++) {
            for (size_t k = 0; k < this->getCols(); k++) {
                result.addElement(i, j, result.getElement(i, j) + this->getElement(i, k) * matrix.getElement(k, j));
            }
        }
    }
    return result;
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator-(const MatrixNumerical<T> &matrix) const {
    if (this->getRows() != matrix.getRows() || this->getCols() != matrix.getCols()) {
        throw std::invalid_argument("Matrices must have the same dimensions");
    }
    MatrixNumerical<T> result(this->getRows(), this->getCols());
    for (size_t i = 0; i < this->getRows(); i++) {
        for (size_t j = 0; j < this->getCols(); j++) {
            result.addElement(i, j, this->getElement(i, j) - matrix.getElement(i, j));
        }
    }
    return result;
}

template<typename T>
MatrixNumerical<T>::MatrixNumerical(size_t rows, size_t cols, T value) : MatrixBase<T>(rows, cols) {
    this->matrix = std::vector<std::vector<T>>(rows, std::vector<T>(cols, value));
}

template<typename T>
MatrixNumerical<T> MatrixNumerical<T>::operator+(const MatrixNumerical<T> &matrix) const {
    if (this->getRows() != matrix.getRows() || this->getCols() != matrix.getCols()) {
        throw std::invalid_argument("Matrices must have the same dimensions");
    }
    MatrixNumerical<T> result(this->getRows(), this->getCols());
    for (size_t i = 0; i < this->getRows(); i++) {
        for (size_t j = 0; j < this->getCols(); j++) {
            result.addElement(i, j, this->getElement(i, j) + matrix.getElement(i, j));
        }
    }
    return result;
}

template<typename T>
[[maybe_unused]] MatrixNumerical<T>::MatrixNumerical(size_t rows, size_t cols) : MatrixBase<T>(rows, cols) {
    this->matrix = std::vector<std::vector<T>>(rows, std::vector<T>(cols, 0));
}

template<typename T>
T MatrixNumerical<T>::getDeterminant() const {
    if (this->getRows() != this->getCols()) {
        throw std::invalid_argument("Matrix must be square");
    }
    if (this->getRows() == 1) {
        return this->getElement(0, 0);
    }
    if (this->getRows() == 2) {
        return this->getElement(0, 0) * this->getElement(1, 1) - this->getElement(0, 1) * this->getElement(1, 0);
    }
    T determinant = 0;
    for (size_t i = 0; i < this->getRows(); i++) {
        MatrixNumerical<T> subMatrix(this->getRows() - 1, this->getCols() - 1, 0);
        for (size_t j = 1; j < this->getRows(); j++) {
            for (size_t k = 0; k < this->getCols(); k++) {
                if (k < i) {
                    subMatrix.addElement(j - 1, k, this->getElement(j, k));
                } else if (k > i) {
                    subMatrix.addElement(j - 1, k - 1, this->getElement(j, k));
                }
            }
        }
        determinant += pow(-1, i) * this->getElement(0, i) * subMatrix.getDeterminant();
    }
    return determinant;
}

#endif //ECOLE_CPP_F_NUM_MATRIX_H
