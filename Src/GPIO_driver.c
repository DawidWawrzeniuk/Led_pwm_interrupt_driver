#include "main.h"
#include <GPIO_driver.h>
Button_t BTN_PA5 = {GPIOA,5};
Button_t BTN_PA1 = {GPIOA,1};

void Configure_PA5(void)
{
	//Enable clock access to gpioa
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	//Set pa0 mode to input
	GPIOA->MODER &=~ (GPIO_MODER_MODER5_0);
	GPIOA->MODER &=~ (GPIO_MODER_MODER5_1);
	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR5);
	GPIOA->PUPDR |=  GPIO_PUPDR_PUPDR5_0;   			// pull-up
}
void Configure_PA1(void)
{
	//Set pa1 mode to input
	GPIOA->MODER &=~ (GPIO_MODER_MODER1_0);
	GPIOA->MODER &=~ (GPIO_MODER_MODER1_1);
	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR1);
	GPIOA->PUPDR |=  GPIO_PUPDR_PUPDR1_0;   			// pull-up
}
void ConfigurePA6(void)
{
		//PA6 as a output compare TIM3 CH1
		RCC->AHBENR |= RCC_AHBENR_GPIOAEN;				//clock to gpioa
		GPIOA->MODER |= GPIO_MODER_MODER6_1;			//pa6 as alternate function
		GPIOA->MODER &= ~(GPIO_MODER_MODER6_0);			//
		//wspisanie alternate function AF2
		GPIOA->AFR[0] &= ~(0xF << 24);					//reset four bits
		GPIOA->AFR[0] |= (1 << 25); // AF2 = TIM3

		GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_6);			// push-pull
		GPIOA->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR6);	// low speed rising signals (both bits)
		GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPDR6);			// no-pull up no- pull down
}
uint32_t Is_Button_Pressed(Button_t *button)
{
	return !(button->port->IDR & (1U << button->pin));
}

