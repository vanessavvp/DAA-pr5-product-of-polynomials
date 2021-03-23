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

#include <chrono>
#include <ctime>

#include "../include/classicMultiply.h"
#include "../include/dycMultiply.h"
#include "../include/monomial.h"
#include "../include/polynomial.h"

int main(int argc, char* argv[]){
	if (argc != 2) {
		std::cout << "\nNúmero de parametros incorrecto. Encontrado " << argc-1 << " requerido 1."<< std::endl;
		exit(-1);
	} else {
    int size = atoi(argv[1]);
		Polynomial polynomialA(size);
    Polynomial polynomialB(size);
    Polynomial polynomialC(size);
    MultiplyStrategy* classicMultiply = new ClassicMultiply;

    auto start = std::chrono::system_clock::now();
    polynomialC = classicMultiply->polynomialMultiply(polynomialA, polynomialB);
    auto end = std::chrono::system_clock::now();

    std::cout << "\nAlgoritmos de multiplicación de polinomios\n";
    //std::cout << "\n\tPolinomios a multiplicar:";
    //std::cout << "\n-> Polinomio A: " << polynomialA;
    //std::cout << "-> Polinomio B: " << polynomialB;
    std::cout << "\nMultiplicación Algoritmo Clásico:\n"; //<< "-> Polinomio C: " << polynomialC;
    std::chrono::duration<float, std::nano> duration = end - start;
    std::cout << "TAMAÑO: " << size;
    std::cout << "\nTIEMPO: " << duration.count() * 1e-9<< " segundos" << std::endl;

    Polynomial polynomialD(size);
    MultiplyStrategy* dyvMultiply = new DyCMultiply;

    auto start2 = std::chrono::system_clock::now();
    //polynomialD = dyvMultiply->polynomialMultiply(polynomialA, polynomialB);
    auto end2 = std::chrono::system_clock::now();

    std::cout << "\nMultiplicación Algoritmo Divide y Vencerás:\n"; //<< "-> Polinomio C: \n"; //<< polynomialF;
    std::chrono::duration<float, std::nano> duration2 = end2 - start2;
    std::cout << "TAMAÑO: " << size << "\n";
    std::cout << "\nTIEMPO: "; //<< duration2.count() * 1e-9; << " segundos" << std::endl;
	}
  
}