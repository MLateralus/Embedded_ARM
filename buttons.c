#include "MKL46Z4.h"

#include "buttons.h"
#include "timer.h"
#include "main.h"
#include "lcd.h"

#define SW1_PIN 3
#define SW3_PIN 12


void buttons_init()
{
    /* Enable port clocks */
    SIM->SCGC5 |=  SIM_SCGC5_PORTC_MASK;
		SIM->SCGC5 |=  SIM_SCGC5_PORTE_MASK;

    /* Configure pin as GPIO */
    PORTC->PCR[SW1_PIN] |= PORT_PCR_MUX(1);
    PORTC->PCR[SW3_PIN] |= PORT_PCR_MUX(1);
    /* Enable internal pullup resistor */
    PORTC->PCR[SW1_PIN] |= PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
    PORTC->PCR[SW3_PIN] |= PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
	
    /* Interrupt on falling edge */
    PORTC->PCR[SW1_PIN] |= PORT_PCR_IRQC(0x0A);
    PORTC->PCR[SW3_PIN] |= PORT_PCR_IRQC(0x0A);

    /* Enable IRQ */
    NVIC_ClearPendingIRQ(PORTC_PORTD_IRQn);
    NVIC_EnableIRQ(PORTC_PORTD_IRQn);
    NVIC_SetPriority(PORTC_PORTD_IRQn, 1);
}

void PORTC_PORTD_IRQHandler()
{
    /* Interrupt on SW1 detected */
    if (PORTC->PCR[SW1_PIN] & PORT_PCR_ISF_MASK) {
			
			  time_counting(&minutes, &seconds, 1);
        lcd_displaytime(minutes, seconds);
        /* Clear */
        PORTC->PCR[SW1_PIN] |= PORT_PCR_ISF_MASK;
    }
		/* Interrupt on SW3 detected */
	  if (PORTC->PCR[SW3_PIN] & PORT_PCR_ISF_MASK) {
			  time_counting(&minutes,&seconds, 60);
        lcd_displaytime(minutes,seconds);
        /* Clear */
        PORTC->PCR[SW3_PIN] |= PORT_PCR_ISF_MASK;
    }
	}
