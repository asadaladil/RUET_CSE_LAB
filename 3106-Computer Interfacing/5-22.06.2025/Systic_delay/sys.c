#include "stm32f10x.h"

// Function prototypes
void GPIO_Config(void);
void EXTI_Config(void);
void NVIC_Config(void);
void SysTick_Init(void);
void delay_ms(uint32_t ms);

// Configure GPIO: PB0 as input for button, PC15 as output for LED
void GPIO_Config(void) {
    // Enable clocks for GPIOB, GPIOC and AFIO
    RCC->APB2ENR |= (1 << 3) | (1 << 4) | (1 << 0);

    // Configure PB0 as input floating (external pull-down resistor used)
    GPIOB->CRL &= ~(0xF << 0);  // Clear CNF0 and MODE0 bits
    GPIOB->CRL |= (0x4 << 0);   // CNF0 = 01 (floating input), MODE0 = 00 (input mode)

    // Configure PC15 as output push-pull, max speed 2 MHz
    GPIOC->CRH &= ~(0xF << 28); // Clear CNF15 and MODE15 bits
    GPIOC->CRH |= (0x2 << 28);  // CNF15 = 00 (push-pull output), MODE15 = 10 (2 MHz)
}

// Configure external interrupt EXTI0 to be triggered by PB0 (falling edge)
void EXTI_Config(void) {
    // Map EXTI0 line to port B pin 0
    AFIO->EXTICR[0] &= ~(0xF << 0);
    AFIO->EXTICR[0] |= (0x1 << 0);

    EXTI->IMR |= (1 << 0);      // Unmask EXTI0 line
    EXTI->FTSR |= (1 << 0);     // Trigger on falling edge (button release)
    // You can also enable rising edge (EXTI->RTSR |= (1 << 0);) if needed
}

// Enable EXTI0 interrupt in NVIC
void NVIC_Config(void) {
    NVIC_EnableIRQ(EXTI0_IRQn);
}

// Initialize SysTick timer for 1 millisecond tick (assuming 72 MHz system clock)
void SysTick_Init(void) {
    SysTick->LOAD = 72000 - 1; // 72,000 clocks for 1 ms (72 MHz / 1000)
    SysTick->VAL = 0;          // Clear current SysTick value
    SysTick->CTRL = 5;         // Enable SysTick, use processor clock, no interrupt
}

// Delay function: blocks for specified milliseconds using SysTick timer
void delay_ms(uint32_t ms) {
    while (ms--) {
        while (!(SysTick->CTRL & (1 << 16)));  // Wait until COUNTFLAG is set
    }
}

// EXTI0 interrupt handler: called on button press (falling edge on PB0)
void EXTI0_IRQHandler(void) {
    if (EXTI->PR & (1 << 0)) {       // Check if interrupt pending on EXTI0
        delay_ms(30);                // Debounce delay of 30 ms
        if (!(GPIOB->IDR & (1 << 0))) { // Check if button is still pressed (LOW)
            delay_ms(500);          // Actual 1 second delay
            GPIOC->ODR ^= (1 << 15); // Toggle LED on PC15
        }
        EXTI->PR |= (1 << 0);        // Clear interrupt pending flag
    }
}

int main(void) {
    GPIO_Config();   // Configure GPIO pins
    EXTI_Config();   // Configure external interrupt
    NVIC_Config();   // Enable NVIC interrupt
    SysTick_Init();  // Initialize SysTick timer

    while (1) {
        // Main loop does nothing; LED toggling handled in ISR
    }
}