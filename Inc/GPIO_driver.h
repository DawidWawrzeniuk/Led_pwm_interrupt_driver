#include "stm32f3xx.h"
#include <stdint.h>

void Configure_PA5(void);
void Configure_PA1(void);
void ConfigurePA6(void);
typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
} Button_t;


uint32_t Is_Button_Pressed(Button_t *button);


