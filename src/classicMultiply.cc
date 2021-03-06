/**
 * PROJECT HEADER
 * @file classicMultiply.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 22/03/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº5
 * Purpose: multiplication of polynomials using divide and conquer and
 *  classic algorithm (Strategy design pattern)
 */

#include "../include/classicMultiply.h"
#include "../include/multiplyStrategy.h"
#include "../include/monomial.h"


Polynomial ClassicMultiply::polynomialMultiply(const Polynomial& polynomialA, const Polynomial& polynomialB) {
  int newPolynomial[polynomialA.getGrade() + polynomialB.getGrade() + 1];
  int size = sizeof(newPolynomial) / sizeof(newPolynomial[0]);

  for (int i = 0; i < (size + 1); i++) {
    newPolynomial[i] = 0;
  }

  for (int i = 0; i <= polynomialA.getGrade(); i++) {
    for (int j = 0; j <= polynomialB.getGrade(); j++) {
      newPolynomial[i + j] += (polynomialA.getMonomial(i) * polynomialB.getMonomial(j)).getCoefficient();
    } 
  }
  Polynomial result(newPolynomial, size);
  return result;
}