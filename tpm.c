#include "tpm.h"
#include "main.h"
#include "timer.h"
#include "lcd.h"
void tpm_init()
{
	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;
    /* Select the MCGIRCLK as clock source for TPM counter clock */
	SIM->SOPT2 |= SIM_SOPT2_TPMSRC(3); 
    /* Enables the internal reference clock for use as MCGIRCLK */
	MCG->C1 |= MCG_C1_IRCLKEN_MASK;
    /* Select internal reference clock */
	MCG->C1 |= MCG_C1_IREFS_MASK;
    /* TPM counter operates in up counting mode */
	TPM0->SC &= ~TPM_SC_CPWMS_MASK;

    /* Prescaler divide by 64 */
	TPM0->SC |= TPM_SC_PS(6);
    /* Clear counter */
	TPM0->CNT = 0x00; 
    /* Count up to 500 */
	TPM0->MOD = 500;
    /* Output compare mode */
	TPM0->CONTROLS[0].CnSC |= TPM_CnSC_MSA_MASK;
    /* Enable IRQ */
	NVIC_ClearPendingIRQ(TPM0_IRQn);
	NVIC_EnableIRQ(TPM0_IRQn);
    /* Enable channel interrupt */
	TPM0->CONTROLS[0].CnSC |= TPM_CnSC_CHIE_MASK;
	
    /* TPM counter increments on every TPM counter clock */
	TPM0->SC |= TPM_SC_CMOD(1);
}

void TPM0_IRQHandler(){
	
	if (TPM0->STATUS & TPM_STATUS_CH0F_MASK && start_counting && !minutes && !seconds) {   
		TPM0->STATUS |= TPM_STATUS_CH0F_MASK;
	}
    else {      
    }
	TPM0->STATUS |= TPM_STATUS_TOF_MASK;
}
