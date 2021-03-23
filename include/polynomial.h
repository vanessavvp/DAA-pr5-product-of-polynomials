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
    // Constructores
    Polynomial(); // Constructor por defecto
    Polynomial(int coef[], const int terms); 
    Polynomial(int terms);
    void generateRandomPolynomial();
    int getNumberOfTerms() const;
    int getGrade() const;
    std::vector<Monomial> getPolynomial();
    void setMonomial(Monomial newMonomial, int i);
    int getMonomial(int index);
    void setZero(int size);

  private:
    int grade_; // grade_ del polinomio
    int numberOfTerms_; // Número de términos en el polinomio
    std::vector<Monomial> polynomial_;
    MultiplyStrategy* multiplyStrategy_;
};

std::ostream& operator<<(std::ostream &sout, Polynomial &p);
Polynomial* operator+(Polynomial x, Polynomial y);
Polynomial* operator-(Polynomial &x, Polynomial &y);
Polynomial* operator*(Polynomial &x, int exp);