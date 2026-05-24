#include <stdint.h>
#include <led_logic.h>
#include "main.h"
void Set_Led_Brightness(uint32_t duty_cycle)
{
	if (duty_cycle > ADC_MAX)
		duty_cycle = ADC_MAX;
	TIM3->CCR1 = (duty_cycle * PWM_MAX) / ADC_MAX;
}
