/*
 * main.c
 *
 * Created: 2/6/2021 2:48:25 PM
 *  Author: MrMat
 */ 

#include <xc.h>
#include <avr/io.h>
#include <util/delay.h>

void dzwon()
{
	PORTD=0b00000001;// ustaw stan wysoki
	_delay_ms(1000);// czekanie 1 sekundy
}

void reset()
{	
	PORTC=0b00000010;
	
	PORTD=0b00000000;// ustaw stan niski
	while(bit_is_set(PIND, 3));
	PORTA=0xff;
}

int main(void)
{

	DDRB=0b00000000; // ustawienia pinow w porcie B jako wejsc dla guzikow
	DDRA=0b11111111; //piny wyjsc dla wyswietlacza
    DDRD=0b00000001; // ustawia port D0 jako wyjscie	dla buzera
	PORTA=0xff; // ustawianie stanów wysokich na wyswietlaczu zeby nie bylo nic widac, wyswietlacz dziala na stanach niskich
	DDRC=0b01000011;
	
	while(1)
	{  		
		PORTC=0b00000001;
		
		while(PINB == 0b11111111);
		
		PORTC=0b01000000;
		
		if(bit_is_clear(PINB, 0))
		{
			PORTA=0b01111001;
			dzwon();
			reset();
		}
		
		if(bit_is_clear(PINB, 1))
		{			
			PORTA=0b00100100;
			dzwon();
			reset();
		}
		
		if(bit_is_clear(PINB, 2))
		{
			PORTA=0b00110000;
			dzwon();
			reset();
		}
		
		if(bit_is_clear(PINB, 3))
		{
			PORTA=0b00011001;
			dzwon();
			reset();
		}
		
		if(bit_is_clear(PINB, 4))
		{
			PORTA=0b00010010;			
			dzwon();
			reset();
		}
		
		if(bit_is_clear(PINB, 5))
		{
			PORTA=0b00000010;
			dzwon();
			reset();
		}
		
		if(bit_is_clear(PINB, 6))
		{
			PORTA=0b01111000;
			dzwon();
			reset();
		}
		
		if(bit_is_clear(PINB, 7))
		{
			PORTA=0b00000000;
			dzwon();
			reset();
		}		
	}
	return 0;
	
}