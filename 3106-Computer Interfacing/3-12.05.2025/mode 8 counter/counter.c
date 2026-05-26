#include "stdint.h"
#include "stm32f10x.h"

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

int d=0;
void delay()
{
	for(int i=0;i<2000000;i++)
	{}
}
void doublee()
{
   GPIOB->ODR=d<<3;
	return;
}


int main()
{
// Enable clocks for GPIOA
	RCC->APB2ENR |= (3<<2); // GPIOA

	// Set PA0-2 as output (push-pull, max speed 50 MHz)
	GPIOA->CRL &= ~(15UL<<0);
	GPIOA->CRL &= ~(15UL<<4);
	GPIOA->CRL &= ~(15UL<<8);
	GPIOA->CRL &= ~(15UL<<12);
	GPIOA->CRL |= 3UL<<0;
	GPIOA->CRL |= 3UL<<4;
	GPIOA->CRL |= 3UL<<8;
	GPIOA->CRL |= 3UL<<12;
	
	GPIOB->CRL &= ~(15UL<<0);
	GPIOB->CRL |= 3UL<<0;
	
	//GPIOB->ODR=d<<3;
	
	
	while(1)
	{
		for(int i=0;i<10;i++)
		{
			GPIOA->ODR=i;
			if (i==6||i==9)
			{
				GPIOB->ODR=0;
			}
			else
			{
				GPIOB->ODR=1;
			}
			delay();
		}
	}
}