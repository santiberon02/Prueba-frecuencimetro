/*
 * LibDecCentUni.c
 *
 * Created: 20/10/2023 11:22:24
 *  Author: Usuario
 */ 
#include "LibDecCentUni.h"
#include "LibUart.h"
#include "LibEeprom.h"
#define Mil 1000
#define Centena 100
#define Decena 10
#define Unidad 1
int salidaM;
int calculoMil(int numeroM,int divisor)
{
	switch (divisor)
	{case 1000:
		salidaM=numeroM;
		salidaM=salidaM/divisor;
		break;
		
	case 100:
	salidaM=numeroM%1000;
		salidaM=salidaM/100;
	break;
	
	case 10:
salidaM=numeroM%1000;
	salidaM=salidaM%100;
	salidaM=salidaM/10;
	break;
	
	case 1:
	if (numeroM>999)
	salidaM=numeroM%1000;
	salidaM=salidaM%100;
	salidaM=salidaM%10;
	break;
	
	}
	return salidaM;
}


int calculoCentena(int numeroC)
{
	int salida = (numeroC/100);
	return salida;
}

int calculoDecena(int numeroD)
{
	int salidaD=(numeroD%100);
	salidaD=(salidaD/10);
	return salidaD;
}

int calculoUnidad(int numeroU)
{
	int salidaU=(numeroU%100);
	salidaU=(salidaU%10);
	return salidaU;
}

void envioValorSeteado(int contcade){
	envioUart(calculoCentena(contcade)+48);
	envioUart(calculoDecena(contcade)+48);
	envioUart(calculoUnidad(contcade)+48);
}