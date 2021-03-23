/**
 * PROJECT HEADER
 * @file dycMultiply.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 22/03/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº5
 * Purpose: multiplication of polynomials using divide and conquer and
 *  classic algorithm (Strategy design pattern)
 */

#include "../include/dycMultiply.h"
#include "../include/multiplyStrategy.h"

Polynomial DyCMultiply::polynomialMultiply(const Polynomial& p, const Polynomial& q) {
  Polynomial result;
  int n = p.getNumberOfTerms();

  if (n == 1) {
    Monomial temp;
    temp = (p.getMonomial(0) * q.getMonomial(0));
    result.setMonomial(temp);
  } 
  else {
    int middle = n / 2;

    Polynomial pl(p.getPolynomial(), 0, middle);
    Polynomial ph(p.getPolynomial(), middle, n);
    Polynomial ql(q.getPolynomial(), 0, middle);
    Polynomial qh(q.getPolynomial(), middle, n);
    Polynomial rl, rh, rm, aux;

    rl = polynomialMultiply(pl, ql);
    rh = polynomialMultiply(ph, qh);
    rm = polynomialMultiply((pl + ph), (ql + qh));

    result = rl;
    aux = (rm - rl - rh) * middle;
    result = result + aux;

    if ((n % 2) == 0) {
      aux = (rh) * n;
    } else {
      aux = (rh) * (n - 1);
    }  

    result = result + aux;
  }
  return result;
}
