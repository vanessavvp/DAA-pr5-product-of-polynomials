/**
 * PROJECT HEADER
 * @file multiplyStrategy.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 22/03/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº5
 * Purpose: multiplication of polynomials using divide and conquer and
 *  classic algorithm (Strategy design pattern)
 */
#pragma once

//#ifdef MULTIPLY_STRATEGY_H
//#define MULTIPLY_STRATEGY_H

#include <iostream>

#include "./polynomial.h"

class Polynomial;
class MultiplyStrategy {
  public:
    virtual ~MultiplyStrategy() {};
    virtual Polynomial polynomialMultiply(Polynomial* polynomialA, Polynomial* polynomialB) = 0;
};
//#endif // MULTIPLY_STRATEGY_H
