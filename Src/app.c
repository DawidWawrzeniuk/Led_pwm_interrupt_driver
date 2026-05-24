#include "ADC_driver.h"
#include "GPIO_driver.h"
#include "TIMER_driver.h"
#include "led_logic.h"
#include "SYSTICK_driver.h"
#include <stdint.h>
void App_Run(void)
{
	uint32_t AdcSample;
	ADC_Conversion();
	AdcSample = ADC_ReadData();
	Set_Led_Brightness(AdcSample);
}
void App_Init(void)
{
	SysTick_Config(8000000 / 1000); // 1 ms
	Configure_PA5();
	Configure_PA1();
	ConfigurePA6();
	TIM3_BaseConfiguration();
	TIM3_InterruptConfiguration();
	TIM3_PwmConfiguration();
	TIM3_Start();
	ADC_Input0GpioConfigure();
	ADC_Configure();
	ADC_ChannelSelection();
}
