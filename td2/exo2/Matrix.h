//
// Created by Baptiste  WETTERWALD on 16/11/2023.
//

#ifndef ECOLE_CPP_F_MATRIX_H
#define ECOLE_CPP_F_MATRIX_H

#include <vector>
#include <iostream>

template <typename T>
class Matrix {
protected:
    vector<vector<T>> data;
    size_t rows;
    size_t cols;

public:
    Matrix(size_t rows, size_t cols);
    Matrix(const Matrix<T>& m);
    ~Matrix();

    Matrix<T>& operator=(const Matrix<T>& m);
    Matrix<T>& operator+=(const Matrix<T>& m);
    Matrix<T>& operator-=(const Matrix<T>& m);
    Matrix<T>& operator*=(const Matrix<T>& m);
    Matrix<T>& operator*=(const T& s);
    Matrix<T>& operator/=(const T& s);

    Matrix<T> operator+(const Matrix<T>& m) const;
    Matrix<T> operator-(const Matrix<T>& m) const;
    Matrix<T> operator*(const Matrix<T>& m) const;
    Matrix<T> operator*(const T& s) const;
    Matrix<T> operator/(const T& s) const;

    Matrix<T> operator-() const;

    Matrix<T> transpose() const;

    T& operator()(size_t i, size_t j);
    const T& operator()(size_t i, size_t j) const;

    size_t getRows() const;
    size_t getCols() const;

    void display(std::ostream& os) const;
};

#endif //ECOLE_CPP_F_MATRIX_H

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
    data = vector<vector<T>>(rows, vector<T>(cols));
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> &m) : rows(m.rows), cols(m.cols) {
    data = vector<vector<T>>(rows, vector<T>(cols));
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j)
            data[i][j] = m.data[i][j];
    }
}

template<typename T>
Matrix<T>::~Matrix() {
    data.clear();
}

