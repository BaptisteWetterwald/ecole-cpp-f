#include "Complex2D.h"
#include <iostream>
#include <format>
#include <string>
#include <valarray>

Complex2D::Complex2D() {
    m_real = m_imaginary = 0.0;
}

Complex2D::Complex2D(double real, double imaginary) :
        m_real{real},
        m_imaginary{imaginary} {}

[[maybe_unused]] Complex2D::Complex2D(const Complex2D &complex) :
        m_real{complex.getReal()},
        m_imaginary{complex.getImaginary()} {}

[[maybe_unused]] Complex2D::Complex2D(double value) :
        m_real{value},
        m_imaginary{value} {}

[[maybe_unused]] void Complex2D::setReal(double real) {
    m_real = real;
}

[[maybe_unused]] void Complex2D::setImaginary(double imaginary) {
    m_imaginary = imaginary;
}

double Complex2D::getReal() const {
    return m_real;
}

double Complex2D::getImaginary() const {
    return m_imaginary;
}

Complex2D Complex2D::add(const Complex2D& complex) const {
    return {m_real + complex.getReal(), m_imaginary + complex.getImaginary()};
}

Complex2D Complex2D::subtract(const Complex2D& complex) const {
    return {m_real - complex.getReal(), m_imaginary - complex.getImaginary()};
}

Complex2D Complex2D::multiplyBy(const Complex2D& complex) const {
    return {
        m_real * complex.getReal() - m_imaginary * complex.getImaginary(),
        m_real * complex.getImaginary() + m_imaginary * complex.getReal()
    };
}

Complex2D Complex2D::divideBy(const Complex2D& complex) const {
    if (!(complex.getReal() == 0.0 && complex.getImaginary() == 0.0)) {
        const double a = m_real;
        const double b = m_imaginary;
        const double c = complex.getReal();
        const double d = complex.getImaginary();

        const double real = (a * c + b * d) / (c * c + d * d);
        const double imaginary = (b * c - a * d) / (c * c + d * d);

        return {real, imaginary};
    }
    throw std::overflow_error("Cannot divide by 0.");
}

Complex2D Complex2D::opposite() const {
    return {-m_real, -m_imaginary};
}

Complex2D Complex2D::conjugate() const {
    return {m_real, -m_imaginary};
}

Complex2D Complex2D::inverse() const {
    if (m_real == 0.0 && m_imaginary == 0.0)
        throw std::overflow_error("Cannot divide by 0.");
    const double a = m_real;
    const double b = m_imaginary;

    return {a / (a * a + b * b), -b / (a * a + b * b)};
}

void Complex2D::print() const {
    std::cout << this->toString() << std::endl << std::endl;
}

void Complex2D::print(const std::string& prefix) const {
    std::cout << prefix << this->toString() << std::endl << std::endl;
}

std::string Complex2D::toString() const {
    std::string s;

    if (m_real == 0.0 && m_imaginary == 0.0) // a=0 & b=0
        s = "0";
    else {
        std::string sImaginary;

        const std::string sReal = m_real != 0.0 ? std::format("{:g}", m_real) : "";

        if (m_imaginary != 0.0) {
            if (m_imaginary != -1.f && m_imaginary != 1.f)
                sImaginary = (m_imaginary > 0 ? (m_real != 0 ? "+" : "") : "") + std::format("{:g}", m_imaginary);
            else
                sImaginary = m_imaginary == -1.f ? "-" : (m_real != 0.0 ? "+" : "");
            sImaginary += "i";
        }

        s = sReal + sImaginary;
    }

    return s;
}



Complex2D operator+(const Complex2D& lhs, const Complex2D& rhs) {
    return lhs.add(rhs);
}

Complex2D operator-(const Complex2D& lhs, const Complex2D& rhs) {
    return lhs.subtract(rhs);
}

Complex2D operator*(const Complex2D& lhs, const Complex2D& rhs) {
    return lhs.multiplyBy(rhs);
}

Complex2D operator/(const Complex2D& lhs, const Complex2D& rhs) {
    return lhs.divideBy(rhs);
}

bool operator==(const Complex2D& lhs, const Complex2D& rhs) {
    return lhs.getReal() == rhs.getReal() && lhs.getImaginary() == rhs.getImaginary();
}

bool operator!=(const Complex2D& lhs, const Complex2D& rhs) {
    return !(lhs == rhs);
}

bool operator<(const Complex2D& lhs, const Complex2D& rhs) {
    return lhs.getReal() < rhs.getReal() && lhs.getImaginary() < rhs.getImaginary();
}

bool operator>(const Complex2D& lhs, const Complex2D& rhs) {
    return lhs.getReal() > rhs.getReal() && lhs.getImaginary() > rhs.getImaginary();
}

double Complex2D::radius() const {
    return sqrt(m_real * m_real + m_imaginary * m_imaginary);
}

double Complex2D::argument() const {
    return atan2(m_imaginary, m_real);
}
