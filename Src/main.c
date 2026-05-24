#include "main.h"
#include <prototypes.h>
#include <ADC_driver.h>
#include <GPIO_driver.h>
#include <TIMER_driver.h>
#include <SYSTICK_driver.h>
#include <led_logic.h>
int main(void)
{
	App_Init();
	/* Loop forever */
	while(1)
	{
		App_Run();

	}
}


