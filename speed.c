#include<avr/io.h>
#include<util/delay.h>
void init_adc()
{
	ADCSRA=ADCSRA|(0b00000001<<ADEN);
	ADCSRA=ADCSRA|(0b00000111);
	ADMUX=ADMUX|(0b00000001<<REFS0);
}
unsigned int read_adc(int p)
{
	ADMUX=ADMUX|p;
	ADCSRA=ADCSRA|0b00000001<<ADSC;
	while((ADCSRA & 0b00000001<<ADIF)==0);
	ADCSRA=ADCSRA|0b00000001<<ADIF;
	return ADC;
}

void main()
{
	DDRB=0b11111111;
	DDRC=0b00000000;
	PORTC=0b11111111;
	init_adc();
	unsigned int c,a,p,TON,TOFF,T;
	while(1)
	{
		p=read_adc(4);
		a=p/40;
		T=25.6;
		TOFF=a;
		TON=T-TOFF;
		c=PINC;
		if(c==0b11111010)
		{
			PORTB=0b00001010;
			_delay_ms(TON);
			PORTB=0b00000000;
			_delay_ms(TOFF);
		}
		if(c==0b11110101)
		{
			PORTB=0b00000101;
			_delay_ms(TON);
			PORTB=0b00000000;
			_delay_ms(TOFF);
		}
		if(c==0b11111001)
		{
			PORTB=0b00001001;
			_delay_ms(TON);
			PORTB=0b00000000;
			_delay_ms(TOFF);
		}
		if(c==0b11110110)
		{
			PORTB=0b00000110;
			_delay_ms(TON);
			PORTB=0b00000000;
			_delay_ms(TOFF);
		}
		if(c==0b11111011)
		{
			PORTB=0b00001000;
			_delay_ms(TON);
			PORTB=0b00000000;
			_delay_ms(TOFF);
		}
		if(c==0b11111110)
		{
			PORTB=0b00000010;
			_delay_ms(TON);
			PORTB=0b00000000;
			_delay_ms(TOFF);
		}
		if(c==0b11111111)
		{
			PORTB=0b00000000;
		}
	}
}
