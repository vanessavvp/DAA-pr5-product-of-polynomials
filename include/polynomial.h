/**
 * PROJECT HEADER
 * @file polynomial.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 22/03/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº5
 * Purpose: multiplication of polynomials using divide and conquer and
 *  classic algorithm (Strategy design pattern)
 */

#pragma once

#include <iostream>
#include <vector>

#include "./monomial.h"
#include "./multiplyStrategy.h"

class Polynomial {
  public:
    Polynomial();
    Polynomial(int terms);
    Polynomial(int coefficient[], const int terms); 
    Polynomial(std::vector<Monomial> polynomial, int begin, int end);
    std::vector<Monomial> getPolynomial() const;
    int getNumberOfTerms() const;
    Monomial getMonomial(int exponent) const;
    int getGrade() const;
    void generateRandomPolynomial();
    void setStrategy(MultiplyStrategy* strategy);
    void setMonomial(Monomial newMonomial, int i);
    Polynomial operator*(int value);

    friend std::ostream& operator<<(std::ostream &sout, Polynomial &p);
    friend Polynomial operator+(Polynomial x, Polynomial y);
    friend Polynomial operator-(Polynomial &x, Polynomial &y);
    friend Polynomial operator*(Polynomial& polynomA, Polynomial& polynomB);

  private:
    int grade_; // grade_ del polinomio
    int numberOfTerms_; // Número de términos en el polinomio
    std::vector<Monomial> polynomial_;
    MultiplyStrategy* strategy_;
};

