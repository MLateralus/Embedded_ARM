#ifndef TIMER_H
#define TIMER_H

#include "MKL46Z4.h"

void time_counting(uint8_t *min, uint8_t *sec, uint8_t val);
void time_reset(uint8_t *minutes, uint8_t *seconds);

#endif
