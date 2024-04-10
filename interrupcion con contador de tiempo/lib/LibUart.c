/*
 * LibUart.c
 *
 * Created: 19/10/2023 14:39:12
 *  Author: Usuario
 */ 
#include "LibDecCentUni.h"
#include "LibUart.h"
// PROGMEM const char fraseNovalido [19]="Seleccion no valida";
// PROGMEM const char viveroSNB[16]="Vivero SNB_02\r";
// PROGMEM const char reseteototal[]="R-Restablecer nuevos valores\r";
// PROGMEM const char utilizarvalores[]="E-Utilizar estos valores\r";
// PROGMEM const char reseteoindividual[]="T-Cambiar seteos individuales\r";
// PROGMEM const char seleccionReset[24]="\rSeleccione los valores";
// PROGMEM const char seleccionAnterior[34]="\rSelecciono los valores anteriores";
// PROGMEM const char TSP[]="TSP: ";
// PROGMEM const char THYS[]="THYS: ";
// PROGMEM const char TKP[]="TKP: ";
// PROGMEM const char HASP[]="HASP: ";
// PROGMEM const char HAHYS[]="HAHYS: ";
// PROGMEM const char HSSP[]="HSSP: ";
// PROGMEM const char HSHYS[]="HSHYS: ";
// PROGMEM const char VVMAX[]="VVMAX: ";
// PROGMEM const char VVMIN[]="VVMIN: ";
// PROGMEM const char EMAX[]="EMAX: ";
// PROGMEM const char EMIN[]="EMIN: ";
void InitUart()	
{
	UCSR0A=0;
	UCSR0B=(1<<RXEN0)|(1<<TXEN0);//|(1<<TXCIE0)|(1<<RXCIE0);
	UCSR0C=(1<<UCSZ01)|(1<<UCSZ00);
	UBRR0=103;
}

char resepcionUart()
{
	while(!(UCSR0A&(1<<RXC0)))
	{
		
	}
	if(UCSR0A&(1<<RXC0))
	{
		datouart=UDR0;
	}
	return datouart;
}

void envioUart(char datotx)
{
	while(!(UCSR0A&(1<<UDRE0)))
	{}
	UDR0=datotx;
}

void envioFrase(char cadenaenviofrase[])
{	contadoruart=0;
	while (cadenaenviofrase[contadoruart]!='\0')
	{	
		/*char letraDeFrase=cadena[contadoruart];*/	
		envioUart(cadenaenviofrase[contadoruart]);
		contadoruart++;
	}
}

float resepcionDato()
{
	datonuevo=0;
	total=0;
	datonuevo = resepcionUart();
	envioUart(datonuevo);
	datonuevo=(datonuevo-48);
	total=datonuevo*100;
	datonuevo = resepcionUart();
	envioUart(datonuevo);
	datonuevo=(datonuevo-48);
	total=total+(datonuevo*10);
	datonuevo = resepcionUart();
	envioUart(datonuevo);
	datonuevo=(datonuevo-48);
	total=total+datonuevo;
	return total;
}

