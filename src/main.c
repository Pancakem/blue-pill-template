#include "../inc/stm32f1xx.h"

void delay(long cycles)
{
  while(cycles >0)
  cycles--;
}

void gpio_ports_enable(void)
{
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN |     RCC_APB2ENR_IOPBEN|RCC_APB2ENR_IOPCEN; //ports A & B clock enabled
  GPIOC->CRH |= GPIO_CRH_MODE13_0|GPIO_CRH_MODE13_1;
  GPIOC->CRH &= ~(GPIO_CRH_CNF13_0|GPIO_CRH_CNF13_1);
}

int main(void)
{
    gpio_ports_enable();

    while(1)
    {
          GPIOC->BSRR = GPIO_BSRR_BS13; 
          delay(500000);
          GPIOC->BSRR = GPIO_BSRR_BR13; 
          delay(500000); 
        }    
}
