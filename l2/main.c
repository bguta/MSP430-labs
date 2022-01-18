#include <msp430g2553.h> // dev board

// main program start
void main (void)
{
    WDTCTL = WDTPW + WDTHOLD ; // stop the watchdog timer (the watchdog timer is a
    //feature that allows the cpu to detect and recover from some kinds of software
    //bugs. We just want to disable it for now.

    P1DIR = 247; // Binary 11110111 All pins of port 1 output except P1.3
    P1OUT = 150;    // 9 ->  10010110 -> 150
    P1OUT = 148;    // set-next -> 1001 0 100
    P1OUT = 20;     // 1 ->  00010100 -> 20
    P1OUT = 21;     // set-next -> 0001 0 101
    P1OUT = 98;     // 6 ->  01100010 -> 98
    P1OUT = 98;     // 6 ->  01100000 -> 96
}
