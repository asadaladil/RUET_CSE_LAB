#include "stm32f10x.h" // Device header
#include <stdint.h>
#define RCC_APB2ENR (*(volatile uint32_t*)0x40021018)
#define GPIOA_CRL (*(volatile uint32_t*)0x40010800)
#define GPIOA_ODR (*(volatile uint32_t*)0x4001080C)
void delay()
{
	int i;
	for(i=0;i<1000000;i++)
	{}
		
}
/*int main(void)
{
	RCC->APB2ENR |= 0x10;
	GPIOC->CRH &= 0xff0fffff;
	GPIOC->CRH |= 0x00300000;
	GPIOC->ODR=8192;
	
	//return 0;
	while(1)
	{
		GPIOC->ODR=8192;
		delay();
		GPIOC->ODR=0;
		delay();
	}
}
// options for target->debug->use stlink debugger(in the right side)
// build->load->debug->run. for transfering the instruction to the flash memory......
int main()
{
	RCC_APB2ENR |= (1UL<<2);
	GPIOA_CRL &= ~(15UL<<20);
	GPIOA_CRL |= (3UL<<20);
	
	
	while(1)
	{
		GPIOA_ODR ^= (1UL<<5);
		delay();
		GPIOA_ODR ^= (1UL<<5);
		delay();
	}
}*/
int main()
{
	RCC->APB2ENR |= (1UL<<4);
	GPIOC->CRH &= ~(15UL<<20);
	GPIOC->CRH |= (3UL<<20);
	while(1)
	{
		GPIOC->ODR ^= (1UL<<13);
		delay();
	}
}