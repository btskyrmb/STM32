#include "led.h"

void LED_Init(void)
{
    GPIO_InitTypeDef LED_Initure;

    __HAL_RCC_GPIOB_CLK_ENABLE();

    LED_Initure.Pin = GPIO_PIN_0 | GPIO_PIN_1;
    LED_Initure.Mode = GPIO_MODE_OUTPUT_PP;
    LED_Initure.Pull = GPIO_PULLUP;
    LED_Initure.Speed = GPIO_SPEED_HIGH;
    HAL_GPIO_Init(GPIOB, &LED_Initure);

    LED0(1);
    LED1(1);
}


