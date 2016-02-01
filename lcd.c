#include "MKL46Z4.h"

#include "lcd.h"

const static uint8_t LCD_Frontplane_Pin[LCD_NUM_FRONTPLANE_PINS] = {
    LCD_FRONTPLANE0, LCD_FRONTPLANE1, LCD_FRONTPLANE2, LCD_FRONTPLANE3,
    LCD_FRONTPLANE4, LCD_FRONTPLANE5, LCD_FRONTPLANE6, LCD_FRONTPLANE7
};

void lcd_init(void)
{
    SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK |
        SIM_SCGC5_PORTC_MASK |
        SIM_SCGC5_PORTD_MASK |
        SIM_SCGC5_PORTE_MASK |
        SIM_SCGC5_SLCD_MASK;

    LCD->GCR |= LCD_GCR_PADSAFE_MASK;
    LCD->GCR &= ~LCD_GCR_LCDEN_MASK;

    PORTB->PCR[7] = PORT_PCR_MUX(0);
    PORTB->PCR[8] = PORT_PCR_MUX(0);
    PORTB->PCR[10] = PORT_PCR_MUX(0);
    PORTB->PCR[11] = PORT_PCR_MUX(0);
    PORTB->PCR[21] = PORT_PCR_MUX(0);
    PORTB->PCR[22] = PORT_PCR_MUX(0);
    PORTB->PCR[23] = PORT_PCR_MUX(0);
    PORTC->PCR[17] = PORT_PCR_MUX(0);
    PORTC->PCR[18] = PORT_PCR_MUX(0);
    PORTD->PCR[0] = PORT_PCR_MUX(0);
    PORTE->PCR[4] = PORT_PCR_MUX(0);
    PORTE->PCR[5] = PORT_PCR_MUX(0);

    LCD->GCR = LCD_GCR_RVTRIM(0x00) |
        LCD_GCR_CPSEL_MASK |
        LCD_GCR_LADJ(0x03) |
        LCD_GCR_VSUPPLY_MASK |
        LCD_GCR_ALTDIV(0x00) |
        LCD_GCR_SOURCE_MASK |
        LCD_GCR_LCLK(0x01) |
        LCD_GCR_DUTY(0x03);

    LCD->AR = LCD_AR_BRATE(0x00);
    LCD->FDCR = 0x00000000;

    LCD->PEN[0] = LCD_PEN_PEN(1u<<7u) |
        LCD_PEN_PEN(1u<<8u) |
        LCD_PEN_PEN(1u<<10u) |
        LCD_PEN_PEN(1u<<11u) |
        LCD_PEN_PEN(1u<<17u) |
        LCD_PEN_PEN(1u<<18u) |
        LCD_PEN_PEN(1u<<19u);

    LCD->PEN[1] = LCD_PEN_PEN(1u<<5u) |
        LCD_PEN_PEN(1u<<6u) |
        LCD_PEN_PEN(1u<<8u) |
        LCD_PEN_PEN(1u<<20u) |
        LCD_PEN_PEN(1u<<21u);
    LCD->BPEN[0] = LCD_BPEN_BPEN(1u<<18u) |
        LCD_BPEN_BPEN(1u<<19u);
    LCD->BPEN[1] = LCD_BPEN_BPEN(1u<<8u) |
        LCD_BPEN_BPEN(1u<<20u);
    LCD->WF[0] = LCD_WF_WF0(0x00) |
        LCD_WF_WF1(0x00) |
        LCD_WF_WF2(0x00) |
        LCD_WF_WF3(0x00);
    LCD->WF[1] = LCD_WF_WF4(0x00) |
        LCD_WF_WF5(0x00) |
        LCD_WF_WF6(0x00) |
        LCD_WF_WF7(0x00) ;
    LCD->WF[2] = LCD_WF_WF8(0x00) |
        LCD_WF_WF9(0x00) |
        LCD_WF_WF10(0x00) |
        LCD_WF_WF11(0x00);
    LCD->WF[3] = LCD_WF_WF12(0x00) |
        LCD_WF_WF13(0x00) |
        LCD_WF_WF14(0x00) |
        LCD_WF_WF15(0x00);
    LCD->WF[4] = LCD_WF_WF16(0x00) |
        LCD_WF_WF17(0x00) |
        LCD_WF_WF18(0x88) |
        LCD_WF_WF19(0x44);
    LCD->WF[5] = LCD_WF_WF20(0x00) |
        LCD_WF_WF21(0x00) |
        LCD_WF_WF22(0x00) |
        LCD_WF_WF23(0x00);
    LCD->WF[6] = LCD_WF_WF24(0x00) |
        LCD_WF_WF25(0x00) |
        LCD_WF_WF26(0x00) |
        LCD_WF_WF27(0x00);
    LCD->WF[7] = LCD_WF_WF28(0x00) |
        LCD_WF_WF29(0x00) |
        LCD_WF_WF30(0x00) |
        LCD_WF_WF31(0x00);
    LCD->WF[8] = LCD_WF_WF32(0x00) |
        LCD_WF_WF33(0x00) |
        LCD_WF_WF34(0x00) |
        LCD_WF_WF35(0x00);
    LCD->WF[9] = LCD_WF_WF36(0x00) |
        LCD_WF_WF37(0x00) |
        LCD_WF_WF38(0x00) |
        LCD_WF_WF39(0x00);
    LCD->WF[10] = LCD_WF_WF40(0x11) |
        LCD_WF_WF41(0x00) |
        LCD_WF_WF42(0x00) |
        LCD_WF_WF43(0x00);
    LCD->WF[11] = LCD_WF_WF44(0x00) |
        LCD_WF_WF45(0x00) |
        LCD_WF_WF46(0x00) |
        LCD_WF_WF47(0x00);
    LCD->WF[12] = LCD_WF_WF48(0x00) |
        LCD_WF_WF49(0x00) |
        LCD_WF_WF50(0x00) |
        LCD_WF_WF51(0x00);
    LCD->WF[13] = LCD_WF_WF52(0x22) |
        LCD_WF_WF53(0x00) |
        LCD_WF_WF54(0x00) |
        LCD_WF_WF55(0x00);
    LCD->WF[14] = LCD_WF_WF56(0x00) |
        LCD_WF_WF57(0x00) |
        LCD_WF_WF58(0x00) |
        LCD_WF_WF59(0x00);
    LCD->WF[15] = LCD_WF_WF60(0x00) |
        LCD_WF_WF61(0x00) |
        LCD_WF_WF62(0x00) |
        LCD_WF_WF63(0x00);

    LCD->GCR &= ~LCD_GCR_PADSAFE_MASK;
    LCD->GCR |= LCD_GCR_LCDEN_MASK;
}

void SegLCD_Set(uint8_t Value,uint8_t Digit)
{
    if (Digit > 4) {
        SegLCD_DisplayError(0x01);
    }
    else {
        switch (Value) {
        case 0x00:
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-2)]] =
                (LCD_SEG_D | LCD_SEG_E |LCD_SEG_F);
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-1)]] =
                (LCD_SEG_A | LCD_SEG_B | LCD_SEG_C);
            break;
        case 0x01:
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-2)]] =
                (LCD_CLEAR);
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-1)]] =
                (LCD_SEG_B | LCD_SEG_C);
            break;
        case 0x02:
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-2)]] =
                (LCD_SEG_D | LCD_SEG_E | LCD_SEG_G);
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-1)]] =
                (LCD_SEG_A | LCD_SEG_B);
            break;
        case 0x03:
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-2)]] =
                (LCD_SEG_D | LCD_SEG_G);
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-1)]] =
                (LCD_SEG_A | LCD_SEG_B | LCD_SEG_C);
            break;
        case 0x04:
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-2)]] =
                (LCD_SEG_F | LCD_SEG_G);
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-1)]] =
                (LCD_SEG_B | LCD_SEG_C);
            break;
        case 0x05:
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-2)]] =
                (LCD_SEG_D | LCD_SEG_F | LCD_SEG_G);
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-1)]] =
                (LCD_SEG_A | LCD_SEG_C);
            break;
        case 0x06:
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-2)]] =
                (LCD_SEG_D | LCD_SEG_E | LCD_SEG_F | LCD_SEG_G);
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-1)]] =
                (LCD_SEG_A | LCD_SEG_C);
            break;
        case 0x07:
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-2)]] =
                (LCD_CLEAR);
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-1)]] =
                (LCD_SEG_A | LCD_SEG_B | LCD_SEG_C);
            break;
        case 0x08:
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-2)]] =
                (LCD_SEG_D | LCD_SEG_E | LCD_SEG_F | LCD_SEG_G);
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-1)]] =
                (LCD_SEG_A | LCD_SEG_B | LCD_SEG_C);
            break;
        case 0x09:
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-2)]] =
                (LCD_SEG_F | LCD_SEG_G);
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-1)]] =
                (LCD_SEG_A | LCD_SEG_B | LCD_SEG_C);
            break;
        case 0x0A:
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-2)]] =
                (LCD_SEG_E | LCD_SEG_F | LCD_SEG_G);
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-1)]] =
                (LCD_SEG_A | LCD_SEG_B | LCD_SEG_C);
            break;
        case 0x0B:
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-2)]] =
                (LCD_SEG_D | LCD_SEG_E | LCD_SEG_F | LCD_SEG_G);
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-1)]] =
                LCD_SEG_C;
            break;
        case 0x0C:
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-2)]] =
                (LCD_SEG_D | LCD_SEG_E | LCD_SEG_F);
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-1)]] =
                LCD_SEG_A;
            break;
        case 0x0D:
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-2)]] =
                (LCD_SEG_D | LCD_SEG_E | LCD_SEG_G);
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-1)]] =
                LCD_SEG_B | LCD_SEG_C;
            break;
        case 0x0E:
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-2)]] =
                (LCD_SEG_D | LCD_SEG_E | LCD_SEG_F | LCD_SEG_G);
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-1)]] =
                LCD_SEG_A;
            break;
        case 0x0F:
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-2)]] =
                (LCD_SEG_E | LCD_SEG_F | LCD_SEG_G);
            LCD->WF8B[LCD_Frontplane_Pin[((2*Digit)-1)]] =
                LCD_SEG_A;
            break;
        }
    }
}

void lcd_displaytime(uint8_t Value1, uint8_t Value2)
{
    if ((Value1 > 99) | (Value2 > 99)) {
        SegLCD_DisplayError(0x10);
    }
    else {
        SegLCD_Set(Value1/10, 1);
        SegLCD_Set(Value1 % 10, 2);
        SegLCD_Set(Value2/10, 3);
        SegLCD_Set(Value2 % 10, 4);
        SegLCD_Col_On();
    }
}

void SegLCD_DisplayError(uint8_t ErrorNum)
{
    LCD->WF8B[LCD_FRONTPLANE0] = (LCD_SEG_D | LCD_SEG_E | LCD_SEG_F | LCD_SEG_G);
    LCD->WF8B[LCD_FRONTPLANE1] = (LCD_SEG_A);
    LCD->WF8B[LCD_FRONTPLANE2] = (LCD_SEG_E | LCD_SEG_G);
    LCD->WF8B[LCD_FRONTPLANE3] = (LCD_CLEAR);
    LCD->WF8B[LCD_FRONTPLANE4] = (LCD_SEG_E | LCD_SEG_G);
    LCD->WF8B[LCD_FRONTPLANE5] = (LCD_CLEAR);
    if (ErrorNum < 0x10) {
        SegLCD_Set(ErrorNum,4);
    }
    else {
        LCD->WF8B[LCD_FRONTPLANE6] = (LCD_CLEAR);
        LCD->WF8B[LCD_FRONTPLANE7] = (LCD_CLEAR);
    }
}
