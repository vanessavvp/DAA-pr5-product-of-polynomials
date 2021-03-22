/**
 * PROJECT HEADER
 * @file dyvMultiply.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 22/03/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº5
 * Purpose: multiplication of polynomials using divide and conquer and
 *  classic algorithm (Strategy design pattern)
 */


#pragma once

#include <cmath>

#include "./polynomial.h"
#include "./multiplyStrategy.h"

class Polynomial;
class DyCMultiply : public MultiplyStrategy {
  public:
    Polynomial polynomialMultiply(Polynomial& polynomialA, Polynomial& polynomialB);
};