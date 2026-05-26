#include "stm32f10x.h"
void delay_ms(uint32_t ms);
void gpio_init(void);
void adc_init(void);
uint16_t adc_read(void);

int main(void) 
{
	gpio_init();
	adc_init();
	while (1) {
	
	uint16_t adc_value = adc_read();
	if(adc_value>=4000)
	{
		GPIOB->ODR |=(1UL<<0);
		GPIOB->ODR &=~(1UL<<1);
	}
	else
	{
		GPIOB->ODR |=(1UL<<1);
		GPIOB->ODR &=~(1UL<<0);
	}
	}
}
void gpio_init(void) 
{
	RCC->APB2ENR |= (1 << 3);
	GPIOB->CRL &= ~(15UL << 0 | 15UL<<4);
	GPIOB->CRL |= (1UL << 0 | 1UL<<4);
	RCC->APB2ENR |= (1 << 2); 
	GPIOA->CRL &= ~(15UL << 0);
	GPIOA->CRL |= (0UL << 0); 
}
void adc_init(void) {

	RCC->APB2ENR |= (1 << 9);
	
	ADC1->CR2 |= (1 << 0);
	
	for (volatile int i = 0; i < 1000; i++);

	ADC1->SMPR2 |= (0x7 << 0);
}

uint16_t adc_read(void) 
{
	ADC1->SQR1 = (1 - 1) << 20;

	ADC1->SQR3 = (0 << 0);

	ADC1->CR2 |= (1 << 0);

	while (!(ADC1->SR & (1 << 1)));
	
	return ADC1->DR;
}