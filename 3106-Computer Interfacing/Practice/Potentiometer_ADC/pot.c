#include "stm32f10x.h"

void delay_ms(uint32_t ms);
void gpio_init(void);
void adc_init(void);
uint16_t adc_read(void);

int main(void) {
	gpio_init();
	adc_init();
	while (1) {
	// Read ADC value from channel 0 (range: 0 to 4095)
	uint16_t adc_value = adc_read();
		
	// Convert ADC value to delay between 100ms to 1000ms
	// based on potentiometer input
	/*uint32_t delay = 100 + (adc_value * 900) / 4095; // 100ms–1000ms
		
	// Toggle PC13 (LED) state (XOR with 1 << 13)
	GPIOC->ODR ^= (1 << 13);
	delay_ms(delay);*/
		if(adc_value>=4000)
		{
				GPIOB->ODR |= (1 << 4);
				GPIOB->ODR &= ~(1 << 5);
		}
		else
		{GPIOB->ODR |=(1 << 5);
		GPIOB->ODR &= ~(1 << 4);
		}
	}
}
void gpio_init(void) {
	RCC->APB2ENR |= (1 << 3); // RCC_APB2ENR_IOPCEN (bit 4)
	
	GPIOB->CRL &= ~((15 << 16)|(15<<20)); // Clear PC13 config
	
	GPIOB->CRL |= (3 << 16)|(3<<20); // PC13 output push-pull 10MHz
	
	RCC->APB2ENR |= (1 << 2); // RCC_APB2ENR_IOPAEN (bit 2)
	
	GPIOA->CRL &= ~(15 << 20); // Clear PA0 config
	
	GPIOA->CRL |= (0 << 20); // PA0 analog input
}
void adc_init(void) {
	// Enable ADC1 clock (bit 9 = ADC1EN)
	RCC->APB2ENR |= (1 << 9);
	
	// Turn on ADC1 (set ADON bit)
	ADC1->CR2 |= (1 << 0);
	
	// Short software delay for ADC stabilization
	for (volatile int i = 0; i < 1000; i++);
	
	//ADC_SMPR2_SMP0 (bits 2:0 = 111 for 239.5 cycles)
	//Set sampling time for channel 0 to 239.5 ADC cycles
	ADC1->SMPR2 |= (7 << 0);
	}
uint16_t adc_read(void) {
	
	// Set total number of conversions to 1 (Single Conversion)
	// 0000 : 1 Conversion, 0001 : 2 Conversions
	ADC1->SQR1 = (1 - 1) << 20;
	
	// Set regular sequence register to channel 0 (PA0)
	ADC1->SQR3 = (5 << 0);

	// Start conversion by setting ADON again
	// (first ADON turns on ADC, second triggers conversion)
	
	ADC1->CR2 |= (1 << 0);
	
	// Wait until End Of Conversion (EOC) flag is set (bit 1)
	while (!(ADC1->SR & (1 << 1)));
	
	// Read and return 12-bit ADC conversion result from Data Register
	return ADC1->DR; // Read result
}
void delay_ms(uint32_t ms) {
	
	// Approximate delay using simple loop (assuming 8 MHz)
	for (uint32_t i = 0; i < ms * 800; i++) {
		
	}
}