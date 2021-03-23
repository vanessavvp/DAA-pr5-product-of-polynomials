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

#ifndef MONOMIAL_H
#define MONOMIAL_H

#include <iostream>
#include <cmath>
#pragma once

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

    //Operadores de inserción y extracción
    friend std::ostream& operator<<(std::ostream &sout, const Monomial &s);
    friend std::istream& operator>>(std::istream &sin, Monomial &r);

    //Suma dos monommios de mismo exponente
    friend Monomial operator+(const Monomial &x, const Monomial &y);
    friend Monomial operator*(const Monomial &x, const Monomial &y);
    
  private:
    int coefficient_;
    int exponent_;
};
#endif // !MONOMIAL_H