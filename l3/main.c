#include <msp430g2553.h>
unsigned int ms;
void main (void)
{
    WDTCTL = WDTPW + WDTHOLD ;

    P1DIR = 65; //Set P1.0 and P1.6 to output; binary 01000001 is 65
    //P1OUT = 64; //Set the output Pin P1.0 to low and P1.6 to high

    // case B
    P1OUT = 65; //Set the output Pin P1.0 and P1.6 to high

    for(;;) {
        //__delay_cycles (500000); //This function introduces 0.5 s delay
        // case A
        __delay_cycles (250000); // 0.25s s delay
        P1OUT = P1OUT ^ 65; //bitwise xor the output with 01000001
    }
}
