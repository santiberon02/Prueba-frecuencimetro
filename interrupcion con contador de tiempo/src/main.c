#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "LibUart.h"
#include "LibDecCentUni.h"
//sasas
void initInt1();
void initTimer1();
int t1=0;
int t2=0;
int contInt1=0;
int periodo=0;
int valoresSeteados;
#define Mil 1000
#define Centena 100
#define Decena 10
#define Unidad 1
int salidaM;
void envioUart(char datotx)
{
	while(!(UCSR0A&(1<<UDRE0)))
	{}
	UDR0=datotx;
}
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
int main (void){
DDRB=(1<<DDB5);
initInt1();
initTimer1();
//InitUart();
	UCSR0A=0;
	UCSR0B=(1<<RXEN0)|(1<<TXEN0);//|(1<<TXCIE0)|(1<<RXCIE0);
	UCSR0C=(1<<UCSZ01)|(1<<UCSZ00);
	UBRR0=103;

sei();
t1=5;
t2=20;
  while (1)
  {
//t1=t1/10;
//t2=t2/10;
periodo=t2-t1;
envioValorSeteado(periodo);
_delay_ms (100);
  }
}

ISR(INT1_vect)
{
     PINB|=(1<<PINB5);
     if (contInt1==0){
       t1=TCNT1;
       contInt1++;
     }
    if (contInt1==1)
    {
      t2=TCNT1;
      contInt1=0;
    }
}


void initInt1(){// Flanco descendente, PullUp, Pin D3
  EICRA=(1<<ISC11)|(1<<ISC10);
  EIMSK=(1<<INT1);
  DDRD=0;
 
}


void initTimer1(){ 

   TCCR1B=(1<<CS12);
   TCCR1C=0;
   TIMSK1=(1<<TOIE1);
   TCNT1=3036;


}


ISR(TIMER1_OVF_vect){
    PINB|=(1<<PINB5);
    TCNT1=3036;
}
