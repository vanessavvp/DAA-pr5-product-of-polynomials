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


Monomial::Monomial() {
  coefficient_ = 0;
  exponent_ = 0;
}


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
std::ostream& operator<<(std::ostream &os, const Monomial &monomial) {
  if (monomial.getExponent() == 0) {
    os << monomial.getCoefficient();
  }
  else if (monomial.getExponent() == 1) {
    os << monomial.getCoefficient() << "x";
  }
  else  {
    os << monomial.getCoefficient() << "x" << "^" << monomial.getExponent();
  }

  return os;
}


std::istream& operator>>(std::istream &is, Monomial &monomial) {
  int newCoefficient;
  int newExponent;
  is >> newCoefficient >> newExponent;

  monomial.setCoefficient(newCoefficient);
  monomial.setExponent(newExponent);

  return is;
}


//Suma dos monommios de mismo exponente
Monomial operator+(const Monomial &x, const Monomial &y) {
  Monomial result;

  if (x.getExponent() == y.getExponent()) {
    result.setExponent(x.getExponent());
    result.setCoefficient(x.getCoefficient() + y.getCoefficient());
  }
  else {
    std::cout << "\nERROR: Two monomials cannot be added if they have different exponents.\n";
  }
  return result;
}


Monomial operator*(const Monomial &x, const Monomial &y) {
  Monomial result;

  result.setExponent(x.getExponent() + y.getExponent());
  result.setCoefficient(x.getCoefficient() * y.getCoefficient());
  return result;
}