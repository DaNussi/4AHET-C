#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>


volatile unsigned int speed = 0;		//Blink Geschwindigkeit geht von 0 bis 5
volatile unsigned int counter = 0;		//Zählt wie oft der Timer einen Interrupt auslöst. Resetet bei >= 50

 
/*-------------------------------------------
 * Interruptvektoren
 * ------------------------------------------ */
// External Interrupt Request 0   	_VECTOR(1)
ISR(INT0_vect) { }
// External Interrupt Request 1   	_VECTOR(2)
ISR(INT1_vect) { }
// External Interrupt Request 1   	_VECTOR(3)
ISR(INT2_vect) {				//Dieser Interrupt wird ausgelöst wenn der Knopf gedrückt wurde
	speed++;					//Erhöhen der Geschwindigkeit
	if(speed >= 5) speed = 0;	//Limitiren/Zurücksetzen der Geschwindikeit
	OCR0A = 54*speed;			//Setzen der OCR0A Registers mit hilfe der Geschwindikeit
}
// External Interrupt Request 1   	_VECTOR(4)
ISR(INT3_vect) { }
// External Interrupt Request 1   	_VECTOR(5)
ISR(INT4_vect) { }
// External Interrupt Request 1   	_VECTOR(6)
ISR(INT5_vect) { }
// External Interrupt Request 1   	_VECTOR(7)
ISR(INT6_vect) { }
// External Interrupt Request 1   	_VECTOR(8)
ISR(INT7_vect) { }
// External Interrupt Pin Change 0  _VECTOR(9)
ISR(PCINT0_vect) { }
// External Interrupt Pin Change 1  _VECTOR(10)
ISR(PCINT1_vect) { }
// External Interrupt Pin Change 2  _VECTOR(11)
ISR(PCINT2_vect) { }
// Watchdog Time-out   				_VECTOR(12)
ISR(WDT_vect) { }
// SPI Seriel Transfer Complete     _VECTOR(24)
ISR(SPI_STC_vect) { }
// Analog Comperator 				_VECTOR(28)
ISR(ANALOG_COMP_vect) { }
// ADC Conversion Complete 			_VECTOR(29)
ISR(ADC_vect) { }
// EEPROM Ready						_VECTOR(30)
ISR(EE_READY_vect) { }
// 2-wire Serial Interface 			_VECTOR(39)
ISR(TWI_vect) { }
// Store Program Memory Read        _VECTOR(40)
ISR (SPM_READY_vect) { }

ISR(TIMER0_COMPA_vect) {
	counter++;				//Zähler um eins erhöhen
	if(counter >= 50) {
		PORTB ^= 1<<5;		//Toggeln von PB5
		counter = 0;		//Zurücksetzen des Zählers
	}
}
// Timer0 Compare B  				_VECTOR(22)
ISR(TIMER0_COMPB_vect) { }
// Timer0 Overflow  				_VECTOR(23)
ISR(TIMER0_OVF_vect) { }
// Timer1 Capture Event  			_VECTOR(16)
ISR(TIMER1_CAPT_vect) { }
// Timer1 Compare A  				_VECTOR(17)
ISR(TIMER1_COMPA_vect) { }
// Timer1 Compare B  				_VECTOR(18)
ISR(TIMER1_COMPB_vect) { }
// Timer1 Compare C  				_VECTOR(19)
ISR(TIMER1_COMPC_vect) { }
// Timer1 Overflow  				_VECTOR(20)
ISR(TIMER1_OVF_vect) { }
// Timer2 Compare A  				_VECTOR(13)
ISR(TIMER2_COMPA_vect) { }
// Timer2 Compare B  				_VECTOR(14)
ISR(TIMER2_COMPB_vect) { }
// Timer2 Overflow  				_VECTOR(15)
ISR(TIMER2_OVF_vect) { }
// Timer3 Capture Event  			_VECTOR(31)
ISR(TIMER3_CAPT_vect) { }
// Timer3 Compare A  				_VECTOR(32)
ISR(TIMER3_COMPA_vect) { }
// Timer3 Compare B  				_VECTOR(33)
ISR(TIMER3_COMPB_vect) { }
// Timer3 Compare C  				_VECTOR(34)
ISR(TIMER3_COMPC_vect) { }
// Timer3 Overflow  				_VECTOR(35)
ISR(TIMER3_OVF_vect) { }
// Timer4 Capture Event  			_VECTOR(41)
ISR(TIMER4_CAPT_vect) { }
// Timer4 Compare A  				_VECTOR(42)
ISR(TIMER4_COMPA_vect) { }
// Timer4 Compare B  				_VECTOR(43)
ISR(TIMER4_COMPB_vect) { }
// Timer4 Compare C  				_VECTOR(44)
ISR(TIMER4_COMPC_vect) { }
// Timer4 Overflow  				_VECTOR(45)
ISR(TIMER4_OVF_vect) { }
// Timer5 Capture Event  			_VECTOR(46)
ISR(TIMER5_CAPT_vect) { }
// Timer5 Compare A  				_VECTOR(47)
ISR(TIMER5_COMPA_vect) { }
// Timer5 Compare B  				_VECTOR(48)
ISR(TIMER5_COMPB_vect) { }
// Timer5 Compare C  				_VECTOR(49)
ISR(TIMER5_COMPC_vect) { }
// Timer5 Overflow  				_VECTOR(50)
ISR(TIMER5_OVF_vect) { }
// USART0 Rx Complete 				_VECTOR(25)
ISR(USART0_RX_vect) { }
// USART0 Data Register Empty  		_VECTOR(26)
ISR(USART0_UDRE_vect) { }
// USART0 Tx Complete 				_VECTOR(27)
ISR(USART0_TX_vect) { }
// USART1 Rx Complete 				_VECTOR(36)
ISR(USART1_RX_vect) { }
// USART1 Data Register Empty  		_VECTOR(37)
ISR(USART1_UDRE_vect) { }
// USART1 Tx Complete 				_VECTOR(38)
ISR(USART1_TX_vect) { }
// USART2 Rx Complete 				_VECTOR(51)
ISR(USART2_RX_vect) { }
// USART2 Data Register Empty  		_VECTOR(52)
ISR(USART2_UDRE_vect) { }
// USART2 Tx Complete 				_VECTOR(53)
ISR(USART2_TX_vect) { }
// USART3 Rx Complete 				_VECTOR(54)
ISR(USART3_RX_vect) { }
// USART3 Data Register Empty  		_VECTOR(55)
ISR(USART3_UDRE_vect) { }
// USART3 Tx Complete 				_VECTOR(56)
ISR(USART3_TX_vect) { }



int main() 
{

	DDRB = 1<<5;

	EICRA = 1 << ISC01| 1<< ISC00;
	EIMSK = 1 << INT2;


	OCR0A = 0xff;
	TCCR0A = 1<<WGM01;
	TCCR0B = 1<< CS02 | 1<<CS00;
	TIMSK0 = 1<<OCIE0A | 1<<OCIE0A | 1<<TOIE0;

	
	

	sei();

	while(1) { };

}
