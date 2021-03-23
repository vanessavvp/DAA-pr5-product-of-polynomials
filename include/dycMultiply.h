/**
 * PROJECT HEADER
 * @file dycMultiply.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 22/03/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº5
 * Purpose: multiplication of polynomials using divide and conquer and
 *  classic algorithm (Strategy design pattern)
 */


#pragma once

#ifndef DIVIDE_AND_CONQUER_MULTIPLY_H
#define DIVIDE_AND_CONQUER_MULTIPLY_H

#include <cmath>

#include "./polynomial.h"
#include "./multiplyStrategy.h"
#pragma once

class DyCMultiply : public MultiplyStrategy {
  public:
    Polynomial polynomialMultiply(const Polynomial& polynomialA, const Polynomial& polynomialB);
};
#endif // !DIVIDE_AND_CONQUER_MULTIPLY_H