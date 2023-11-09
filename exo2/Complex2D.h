#pragma once

#include <string>

class Complex2D {
public:
    Complex2D();
    Complex2D(double real, double imaginary);
    [[maybe_unused]] explicit Complex2D(double value);
    [[maybe_unused]] Complex2D(const Complex2D& complex);

    [[maybe_unused]] void setReal(double real);

    [[maybe_unused]] void setImaginary(double imaginary);

    [[nodiscard]] double getReal() const;

    [[nodiscard]] double getImaginary() const;

    [[nodiscard]] Complex2D add(const Complex2D& complex) const;

    [[nodiscard]] Complex2D subtract(const Complex2D& complex) const;

    [[nodiscard]] Complex2D multiplyBy(const Complex2D& complex) const;

    [[nodiscard]] Complex2D divideBy(const Complex2D& complex) const;

    [[nodiscard]] Complex2D opposite() const;

    [[nodiscard]] Complex2D conjugate() const;

    [[nodiscard]] Complex2D inverse() const;

    [[nodiscard]] std::string toString() const;

    [[nodiscard]] double radius() const;
    [[nodiscard]] double argument() const;

    friend Complex2D operator+(const Complex2D& lhs, const Complex2D& rhs);
    friend Complex2D operator-(const Complex2D& lhs, const Complex2D& rhs);
    friend Complex2D operator*(const Complex2D& lhs, const Complex2D& rhs);
    friend Complex2D operator/(const Complex2D& lhs, const Complex2D& rhs);

    friend bool operator==(const Complex2D& lhs, const Complex2D& rhs);
    friend bool operator!=(const Complex2D& lhs, const Complex2D& rhs);
    friend bool operator<(const Complex2D& lhs, const Complex2D& rhs);
    friend bool operator>(const Complex2D& lhs, const Complex2D& rhs);

    void print() const;
    void print(const std::string& prefix) const;

private:
    double m_real, m_imaginary;
};