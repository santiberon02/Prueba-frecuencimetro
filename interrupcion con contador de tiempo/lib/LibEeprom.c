/*
 * LibEeprom.c
 *
 * Created: 19/10/2023 23:58:50
 *  Author: Usuario
 */ 
#include "LibEeprom.h"
#include <avr/eeprom.h>

void guardarEeprom()
{	contadorEeprom=0x80;
	int contadorCadena=0;
	while(contadorEeprom<0x8b)
	{
		if(valoresSeteados[contadorCadena]!=eeprom_read_byte((uint8_t*)contadorEeprom))
		{
			eeprom_write_byte((uint8_t*)contadorEeprom,valoresSeteados[contadorCadena]);
		}
		contadorCadena++;
		contadorEeprom++;
	}
}

void leerEeprom()
{
	contadorEeprom=0x80;
	int contadorCadena=0x0;
	while(contadorEeprom<0x8b)
	{
		valAnterior=eeprom_read_byte((uint8_t*)contadorEeprom);
		if (valoresSeteados[contadorCadena]!=valAnterior)
		{
			valoresSeteados[contadorCadena]=valAnterior;
		}
		contadorEeprom++;
		contadorCadena++;
	}
}