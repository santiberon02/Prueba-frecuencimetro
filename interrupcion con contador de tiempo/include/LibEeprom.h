/*
 * LibEeprom.h
 *
 * Created: 19/10/2023 23:59:06
 *  Author: Usuario
 */ 
#include <avr/io.h>
unsigned int valoresSeteados[11];
char valAnterior;
int contadorEeprom;
#ifndef LIBEEPROM_H_
#define LIBEEPROM_H_

void guardarEeprom();
void leerEeprom();


#endif /* LIBEEPROM_H_ */