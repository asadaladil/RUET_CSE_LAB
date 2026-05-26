#include "stm32f10x.h"

volatile uint16_t adc_value;

void pwm(int x)
{
TIM2->PSC = 72 - 1;            // Prescaler (for 1 MHz timer clock if 72 MHz system clock)
    TIM2->ARR = 1000 - 1;          // Auto-reload value: Period = 1 ms (1 kHz PWM frequency)
    TIM2->CCR1 = x;              // Duty cycle = 50% (500/1000)

    // 4. Set PWM Mode 1 (output high until match, then low)
    TIM2->CCMR1 &= ~(7 << 4);      // Clear OC1M bits
    TIM2->CCMR1 |= (6 << 4);       // OC1M = 110 (PWM mode 1)
    TIM2->CCMR1 |= (1 << 3);       // OC1PE = 1 (Preload enable)

    // 5. Enable output on CH1
    TIM2->CCER |= (1 << 0);        // CC1E = 1

    // 6. Enable Auto-Reload Preload
    TIM2->CR1 |= (1 << 7);         // ARPE = 1

    // 7. Enable counter
    TIM2->CR1 |= (1 << 0);         // CEN = 1
                    
	
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
	ADC1->SMPR2 |= (7 << 3);
				
	}
int adc_read(void) {
	
	// Set total number of conversions to 1 (Single Conversion)
	// 0000 : 1 Conversion, 0001 : 2 Conversions
	ADC1->SQR1 = (1 - 1) << 20;
	
	// Set regular sequence register to channel 0 (PA0)
	ADC1->SQR3 = (1 << 0);

	// Start conversion by setting ADON again
	// (first ADON turns on ADC, second triggers conversion)
	
	ADC1->CR2 |= (1 << 0);
	
	// Wait until End Of Conversion (EOC) flag is set (bit 1)
	while (!(ADC1->SR & (1 << 1)));
	
	// Read and return 12-bit ADC conversion result from Data Register
	return ADC1->DR; // Read result
}


void systick_init()
{
	SysTick->LOAD=72000-1; //ms
	SysTick->VAL=0;
	SysTick->CTRL=5;
}

void delay_ms()
{
	while(!(SysTick->CTRL&(1<<16)));
}
void delay(int t)
{
	while(t--)
	{
		delay_ms();
	}
}

int main(void) {
    // 1. Enable clocks for TIM2 and GPIOA
    RCC->APB1ENR |= (1UL << 0);   // TIM2 clock enable
    RCC->APB2ENR |= (1UL << 2);   // GPIOA clock enable
    RCC->APB2ENR |= (1UL << 0);   // AFIO clock enable (important for alternate function)

    // 2. Configure PA0 (TIM2_CH1) as Alternate Function Push-Pull
    GPIOA->CRL &= ~(0xF << 0);     // Clear MODE0[1:0] and CNF0[1:0]
    GPIOA->CRL |= (0xB << 0);      // MODE0 = 11 (50 MHz), CNF0 = 10 (AF Push-Pull)
	adc_init();
    // 3. Timer Configuration for PWM
    systick_init();
	/*while(1)
	{
	for(int i=0;i<501;i++)
		{
			pwm(i);
			delay(10);
		}
		for(int i=500;i>=0;i--)
		{
			pwm(i);
			delay(10);
		}
	delay(1000);
	}*/
	
	while(1)
	{
		int x=1000*adc_read()/4095;
		pwm(x);
		//delay(10);
		
		
		
	}
}

