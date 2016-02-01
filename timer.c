#include "MKL46Z4.h"

#include "timer.h"


void time_counting(uint8_t *min, uint8_t *sec, uint8_t val)
{
		
    uint8_t m_i = (*sec+val)/60;
		*min = (*min+m_i)%24;
    *sec = (*sec+val)%60;
}


void time_reset(uint8_t *seconds, uint8_t *minutes)
{
    *minutes = 0;
    *seconds = 0;
}

