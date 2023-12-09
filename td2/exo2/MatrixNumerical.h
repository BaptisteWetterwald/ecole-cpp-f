//
// Created by Baptiste  WETTERWALD on 16/11/2023.
//

#ifndef ECOLE_CPP_F_MATRIXNUMERICAL_H
#define ECOLE_CPP_F_MATRIXNUMERICAL_H


template <typename T>
class MatrixNumerical {
public:
    MatrixNumerical(int rows, int cols);
    MatrixNumerical(const MatrixNumerical<T>& m);
    ~MatrixNumerical();

    MatrixNumerical<T>& operator=(const MatrixNumerical<T>& m);
    MatrixNumerical<T>& operator+=(const MatrixNumerical<T>& m);
    MatrixNumerical<T>& operator-=(const MatrixNumerical<T>& m);
    MatrixNumerical<T>& operator*=(const MatrixNumerical<T>& m);
    MatrixNumerical<T>& operator*=(const T& s);
    MatrixNumerical<T>& operator/=(const T& s);

    MatrixNumerical<T> operator+(const MatrixNumerical<T>& m) const;
    MatrixNumerical<T> operator-(const MatrixNumerical<T>& m) const;
    MatrixNumerical<T> operator*(const MatrixNumerical<T>& m) const;
    MatrixNumerical<T> operator*(const T& s) const;
    MatrixNumerical<T> operator/(const T& s) const;

    MatrixNumerical<T> operator-() const;

    MatrixNumerical<T> transpose() const;

    T& operator()(int i, int j);
    const T& operator()(int i, int j) const;

    int rows()
};


#endif //ECOLE_CPP_F_MATRIXNUMERICAL_H
