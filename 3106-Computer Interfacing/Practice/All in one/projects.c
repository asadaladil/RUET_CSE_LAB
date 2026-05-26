#include "stm32f10x.h" // Device header
#define RED_PIN    10
#define GREEN_PIN  11
#define BLUE_PIN   12

int key,led;
uint16_t adc_read(void);

// --------Systick Timer---------
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


// ------------GPIO Configuration-------------

void GPIO_Config(void) {
// Enable clock for GPIOA, GPIOC,
	RCC->APB2ENR |= (1UL<<2)|(1UL<<4)|(1UL<<3); // You can enable separately

	// Configure PA0 as input floating (FOR INPUT)
	GPIOA->CRL &= ~((15UL<<0)|(15<<4)|(15<<8)|(15<<12)); // Clear mode and configuration bits for PA0
	GPIOA->CRL |= (4<<0)|(4<<4)|(4<<8)|(4<<12); // Set configuration to input floating
	
	GPIOA->CRH &= ~((15<<8)|(15<<12)|(15<<16));
	GPIOA->CRH |= ((3<<8)|(3<<12)|(3<<16));
	// Configure PC15 as output push-pull
	GPIOA->CRL &= ~((15<<24)); // Clear mode and configuration bits for PC15
	GPIOB->CRL |= (0<<24); // Set mode to 50 MHz output push-pull
	
	}

	
// -------External Interrupt-----------
	
void EXTI_Config(void) {
	
	RCC->APB2ENR |=(1UL<<0); //AFIO enabling
	// Configure EXTI line 0 to be triggered by PA0
	AFIO->EXTICR[1] &= ~(15UL<<20);  // Clear EXTI0 bits
	AFIO->EXTICR[1] |= (0UL<<20);   // Set EXTI0 to PA0

	// Configure EXTI0 line to trigger on rising edge
	EXTI->IMR |= (1UL<<5);   // Unmask EXTI0
	EXTI->RTSR |= (1UL<<5);  // Trigger on rising edge
	EXTI->FTSR |= (1UL<<5);  // Trigger on falling edge
}

void NVIC_Config(void) {
	NVIC_EnableIRQ(EXTI9_5_IRQn);  // Enable EXTI0 interrupt in NVIC
}
void EXTI9_5_IRQHandler(void) {
	if (EXTI->PR & (1UL<<5)) { // Check if EXTI0 interrupt pending
	EXTI->PR |= (1UL<<5); // Clear the interrupt pending bit
	
		// interrupt er code ekhane likhte hobe main function e na......
		
	// Toggle PC15 based on PA0 input state
		int val=adc_read();
		uint32_t delay = 100 + (val * 900) / 4095;
		GPIOA->ODR ^=led;
		delay_t(delay);
		
		
	}
}

// --------Keypad Code------------

char Keypad_Scan(void) {
    const char keymap[4][4] = {
        {'1', '2', '3','A'},
        {'4', '5', '6','B'},
        {'7', '8', '9','C'},
        {'*', '0', '#','D'}
    };

    const uint8_t col_pins[4] = {8,9,10,11}; // PB0, PB1, PB5, PB6

    for (int col = 0; col < 4; col++) {
        GPIOB->ODR |= (1 << 8) | (1 << 9) | (1 << 10)|(1<<11);  // Set all columns HIGH
        GPIOB->ODR &= ~(1 << col_pins[col]);            // Set current column LOW

        for (int row = 0; row < 4; row++) {
            if (!(GPIOA->IDR & (1 << row))) {  // Active LOW check
                delay_t(20); // debounce
                while (!(GPIOA->IDR & (1 << row))); // wait for release
                return keymap[row][col];
            }
        }
    }
    return 0;
}
void RGB_Control(char key) {
    // Turn off all LEDs first
    GPIOA->ODR &= ~((1 << RED_PIN) | (1 << GREEN_PIN) | (1 << BLUE_PIN));

    switch (key) {
        case '1':  // GREEN + BLUE
            GPIOA->ODR |= (1 << GREEN_PIN) | (1 << BLUE_PIN);
						led=(1 << GREEN_PIN) | (1 << BLUE_PIN);
            break;
        case '2':  // BLUE + RED
            GPIOA->ODR |= (1 << BLUE_PIN) | (1 << RED_PIN);
						led=(1 << BLUE_PIN) | (1 << RED_PIN);
            break;
        case '3':  // RED + GREEN
            GPIOA->ODR |= (1 << RED_PIN) | (1 << GREEN_PIN);
						led=(1 << RED_PIN) | (1 << GREEN_PIN);
            break;
        case '4':  // RED only
            GPIOA->ODR |= (1 << RED_PIN);
						led=(1 << RED_PIN);
            break;
        case '5':  // GREEN only
            GPIOA->ODR |= (1 << GREEN_PIN);
						led=(1 << GREEN_PIN);
            break;
        case '6':  // BLUE only
            GPIOA->ODR |= (1 << BLUE_PIN);
						led=(1 << BLUE_PIN);
            break;
        case '7':  // OFF
            // All off, already done
            break;
        case '0':  // WHITE (RED+GREEN+BLUE)
            GPIOA->ODR |= (1 << RED_PIN) | (1 << GREEN_PIN) | (1 << BLUE_PIN);
						led=(1 << RED_PIN) | (1 << GREEN_PIN) | (1 << BLUE_PIN);
            break;
				case '8':  // WHITE (RED+GREEN+BLUE)
            GPIOA->ODR |= (1 << RED_PIN) | (1 << GREEN_PIN) | (1 << BLUE_PIN);
						led=(1 << RED_PIN) | (1 << GREEN_PIN) | (1 << BLUE_PIN);
            break;
        default:
            break;
    }
}

// ---------ADC Reading------------
void adc_init(void) {
	// Enable ADC1 clock (bit 9 = ADC1EN)
	RCC->APB2ENR |= (1 << 9);
	
	// Turn on ADC1 (set ADON bit)
	ADC1->CR2 |= (1 << 0);
	
	// Short software delay for ADC stabilization
	for (volatile int i = 0; i < 1000; i++);
	
	//ADC_SMPR2_SMP0 (bits 2:0 = 111 for 239.5 cycles)
	//Set sampling time for channel 0 to 239.5 ADC cycles
	ADC1->SMPR2 |= (7 << 5);
	}
uint16_t adc_read(void) {
	
	// Set total number of conversions to 1 (Single Conversion)
	// 0000 : 1 Conversion, 0001 : 2 Conversions
	ADC1->SQR1 = (1 - 1) << 20;
	
	// Set regular sequence register to channel 0 (PA0)
	ADC1->SQR3 = (0 << 0);

	// Start conversion by setting ADON again
	// (first ADON turns on ADC, second triggers conversion)
	
	ADC1->CR2 |= (1 << 0);
	
	// Wait until End Of Conversion (EOC) flag is set (bit 1)
	while (!(ADC1->SR & (1 << 1)));
	
	// Read and return 12-bit ADC conversion result from Data Register
	return ADC1->DR; // Read result
}


// ----------------Timer Code(One Pulse Mode)---------------
void TimerOPM_init()
{
	RCC->APB1ENR |= 1UL<<0;
	TIM2->CNT = 0;
// Prescaler value
  	TIM2->PSC = 3600 - 1; 
// Auto-reload value for 1000 ms  
  	TIM2->ARR = 10000 - 1;
// Configure as OPM   
	TIM2->CR1 |= 1UL<<3;
}

// ----------------Timer Code(Output Capture Mode)---------------
void TimerOCM_init()
{
	RCC->APB1ENR |= (1UL << 0);  // TIM2 clock enable
	// Configure TIM2
	// Prescaler value (PSC)
	TIM2->PSC = 3600 - 1;     	
	// Auto-reload value (ARR) for 1 second timing (assuming 36MHz clock)
	TIM2->ARR = 10000 - 1;
	// Set the capture/compare register value for CH1 (50% duty cycle)     	
	TIM2->CCR1 = 5000 - 1;
	// Set Output Compare mode to Toggle (011)
	TIM2->CCMR1 |= 3<<4;
	// Enable the output on CH1 
	TIM2->CCER |= 1<<0;
	TIM2->CR1 |= 1;       

}


int main(void) {
		//adc_init();
    systick_init();
		GPIO_Config();
		//EXTI_Config();
		//NVIC_Config();

	/*while(1)
	{
				//Interrupt er while loop
	}*/

    while (1) {
			
			// keypad er while loop
			
        char key = Keypad_Scan();
        if (key != 0) {
						if (key=='1'){key=1;}
						else if (key=='2'){key=2;}
						if (key=='3'){key=3;}
            RGB_Control(key);
        }
    }
		/*while (1) {
			//int x=Keypad_Scan()*1000+100;
			int y=100;
			// ADC er while loop
			
	// Read ADC value from channel 0 (range: 0 to 4095)
	uint16_t adc_value = adc_read();
		
	// Convert ADC value to delay between 100ms to 1000ms
	// based on potentiometer input
	uint32_t delay = 100 + (adc_value * 900) / 4095; // 100ms–1000ms
		
	// Toggle PC13 (LED) state (XOR with 1 << 13)
	GPIOC->ODR ^= (1 << 13);
	delay_ms(delay);
		if(adc_value<=1365)
		{
			GPIOA->ODR&=~(1<<1);
			GPIOB->ODR^=(1<<0);
			delay_t(y);
			GPIOB->ODR^=(1<<0);
			GPIOB->ODR^=(1<<1);
			delay_t(y);
			GPIOB->ODR^=(1<<1);
			GPIOA->ODR^=(1<<1);
			delay_t(y);
		}
		else if(adc_value<=2730)
		{
			GPIOB->ODR&=~(1<<0);
			GPIOB->ODR|=(1<<1);
			GPIOA->ODR&=~(1<<1);
		}
		else
		{
			GPIOB->ODR&=~(1<<0);
			GPIOB->ODR&=~(1<<1);
			GPIOA->ODR|=(1<<1);
		}
	}*/
		
	/*while(1) {
		
		// Timer OPM er while loop.....
		
    	TIM2->CR1 |= 1; // Start Timer
    	while(TIM2->CR1 & 1); // Check if still counting
    	GPIOA->ODR ^= 1UL<<0;  // Toggle output
	}*/
	
	/*while(1)
	{
			// Timer OCM er while loop........
	}*/

}

