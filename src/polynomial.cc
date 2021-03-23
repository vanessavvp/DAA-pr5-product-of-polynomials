/**
 * PROJECT HEADER
 * @file polynomial.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 22/03/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº5
 * Purpose: multiplication of polynomials using divide and conquer and
 *  classic algorithm (Strategy design pattern)
 */

#include "../include/polynomial.h"


Polynomial::Polynomial() {}


Polynomial::Polynomial(int coef[], const int terms) {
  numberOfTerms_ = terms;
  grade_ = (terms - 1); 

  for (int i = 0; i < numberOfTerms_; i++) {
    polynomial_.push_back(Monomial(coef[i], i));
  }
} 


Polynomial::Polynomial(int terms) {
  numberOfTerms_ = terms;
  grade_ = (terms - 1);
  generateRandomPolynomial();
}


void Polynomial::generateRandomPolynomial() {
  for (int i = 0; i < numberOfTerms_; i++) {
    int newCoefficient = rand() % 10;
    polynomial_.push_back(Monomial(newCoefficient, i));
  }
}


int Polynomial::getNumberOfTerms() {
  return numberOfTerms_;
}


int Polynomial::getGrade() {
  return grade_;
}


std::vector<Monomial> Polynomial::getPolynomial() {
  return polynomial_;
}


void Polynomial::setMonomial(Monomial newMonomial, int i) {
  polynomial_[i] = newMonomial;
}


int Polynomial::getMonomial(int index) {
  return polynomial_[index].getCoefficient();
}


void Polynomial::setZero(int size) {
  for (int i = numberOfTerms_; i < numberOfTerms_ + size; i++) {
    polynomial_.push_back(Monomial(0, i));
  }
  numberOfTerms_ += size;
}


std::ostream& operator<<(std::ostream &sout, Polynomial &p) {
  for (int i = 0; i < p.getPolynomial().size(); i++) {
    if (i == p.getPolynomial().size() - 1) {
      sout << p.getPolynomial()[i];
    }
    else {
      sout << p.getPolynomial()[i] << " + ";
    }
  }
  sout << std::endl;
  return sout;
}


Polynomial* operator+(const Polynomial& x, const Polynomial& y) {
  if (x.getNumberOfTerms() < y.getNumberOfTerms()) {
    x.setZero(y.getNumberOfTerms() - x.getNumberOfTerms());
  } 
  else if (x.getNumberOfTerms() > y.getNumberOfTerms()) {
    y.setZero(x.getNumberOfTerms() - y.getNumberOfTerms());
  }

  int coef[x.getNumberOfTerms()];
  for (int i = 0; i < x.getNumberOfTerms(); i++) {
    coef[i] = x.getPolynomial()[i].getCoefficient() + y.getPolynomial()[i].getCoefficient();
  }

  Polynomial* result = new Polynomial(coef, x.getNumberOfTerms());
  return result;
}


Polynomial* operator-(const Polynomial &x, const Polynomial &y) {
  if (x.getNumberOfTerms() < y.getNumberOfTerms()) {
    x.setZero(y.getNumberOfTerms() - x.getNumberOfTerms());
  } 
  else if (x.getNumberOfTerms() > y.getNumberOfTerms()) {
    y.setZero(x.getNumberOfTerms() - y.getNumberOfTerms());
  }

  int coef[x.getNumberOfTerms()];
  for (int i = 0; i < x.getNumberOfTerms(); i++) {
    coef[i] = x.getPolynomial()[i].getCoefficient() - y.getPolynomial()[i].getCoefficient();
  }

  Polynomial* result = new Polynomial(coef, x.getNumberOfTerms());
  return result;
}


Polynomial* operator*(Polynomial &x, int exp) {
  int coef[x.getNumberOfTerms() + exp];
  for (int i = 0; i < exp; i++) {
    coef[i] = 0;
  }
  for (int i = exp; i < (x.getNumberOfTerms() + exp); i++) {
    coef[i] = x.getPolynomial()[i - exp].getCoefficient();
  }

  Polynomial* result = new Polynomial(coef, x.getNumberOfTerms() + exp);
  return result;
}