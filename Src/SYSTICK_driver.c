#include "main.h"
volatile uint32_t Tick;

void SysTick_Handler(void)
{
    Tick++;
}

uint32_t GetSystemTick(void)
{
    return Tick;
}
