


#include "stdint.h"
#include "stm32f10x.h"

int d=0;
char UART_Receiver()
{
	while(!(USART1->SR &(1<<5)));
	return USART1->DR;
}
void delay()
{
	for(int i=0;i<3000000;i++)
	{}
}
void show_digit(int d)
{
			GPIOA->ODR &= ~(15<<0);
			GPIOA->ODR|=d;
			if (d==6||d==9)
			{
				GPIOC->ODR=0;
			}
			else
			{
				GPIOC->ODR=0xFFFFFFFF;
			}
}
void gpio_init()
{
	// Enable clocks for GPIOA
	RCC->APB2ENR |= (1<<2) | (1<<4) | (1<<14);
	

	GPIOA->CRL &= ~(15UL<<0);
	GPIOA->CRL &= ~(15UL<<4);
	GPIOA->CRL &= ~(15UL<<8);
	GPIOA->CRL &= ~(15UL<<12);
	GPIOA->CRL |= 3UL<<0;
	GPIOA->CRL |= 3UL<<4;
	GPIOA->CRL |= 3UL<<8;
	GPIOA->CRL |= 3UL<<12;
	
	GPIOC->CRH &= ~(15UL<<20);
	GPIOC->CRH |= 3UL<<20;
	
	GPIOA->CRH &= ~((15<<4) | (15<<8));
	GPIOA-> CRH |= (11<<4);
	GPIOA->CRH |= (4<<8);
	
	USART1->BRR = 39<<4;
	USART1->BRR |= 1<<0;
	
	USART1->CR1 |= 1<<13;
	USART1->CR1 |= 1<<2;
	USART1->CR1 |= 1<<3;

}
int main()
{	
	gpio_init();
	while(1)
	{
		/*for(int i=0;i<10;i++)
		{
			show_digit(i);
			delay();
		}*/
		char c=UART_Receiver();	
		int i;
		if(c>='0'&&c<='9') 
			{
					i=c-'0'; 
					show_digit(i);
      }
	
	}
}