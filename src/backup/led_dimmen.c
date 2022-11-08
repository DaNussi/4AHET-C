#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>


volatile int timer = 0;
volatile int step = 0;

/*-------------------------------------------
 * Interruptvektoren
 * ------------------------------------------ */

// External Interrupt Request 0   	_VECTOR(1)
ISR(INT0_vect) {




}
// External Interrupt Request 1   	_VECTOR(2)
ISR(INT1_vect) { }
// External Interrupt Request 1   	_VECTOR(3)
ISR(INT2_vect) { }
// External Interrupt Request 1   	_VECTOR(4)
ISR(INT3_vect) { }
// External Interrupt Request 1   	_VECTOR(5)
ISR(INT4_vect) { }
// External Interrupt Request 1   	_VECTOR(6)
ISR(INT5_vect) {


        switch (step) {
            case 0: //AUS
                step = 1;
            break;
            case 2: //EIN
                step = 3;
            break;
        }
}
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
// Timer0 Compare A  				_VECTOR(21)
ISR(TIMER0_COMPA_vect) {



}
// Timer0 Compare B  				_VECTOR(22)
ISR(TIMER0_COMPB_vect) { }
// Timer0 Overflow  				_VECTOR(23)
ISR(TIMER0_OVF_vect) {


        switch (step) {
            case 1: //WARTEN
                timer++;
            OCR0A = (timer*255l)/400l;
            if(timer > 400) {
                step = 2;
            }
            break;
            case 3: //WARTEN
                timer++;
            OCR0A = 255l-(timer*255l)/400l;
            if(timer > 400) {
                step = 0;
            }
            break;
            default: //RESET TIMER
                timer = 0;
            break;
        }

}
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


    //================= TIMER =================//

    TCCR0A = (1<<COM0A1)|(1<<WGM02)|(1<<WGM01)|(1<<WGM00);
    TCCR0B = 1<<CS02;
    TIMSK0 = 1<<TOIE0;
    OCR0A = 255;


    //================= BUTTON =================//

    EICRB = 1 << ISC51 | 1<< ISC50;
    EIMSK = 1 << INT5;



    //================= LED =================//

    DDRB = 0xff;
    TCCR1A = (1<<WGM10) | (1<<COM1A1);
    TCCR1B = (1<<CS11) | (1<<CS10);
    OCR1A = 128-1;

    DDRA = 0xff;
    PORTA = 0x00;


    sei();




    while(true) { };
}



