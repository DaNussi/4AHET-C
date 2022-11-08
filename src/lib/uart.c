#include "uart.h"


void uart_init_default(){
    DDRE &=~(1<<0);
    PORTE &=~(1<<0);
    DDRE |= (1<<1);
    //uart Initialisierung
    UCSR0A = 0;
    UBRR0 = 103;
    UCSR0B = (1<<RXCIE0)|(1<<RXEN0)|(1<<TXEN0);
    UCSR0C = (3<<UCSZ00);

}


void uart_transmit( unsigned char data )
{
/* Wait for empty transmit buffer */
    while ( !( UCSR0A & (1<<UDRE0)) );

/* Put data into buffer, sends the data */
    UDR0 = data;

}