/*#include "stm32f10x.h"

void systick_init(void) {
    SysTick->LOAD = 72000 - 1; // Set reload register for 1 ms
    SysTick->VAL = 0; // Clear current value register
    SysTick->CTRL = 5; // Enable SysTick with processor clock
}

void delay_ms(void) 
{
    while (!(SysTick->CTRL & (1 << 16))); // Wait for COUNTFLAG to be 1
}

void delay_t(unsigned long t) 
	{
    while (t--) 
		{ delay_ms();}
}
void GPIO_config(void) {
	
	// Enable GPIOC clock
	RCC->APB2ENR |= (1 << 4);

	// Configure PC15 as output push-pull
   // Clear mode and configuration bits for PC15
	GPIOC->CRH &= ~(15 << 20); 	

   // MODE15[1:0] = 10 (Output mode, max speed 2 MHz)
   GPIOC->CRH |= (2 << 20);	
}
int main(void) {
	systick_init();    	// Initialize SysTick
	GPIO_config();     // Configure GPIO

	while (1) {
    	GPIOC->ODR = (1 << 13); // Enable PC15
    	delay_t(1000);         	// Delay for 500 ms
    	GPIOC->ODR = (0 << 13); // Disable PC15
    	delay_t(1000);         	// Delay for 500 ms
	}
}*/



#include "stm32f10x.h"

int main()
{
	RCC->APB2ENR |=(1<<2)|(1<<3);
	GPIOA->CRL &=~()
}
