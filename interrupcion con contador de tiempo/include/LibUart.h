/*
 * LibUart.h
 *
 * Created: 19/10/2023 14:39:02
 *  Author: Usuario
 */ 
#include <avr/pgmspace.h>
#include <avr/io.h>

char datouart;
char cadenauart;
int contadoruart;
char letraDeFrase;
char datonuevo;
float total;
#ifndef LIBUART_H_
#define LIBUART_H_

void InitUart();	//Inicio uart sin interrupciones 
char resepcionUart();	//recibe de uart
void envioUart(char datotx);//envio un solo caracter
void envioFrase(char cadena[]);
float resepcionDato();

#endif /* LIBUART_H_ */