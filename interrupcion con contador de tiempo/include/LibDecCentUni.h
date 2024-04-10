/*
 * LibDecCentUni.h
 *
 * Created: 20/10/2023 11:22:00
 *  Author: Usuario
 */ 

#include <avr/io.h>

#ifndef LIBDECCENTUNI_H_
#define LIBDECCENTUNI_H_

int calculoCentena(int numeroC);
int calculoDecena(int numeroD);
int calculoUnidad(int numeroU);
void envioValorSeteado(int contcade);
int calculoMil(int numeroM,int divisor);
#endif /* LIBDECCENTUNI_H_ */