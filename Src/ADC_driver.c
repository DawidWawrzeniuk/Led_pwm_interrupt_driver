#include "main.h"






void ADC_Configure(void)
{
	//--------PA0----------

	//--------RCC----------
    RCC->AHBENR |= RCC_AHBENR_ADC12EN;		//RCC
    //--------ADC DISABLE----------
    ADC1->CR &= ~(ADC_CR_ADEN);				//wylaczenie adc
    //--------SAMPLING TIME----------
    ADC1 ->SMPR1 |= ADC_SMPR1_SMP0_0;
    ADC1 ->SMPR1 |= ADC_SMPR1_SMP0_1;		//sampling time 601,5 cycle
    ADC1 ->SMPR1 |= ADC_SMPR1_SMP0_2;
    //--------RCC PRESKALER----------
    ADC1_2_COMMON->CCR &= ~(ADC_CCR_CKMODE); // HCLK/1
    ADC1_2_COMMON->CCR |= ADC_CCR_CKMODE_0;


    //--------SINGLE CONV MODE----------
    ADC1 -> CFGR &= ~(ADC_CFGR_CONT);
    //--------DATA RESOLUTION----------
    ADC1 -> CFGR &= ~(ADC_CFGR_RES);		//12 bit


    //--------SINGLE ENDED MODE----------
    ADC1 -> DIFSEL &= ~(ADC_DIFSEL_DIFSEL_0);		//single ended mode ch1

    //--------SEKWENCE ADC REGULATOR ENABLE----------
    ADC1 -> CR &= ~(ADC_CR_ADVREGEN);
    ADC1 -> CR &= ~(ADC_CR_ADVREGEN_0);	//adc voltage regulator enable
    ADC1 -> CR |= ADC_CR_ADVREGEN_1;
    for (uint32_t i=0; i<9999; i++)
    {
    }

    //--------CALIBRATION ADC1----------
    ADC1->CR &= ~(ADC_CR_ADCALDIF);  //Writing ADCAL will launch a calibration in Single-ended inputs Mode.
    ADC1 ->CR |= ADC_CR_ADCAL; 		// kalibracja adc
    while  (ADC1 ->CR & ADC_CR_ADCAL)
    {}


    //--------ADC ENABLE----------
    ADC1->CR |= ADC_CR_ADEN;			//wlaczenie adc enable
    while (!(ADC1->ISR & ADC_ISR_ADRDY))
    {
    }
}
void ADC_Input0GpioConfigure(void)
{
    // PA0
    GPIOA->MODER |= GPIO_MODER_MODER0; // analog mode (11)
}
void ADC_ChannelSelection(void)
{
    // długość konwersji jest ustawiona na jedną konwersję (domyślnie)
	ADC1->SQR1 &= ~ADC_SQR1_SQ1;
	ADC1->SQR1 |= (1 << ADC_SQR1_SQ1_Pos); // ustawienie kanału 1 w pierwszej konwersji
}
void ADC_Conversion(void)
{
    ADC1->CR |= ADC_CR_ADSTART; // start adc

    while (!(ADC1->ISR & ADC_ISR_EOC))
    {
    }
}
uint32_t ADC_ReadData(void)
{
    return ADC1->DR;
}
