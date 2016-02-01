#include "MKL46Z4.h"
#include "rtc.h"
#include "timer.h"
#include "main.h"
#include "lcd.h"

int rtc_count = 0;

void rtc_init()
{
    /* Clock for rtc */
    SIM->SCGC6 |= SIM_SCGC6_RTC_MASK;

    /* Ensure PTC1 is configured as RTC input clock */
    PORTC->PCR[1] &= ~PORT_PCR_MUX_MASK;
    PORTC->PCR[1] = PORT_PCR_MUX(1);

    /* Clear the OSC32KSEL field to select osc */
    SIM->SOPT1 &= ~SIM_SOPT1_OSC32KSEL_MASK;
	
    /* RTC_CLKIN selected as the ERCLK32K */
    SIM->SOPT1 |= SIM_SOPT1_OSC32KSEL(2);

    /* Set the oscillator enable bit */
    OSC0->CR |= OSC_CR_ERCLKEN_MASK;
	
    /* Clear any pending itnerupts */
    NVIC_ClearPendingIRQ(RTC_Seconds_IRQn);
    NVIC_EnableIRQ(RTC_Seconds_IRQn);
    NVIC_SetPriority(RTC_Seconds_IRQn, 2);

    /* Time seconds interrupt enable */
    RTC->IER |= RTC_IER_TSIE_MASK;
		
    RTC->TSR =  0;							// time counter enable
    RTC->SR |= RTC_SR_TCE_MASK;
}

void RTC_Seconds_IRQHandler()
{
				if(++rtc_count == 59){
					time_counting(&minutes,&seconds ,1);
					lcd_displaytime(minutes,seconds);
					rtc_count = 0;
} 
				if(rtc_count%2==0)						// flashing of dots between hours and minutes
				{   				
				SegLCD_Col_On();
				} 
				else			
					SegLCD_Col_Off();
}

