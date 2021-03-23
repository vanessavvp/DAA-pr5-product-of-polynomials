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


Polynomial::Polynomial(int coefficient[], const int terms) {
  numberOfTerms_ = terms;
  grade_ = (terms - 1); 
  strategy_ = NULL;
  polynomial_.resize(numberOfTerms_);

  for (int i = 0; i < numberOfTerms_; i++) {
    polynomial_[i].setCoefficient(coefficient[i]);
    polynomial_[i].setExponent(i);
  }
} 


Polynomial::Polynomial(int terms) {
  numberOfTerms_ = terms;
  grade_ = (terms - 1);
  strategy_ = NULL;
  generateRandomPolynomial();
}


Polynomial::Polynomial(std::vector<Monomial> polynomial, int begin, int end) {
  strategy_ = NULL;
  polynomial_.resize(end - begin);
  for (int i = 0; i < (end - begin); i++) {
    polynomial_[i].setCoefficient(polynomial[i + begin].getCoefficient());
    polynomial_[i].setExponent(i);
  }
}


void Polynomial::setStrategy(MultiplyStrategy* strategy) {
  strategy_ = strategy;
}


void Polynomial::generateRandomPolynomial() {
  for (int i = 0; i < numberOfTerms_; i++) {
    int newCoefficient = rand() % 10;
    polynomial_.push_back(Monomial(newCoefficient, i));
  }
}


int Polynomial::getNumberOfTerms() const{
  return polynomial_.size();
}


int Polynomial::getGrade() const {
  return (polynomial_.size() - 1);
}


std::vector<Monomial> Polynomial::getPolynomial() const {
  return polynomial_;
}


void Polynomial::setMonomial(Monomial newMonomial, int i) {
  polynomial_[i] = newMonomial;
}


Monomial Polynomial::getMonomial(int exponent) const {
  return polynomial_[exponent];
}


std::ostream& operator<<(std::ostream &os, Polynomial &p) {
  for (int i = 0; i < p.getPolynomial().size(); i++) {
    os << p.polynomial_[i] << " ";
    if (i != p.getGrade()) {
      os << "+ ";
    }
  }
  os << std::endl;
  return os;
}


Polynomial operator+(const Polynomial& polynomA, const Polynomial& polynomB) {
  int polynomAGrade = polynomA.getGrade();
  int polynomBGrade = polynomB.getGrade();
  int maxSize = std::max(polynomAGrade, polynomBGrade) + 1 ;
  int temp[maxSize];
  for (int i = 0; i < maxSize; i++) {
    temp[i] = 0;
  }
  for (int i = 0; i <= polynomAGrade; i++) {
    temp[i] = polynomA.getMonomial(i).getCoefficient();
  }
  for (int i = 0; i <= polynomBGrade; i++) {
    temp[i] += polynomB.getMonomial(i).getCoefficient();
  }
  Polynomial result(temp, maxSize);
  return result;
}


Polynomial operator-(const Polynomial &polynomA, const Polynomial &polynomB) {
  int polynomAGrade = polynomA.getGrade();
  int polynomBGrade = polynomB.getGrade();
  int maxSize = std::max(polynomAGrade, polynomBGrade) + 1 ;
  int temp[maxSize];
  for (int i = 0; i < maxSize; i++) {
    temp[i] = 0;
  }
  for (int i = 0; i <= polynomAGrade; i++) {
    temp[i] = polynomA.getMonomial(i).getCoefficient();
  }
  for (int i = 0; i <= polynomBGrade; i++) {
    temp[i] -= polynomB.getMonomial(i).getCoefficient();
  }
  Polynomial result(temp, maxSize);
  return result;
}


Polynomial Polynomial::operator*(int value) {
  Monomial temp;
  polynomial_.insert(polynomial_.begin(), value, temp);
  for (int i = 0; i <= getGrade(); i++) {
    polynomial_[i].setExponent(i);
  }
  return *this;
}

Polynomial operator*(Polynomial& polynomA, Polynomial& polynomB) {
  return polynomA.strategy_->polynomialMultiply(polynomA, polynomB);
}