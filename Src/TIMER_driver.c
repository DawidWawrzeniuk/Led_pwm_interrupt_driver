#include "main.h"






//Timer 3 configuration
void TIM3_BaseConfiguration(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;					//rcc for timera3
	TIM3->PSC = (16 - 1);								//preskaler in timer
	TIM3->ARR = (100 -1);								//do ilu ma zliczac
}

void TIM3_Start(void)
{
	TIM3->CNT = 0;				//ustawienie zera w control register
	TIM3->CR1 |= TIM_CR1_CEN;	//counter enable

}

void TIM3_InterruptConfiguration(void)
{
	TIM3->DIER |= TIM_DIER_UIE; 	//odblokowanie update interrupt enable (informuje o doliczeniu do wartosci arr)
	TIM3->DIER |= TIM_DIER_CC1IE; 	//odblokowanie capture/compare interrupt
	NVIC_SetPriority(TIM3_IRQn,0); 	//ustawienie priorytetu
	NVIC_EnableIRQ(TIM3_IRQn); 		//wlaczenie przerwania w nvic
}


void TIM3_IRQHandler(void)
{
	if (TIM3->SR & TIM_SR_UIF)		//sprawdzenie czy nastapilo przerwanie od update
	{
		TIM3->SR &= ~(TIM_SR_UIF);	//reset flagi
	}
	if (TIM3->SR & TIM_SR_CC1IF)	//sprawdzenie czy nastąpilo przerwanie od compare/capture
	{
		TIM3->SR &= ~(TIM_SR_CC1IF); //reset flagi
		//PA6_TOGGLE;
	}
}


void TIM3_PwmConfiguration(void)
{
	TIM3->CCMR1 |= TIM_CCMR1_OC1PE;   		// preload dla CCR1	//TIMx_CCR1 moze byc nadpisywany odczytywany po kazdym upodate event
	TIM3->CR1 |= TIM_CR1_ARPE;        		// preload dla ARR	//wlaczenie buforowania wartosci ktora wpisujemy do rejestru arr

	TIM3->CCMR1 &= ~TIM_CCMR1_OC1M;			//
	TIM3->CCMR1 |= TIM_CCMR1_OC1M_1; 		//tryb pwm  mode 1
	TIM3->CCMR1 |= TIM_CCMR1_OC1M_2;		//
	TIM3->CCR1 = (4 - 1);					//wypelnienie
	TIM3->CCER |= TIM_CCER_CC1E;			//capture/compare output enable

	TIM3->EGR |= TIM_EGR_UG;				//"Re-initialize the counter and generates an update of the registers."
	TIM3->CCMR1 &= ~TIM_CCMR1_CC1S; 		// CC1 channel is configured as output
}
