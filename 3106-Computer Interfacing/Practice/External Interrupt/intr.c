#include "stm32f10x.h" // Device header


int on=0;
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




void GPIO_Config(void) {
// Enable clock for GPIOA, GPIOC, and AFIO
	RCC->APB2ENR |= (1UL<<3)|(1UL<<4) | (1UL<<0); // You can enable separately

	// Configure PA0 as input floating
	GPIOC->CRH &= ~(15UL<<28); // Clear mode and configuration bits for PA0
	GPIOC->CRH |= (4UL<<28); // Set configuration to input floating

	// Configure PC15 as output push-pull
	GPIOB->CRL &= ~(15UL<<0); // Clear mode and configuration bits for PC15
	GPIOB->CRL |= (3UL<<0); // Set mode to 50 MHz output push-pull
	}
void EXTI_Config(void) {
	// Configure EXTI line 0 to be triggered by PA0
	AFIO->EXTICR[3] &= ~(15UL<<12);  // Clear EXTI0 bits
	AFIO->EXTICR[3] |= (2UL<<12);   // Set EXTI0 to PA0

	// Configure EXTI0 line to trigger on rising edge
	EXTI->IMR |= (1UL<<15);   // Unmask EXTI0
	EXTI->RTSR |= (1UL<<15);  // Trigger on rising edge
	EXTI->FTSR |= (1UL<<15);  // Trigger on falling edge
}

void NVIC_Config(void) {
	NVIC_EnableIRQ(EXTI15_10_IRQn);  // Enable EXTI0 interrupt in NVIC
}
void EXTI15_10_IRQHandler(void) {
	if (EXTI->PR & (1UL<<15)) { // Check if EXTI0 interrupt pending
	EXTI->PR |= (1UL<<15); // Clear the interrupt pending bit

	// Toggle PC15 based on PA0 input state
	if (GPIOC->IDR & (1UL<<15))		
		{
			GPIOB->ODR |=(1UL<<0); // Turn off PC15
			}
		//GPIOC->ODR |= (1UL<<13); // Turn on PC15
	else
	{
			GPIOB->ODR &=~(1UL<<0);
	}
	}
}
int main(void) {
	systick_init();
	GPIO_Config();
	EXTI_Config();
	NVIC_Config();

	while(1)
	{
	// Main loop does nothing, waiting for interrupt
	}
}
