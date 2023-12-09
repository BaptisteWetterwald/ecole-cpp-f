//
// Created by Baptiste WETTERWALD on 09/12/2023.
//

#ifndef ECOLE_CPP_F_MATRIX_H
#define ECOLE_CPP_F_MATRIX_H

#include <vector>
#include <iostream>
#include <sstream>

template <typename T>
class MatrixBase {
private:
    size_t rows{};
    size_t cols{};

protected:
    std::vector<std::vector<T>> matrix;
public:
    MatrixBase(size_t rows, size_t cols);
    MatrixBase(const MatrixBase<T>& matrix);
    [[nodiscard]] size_t getRows() const;
    [[nodiscard]] size_t getCols() const;
    void addElement(size_t row, size_t col, T value);
    T getElement(size_t row, size_t col) const;
    void Display() const;
};

template<typename T>
MatrixBase<T>::MatrixBase(size_t rows, size_t cols) {
    this->rows = rows;
    this->cols = cols;
}


template<typename T>
MatrixBase<T>::MatrixBase(const MatrixBase<T>& matrix) {
    this->rows = matrix.getRows();
    this->cols = matrix.getCols();
    this->matrix = matrix.matrix;
}

template<typename T>
size_t MatrixBase<T>::getRows() const {
    return this->rows;
}

template<typename T>
size_t MatrixBase<T>::getCols() const {
    return this->cols;
}

template<typename T>
void MatrixBase<T>::addElement(size_t row, size_t col, T value) {
    this->matrix[row][col] = value;
}

template<typename T>
T MatrixBase<T>::getElement(size_t row, size_t col) const {
    return this->matrix[row][col];
}

template<typename T>
void MatrixBase<T>::Display() const {
    std::ostream& os = std::cout;
    for (size_t i = 0; i < this->rows; i++) {
        for (size_t j = 0; j < this->cols; j++) {
            os << this->matrix[i][j] << " ";
        }
        os << std::endl;
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const MatrixBase<T>& matrix) {
    matrix.Display(os);
    return os;
}

#endif //ECOLE_CPP_F_MATRIX_H
