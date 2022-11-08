#include "adc.h"



unsigned char adc_in_8bit(char channel){

    DDRF &=  ~(1<<0);

    PORTF&=  ~(1<<0);

    DIDR0 = 1<<ADC0D;

    ADMUX = (1<<REFS0)|(1<<ADLAR)|(0<<MUX0);

    ADCSRA= (1<<ADEN)|(1<<ADSC)|(1<<ADIF)|(3<<ADPS0);

    ADCSRB= 0;

    while ((ADCSRA&(1<<ADIF))==0);

    return ADCH;

}