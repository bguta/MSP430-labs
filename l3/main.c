#include <msp430g2553.h>
unsigned int ms;
void main (void)
{
    WDTCTL = WDTPW + WDTHOLD ;

    P1DIR = 65; //Set P1.0 and P1.6 to output; binary 01000001 is 65
    P1OUT = 65; //Set the output Pin P1.0 and P1.6 to high

    for(;;) {
        ms= 500;
        while (ms) {
            __delay_cycles (1000); //This function introduces 1000 microsecond delay
            ms--;
        } //decrement ms

        P1OUT = P1OUT ^ 65; //bitwise xor the output with 01000001
    }
}
