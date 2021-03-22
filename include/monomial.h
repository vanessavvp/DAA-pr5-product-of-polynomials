/**
 * PROJECT HEADER
 * @file monomial.h
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
#include <cmath>

class Monomial {
  public:
    Monomial(); 
    Monomial(int coefficient, int exponent); 
    ~Monomial();

    int evaluate(int value) const; //Evalua un monomio en un punto
    int getCoefficient() const; 
    int getExponent() const;
    void setCoefficient(int newCoefficient); 
    void setExponent(int newExponent);
    
  private:
    int coefficient_;
    int exponent_;
};

//Operadores de inserción y extracción
std::ostream& operator<<(std::ostream &sout, const Monomial &s);
std::istream& operator>>(std::istream &sin, Monomial &r);

//Suma dos monommios de mismo exponente
Monomial operator+(const Monomial &x, const Monomial &y);
Monomial operator*(const Monomial &x, const Monomial &y);
