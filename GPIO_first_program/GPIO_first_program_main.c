
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>


// This function initializes all the peripherals
void initialize();

int main(void)
{

    initialize();

    while (1) {
        // If the button is not pressed, turn the LED off
        if ((P1IN & 0b00000010) != 0)
            P1OUT = P1OUT & 0b11111110;

        // otherwise, turn the LED on
        else
            P1OUT = P1OUT |  0b00000001;
    }
}

void initialize()
{

    // step 1: Stop watchdog timer
    // We do this at the beginning of all our programs for now.Later we learn more about it.
    WDT_A_hold(WDT_A_BASE);

    // step 2: Initializing LED1
    // According to table 12.1 on page 678 of MSP432 User guide,
    // to create an output, all you need is to write a 1 to PxDIR for the specific bit you want
    // A common mistake is to write P1DIR = LEFT_LED instead of P1DIR |= LEFT_LED;
    P1DIR |= 0b00000001;  // Same as P1DIR = P1DIR | LEFT_LED;


    // step 3: Initializing S1 (switch 1 or button 1)
    // According to the table on page 678 of MSP432 User guide,
    // to create an input with pull-up resistor, you need to do three things

    // step 3.1: write a 0 to PxDIR for the specific bit you want
    P1DIR &= 0b11111101;

    // step 3.2: write a 1 to PxREB for the specific bit you want
    P1REN |= 0b00000010;

    // step 3.3: write a 1 to PxOUT for the specific bit you want
    P1OUT |= 0b00000010;  // select pull-up
}
