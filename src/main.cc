/**
 * PROJECT HEADER
 * @file main.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 22/03/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº5
 * Purpose: multiplication of polynomials using divide and conquer and
 *  classic algorithm (Strategy design pattern)
 */

#include "../include/classicMultiply.h"
#include "../include/dycMultiply.h"
#include "../include/monomial.h"
#include "../include/polynomial.h"

int main () {
  int size = 4;
  Polynomial* polynomialA = new Polynomial(size);
  Polynomial* polynomialB = new Polynomial(size);
  Polynomial polynomialC(size);
  MultiplyStrategy* classicMultiply = new ClassicMultiply;
  //MultiplyStrategy* dyvMultiply = new DyVMultiply;
//
  polynomialC = classicMultiply->polynomialMultiply(polynomialA, polynomialB);
  std::cout << "\n\n" << polynomialA << polynomialB << polynomialC;

}