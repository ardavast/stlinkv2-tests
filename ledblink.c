#include "stlinkv2.h"

#define STACK_TOP 0x20002000

void nmi_handler(void);												
void hardfault_handler(void);
void delay(void); 
int main(void);

uint32_t *myvectors[4] 
__attribute__ ((section("vectors")))= {
    (uint32_t *)STACK_TOP,         
    (uint32_t *)main,              
    (uint32_t *)nmi_handler,       
    (uint32_t *)hardfault_handler  
};

int main(void)
{	
	RCC->APB2ENR |= 0x4; /* GPIOA clock enable */
	GPIOA->CRH = (GPIOA->CRH & ~(0xf0)) | 0x20; /* PA9 output max 2MHz, push-pull */

	for (;;) {
		GPIOA->BSRR = (1 << 9); /* set PA9 */
		delay();
		GPIOA->BSRR = (1 << (9 + 16)); /* reset PA9 */
		delay();
	}
}

void delay(void) 
{
	int i;

	for (i = 400000; i > 0; i--) {
		asm("nop");
	}
}

void nmi_handler(void)
{
	return;
}

void hardfault_handler(void)
{
	return;
}
