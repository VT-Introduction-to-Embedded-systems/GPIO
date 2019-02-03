// This application uses button 1 and LED 1
// The operation is such that if you press the left button, as long as you keep the button pressed,
// the LED is on. As soon as you release the button, LED is off and stays off until the button is pressed again.
// This example uses Driverlib functions but does not use HAL functions.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

// According to the schematics on page 37 of the Launchpad User Guide,
// When a button is pressed, it is grounded (logic 0)
#define PRESSED 0

// This function initializes all the peripherals
void initialize();

int main(void)
{

    initialize();
    while (1) {
        // If the button is not pressed, keep the LED off
        if (GPIO_getInputPinValue(GPIO_PORT_P1, GPIO_PIN1) != PRESSED)
            GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0);
        else
            GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
    }
}

void initialize()
{

    // step 1: Stop watchdog timer
    // We do this at the beginning of all our programs for now.Later we learn more about it.
    WDT_A_hold(WDT_A_BASE);

    // step 2: Initializing LED1, which is on Pin 0 of Port P1
    // (from page 37 of the Launchpad User Guide)
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);

    // step 3: Initializing S1 (switch 1 or button 1),
    // which is on Pin1 of Port 1 (from page 37 of the Launchpad User Guide)
    GPIO_setAsInputPinWithPullUpResistor (GPIO_PORT_P1, GPIO_PIN1);
}


