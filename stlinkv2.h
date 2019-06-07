#ifndef __STM32F101_H__
#define __STM32F101_H__

#include <stdint.h>

typedef struct {
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
} RCC_TypeDef;

typedef struct {
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
} GPIO_TypeDef;


#define PERIPH_BASE     ((uint32_t)0x40000000)
#define APB2PERIPH_BASE (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE  (PERIPH_BASE + 0x20000)
#define RCC_BASE        (AHBPERIPH_BASE + 0x1000)
#define RCC             ((RCC_TypeDef *)RCC_BASE)
#define GPIOA_BASE      (APB2PERIPH_BASE + 0x0800)
#define GPIOA           ((GPIO_TypeDef *)GPIOA_BASE)

#endif /* !__STM32F101_H__ */
