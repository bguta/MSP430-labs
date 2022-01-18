#include <msp430g2553.h> // dev board
//3.3 CMOS output levels
//High -> 3.3 - 2.4
//Between -> 2.4 - 0.5
//LOW -> 0.5 - 0


// main program start
void main(void) {
    WDTCTL = WDTPW + WDTHOLD; // Stop WDT
    ADC10CTL0 = ADC10SHT_2 + ADC10ON; // ADC10 On
    ADC10CTL1 = INCH_1; // input A1
    ADC10AE0 |= 2; // PA.1 ADC option select
    P1DIR |= 69 ; // 01000101 -> set P1.0, P1.2 and P1.6 to output direction

    for (;;) {
        ADC10CTL0 |= ENC + ADC10SC; // sampling and conversion start
        while (ADC10CTL1 &ADC10BUSY){  // ADC10 Busy?
            if (ADC10MEM > 744){ // Value greater than HIGH upper?
                P1OUT &= 1; // 0000 0001 set P1.2 and P1.6 off
                P1OUT |= 1; // 0000 0001 -> Set P1.0 LED on
            }
            else if(ADC10MEM > 155){ // Value greater than LOW upper?
                P1OUT &= 4; // 00000100 set P1.0 and P1.6 off
                P1OUT |= 4; // 00000100 -> Set P1.2 LED on
            }else{ 
                P1OUT &= 64; // 01000000 set P1.0 and P1.2 off
                P1OUT |= 64; // 01000000 -> Set P1.6 LED on
            }
        }    
        unsigned i;
        for (i = 65535; i > 0; i--); // Delay
    }
}
