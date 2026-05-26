
#include "stm32f10x.h"
#define RED_PIN    10
#define GREEN_PIN  11
#define BLUE_PIN   12

int led;
void GPIO_Config(void);
char Keypad_Scan(void);
void RGB_Control(char key);


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
	// 6. NVIC setup
    /*NVIC_EnableIRQ(ADC1_2_IRQn);
    NVIC_SetPriority(ADC1_2_IRQn, 0);*/
	// Read and return 12-bit ADC conversion result from Data Register
	return ADC1->DR; // Read result
}

// -------External Interrupt-----------
	



void systick_init(void) {
    SysTick->LOAD = 72000 - 1; // Set reload register for 1 ms
    SysTick->VAL = 0; // Clear current value register
    SysTick->CTRL = 5; // Enable SysTick with processor clock
}

void delay_ms(void) 
{
    while (!(SysTick->CTRL & (1 << 16)));//*char key = Keypad_Scan(); // Wait for COUNTFLAG to be 1
}

void delay_t(unsigned long t) 
	{
    while (t--) 
		{			delay_ms();}
	}
/*void ADC1_2_IRQHandler(void) {
    if(ADC1->SR & ADC_SR_EOC) {
			while(1){
        uint16_t val=adc_read();  // Read result (clears EOC flag)
        // Process the value (e.g., trigger action)
			int delay = 100 + (val * 900) / 4095;
			GPIOA->ODR^=led;
				delay_t(delay);
			}
				
    }
}*/
int main(void) {
		systick_init();
    GPIO_Config();
		adc_init();

    while (1) {
			int val=adc_read();
			int delay = 100 + (val * 100) / 4095;
        char key = Keypad_Scan();
        if (key != 0) {
            RGB_Control(key);
        }
				GPIOA->ODR^=led;
				delay_t(delay);
				
    }
}

void GPIO_Config(void) {
    RCC->APB2ENR |= (1 << 2) | (1 << 3);  // Enable GPIOA and GPIOB clocks

    // PA0-PA3 rows as input pull-up
    GPIOA->CRL &= ~0xFFFF;
    GPIOA->CRL |= 0x8888;   // Input with pull-up/down
    GPIOA->ODR |= 0x0F;     // Enable pull-up

    // PA10, PA11, PA12 RGB LED pins as output push-pull
    GPIOA->CRH &= ~((0xF << 8) | (0xF << 12) | (0xF << 16));
    GPIOA->CRH |=  ((0x1 << 8) | (0x1 << 12) | (0x1 << 16));  // Output 10MHz

    // PB0, PB1, PB5 columns as output push-pull
    GPIOB->CRH &= ~((0xF << 0) | (0xF << 4) | (0xF << 8)|(15<<12));
    GPIOB->CRH |=  ((0x1 << 0) | (0x1 << 4) | (0x1 << 8)|(1<<12));  // Output 10MHz
}

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
					led^=led;
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