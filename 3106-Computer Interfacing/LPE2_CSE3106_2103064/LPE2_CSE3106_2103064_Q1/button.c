#include "stm32f10x.h"
#include "stdint.h"


void gpio_set()
{
	RCC->APB2ENR |= (1UL<<2)|(1UL<<3);
	GPIOA->CRL &= ~((15UL<<4)|(15UL<<8));
	GPIOA->CRL |= (4UL<<4)|(4UL<<8);
	
	GPIOB->CRL &=~(15UL<<4);
	GPIOB->CRL |=(3UL<<4);
}
int main()
{
	gpio_set();
	
	while(1)
	{
		int x=!(GPIOA->IDR&(1UL<<1));
		int y=!(GPIOA->IDR&(1UL<<2));
		
		if((x||y)&&(x!=y))
		{
			GPIOB->ODR |=(1UL<<1);
		}
		else
		{GPIOB->ODR &= ~(1UL<<1);}
		
	}
}