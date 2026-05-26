#include "stdint.h"
#include "stm32f10x.h"
/*#define RCC_APB2ENR (*(volatile uint32_t *)0x40021018)
#define GPIOB_CRL   (*(volatile uint32_t *)0x40010C00)
#define GPIOC_CRH   (*(volatile uint32_t *)0x40011004)
#define GPIOB_ODR   (*(volatile uint32_t *)0x40010C0C)
#define GPIOC_IDR   (*(volatile uint32_t *)0x40011008)*/

/*int main() // when the button is pushed, the led will be on, otherwise it will be off.
{
// Enable clocks for GPIOB and GPIOC
	RCC_APB2ENR |= (1<<3); // GPIOB
	RCC_APB2ENR |= (1<<4); // GPIOC

	// Set PB0 as output (push-pull, max speed 50 MHz)
	GPIOB_CRL &= ~(15UL<<0);
	GPIOB_CRL |= 3UL<<0;

	// Set PC15 as input
	GPIOC_CRH &= ~(15UL<<28);
	GPIOC_CRH |= 4UL<<28;
	
	while(1)
	{
			if(GPIOC_IDR & (1UL<<15))
			{
				GPIOB_ODR |=1UL<<0;
			}
			else
			{
				GPIOB_ODR &= ~(1UL<<0);
			}
	}
}
*/
/*void delay()
{
	for(int i=0;i<50000;i++)
	{}
}*/
int main()
{
// Enable clocks for GPIOB and GPIOC
	RCC->APB2ENR |= (1<<2); // GPIOB
	RCC->APB2ENR |= (1<<3); // GPIOC

	// Set PB0 as output (push-pull, max speed 50 MHz)
	GPIOA->CRL &= ~((15UL<<4)|(15<<8));
	GPIOA->CRL |= 4UL<<4|(4<<8);

	// Set PC15 as input
	GPIOB->CRL &= ~(15UL<<4);
	GPIOB->CRL |= 3UL<<4;
	
	while(1)
	{
		if( (GPIOA->IDR&(1<<1))^(GPIOA->IDR&(1<<2)) )
		{
			GPIOB->ODR |=(1<<1);
		}
		else
		{
			GPIOB->ODR &=~(1<<1);
		}
	}
}