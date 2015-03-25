/*
 * draw.h
 *
 *  Created on: 24.03.2015
 *      Author: tobiasbildner
 */

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "cube.h"

GPIO_InitTypeDef GPIO_InitStructure;

#define GPIOA_USED	(0xE502)
#define GPIOB_USED	(0xFFFF)
#define GPIOC_USED	(0xFFFF)
#define GPIOD_USED	(0x0BDF)
#define GPIOE_USED	(0xFFFF)
#define GPIOH_USED	(0x0003)

#define GPIOA_USED_WO_LAY	(0xC402)
#define GPIOB_USED_WO_LAY	(0xFFFF)
#define GPIOC_USED_WO_LAY	(0xFC3F)
#define GPIOD_USED_WO_LAY	(0x01DF)
#define GPIOE_USED_WO_LAY	(0xFFFF)
#define GPIOH_USED_WO_LAY	(0x0003)

#define GPIOA_USED_LAY		(0x2800)
#define GPIOC_USED_LAY		(0x03C0)
#define GPIOD_USED_LAY		(0x0A00)

volatile uint16_t valueA;
volatile uint16_t valueB;
volatile uint16_t valueC;
volatile uint16_t valueD;
volatile uint16_t valueE;
volatile uint16_t valueH;

void initGPIO(void);
void activateLayer(uint8_t i);
void deactivateLayers(void);
void drawLayer(uint8_t layer[CUBE_SIZE]);
void drawRow(uint8_t row, uint8_t value);
void drawRow0(uint8_t value);
void drawRow1(uint8_t value);
void drawRow2(uint8_t value);
void drawRow3(uint8_t value);
void drawRow4(uint8_t value);
void drawRow5(uint8_t value);
void drawRow6(uint8_t value);
void drawRow7(uint8_t value);
