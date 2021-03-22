/**
 * PROJECT HEADER
 * @file monomial.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 22/03/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº5
 * Purpose: multiplication of polynomials using divide and conquer and
 *  classic algorithm (Strategy design pattern)
 */

#include "../include/monomial.h"


Monomial::Monomial() {}


Monomial::Monomial(int coefficient, int exponent) {
  coefficient_ = coefficient;
  exponent_    = exponent;
}


Monomial::~Monomial() {}


int Monomial::evaluate(int value) const {
  return coefficient_ * pow(value, getExponent());
} 


int Monomial::getCoefficient() const {
  return coefficient_;
} 


int Monomial::getExponent() const {
  return exponent_;
}


void Monomial::setCoefficient(int newCoefficient) {
  coefficient_ = newCoefficient;
} 


void Monomial::setExponent(int newExponent) {
  exponent_ = newExponent;
} 


//Operadores de inserción y extracción
std::ostream& operator<<(std::ostream &sout, const Monomial &s) {
  if (s.getExponent() == 0) {
    sout << s.getCoefficient();
  }
  else if (s.getExponent() == 1) {
    sout << s.getCoefficient() << "x";
  }
  else  {
    sout << s.getCoefficient() << "x" << "^" << s.getExponent();
  }

  return sout;
}


std::istream& operator>>(std::istream &sin, Monomial &r) {
  int newCoefficient;
  int newExponent;
  sin >> newCoefficient >> newExponent;

  r.setCoefficient(newCoefficient);
  r.setExponent(newExponent);

  return sin;
}


//Suma dos monommios de mismo exponente
Monomial operator+(const Monomial &x, const Monomial &y) {
  Monomial result;

  if (x.getExponent() == y.getExponent()) {
    result.setExponent(x.getExponent());
    result.setCoefficient(x.getCoefficient() + y.getCoefficient());
  }
  return result;
}


Monomial operator*(const Monomial &x, const Monomial &y) {
  Monomial result;

  result.setExponent(x.getExponent() + y.getExponent());
  result.setCoefficient(x.getCoefficient() * y.getCoefficient());
  return result;
}