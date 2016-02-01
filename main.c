#include "MKL46Z4.h"
#include "main.h"
#include "lcd.h"
#include "buttons.h"
#include "timer.h"
#include "rtc.h"
#include "tpm.h"

uint8_t minutes;
uint8_t seconds;
uint8_t start_counting;
			
int main(void) {
	
    lcd_init();
    buttons_init();
    tpm_init();
		rtc_init();
		SystemCoreClockUpdate();
    time_reset(&minutes,&seconds);
	
	   while (1);
    };


