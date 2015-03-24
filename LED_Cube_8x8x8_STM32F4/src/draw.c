/*
 * draw.c
 *
 *  Created on: 24.03.2015
 *      Author: tobiasbildner
 */

#include "draw.h";

void gpio_init(void) {
	/* GPIOA Periph clock enable */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	/* Configure in output pushpull mode */
	GPIO_InitStructure.Pin = GPIOA_USED;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

	/* GPIOB Periph clock enable */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	/* Configure in output pushpull mode */
	GPIO_InitStructure.Pin = GPIOB_USED;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);

	/* GPIOC Periph clock enable */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	/* Configure in output pushpull mode */
	GPIO_InitStructure.Pin = GPIOC_USED;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);

	/* GPIOD Periph clock enable */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	/* Configure in output pushpull mode */
	GPIO_InitStructure.Pin = GPIOD_USED;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);

	/* GPIOE Periph clock enable */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
	/* Configure in output pushpull mode */
	GPIO_InitStructure.Pin = GPIOE_USED;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStructure);

	/* GPIOH Periph clock enable */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
	/* Configure in output pushpull mode */
	GPIO_InitStructure.Pin = GPIOH_USED;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOH, &GPIO_InitStructure);
}

uint8_t extractBit(uint8_t count, uint8_t value) {
	value <<= (7 - count);
	value >>= 7;
	return value;
}

void drawLayer(/*array*/) {
	valueA = 0x0000;
	valueB = 0x0000;
	valueC = 0x0000;
	valueD = 0x0000;
	valueE = 0x0000;
	valueH = 0x0000;

	for (uint8_t i = 0; i < 8; ++i) {
		drawRow(i, i);
	}

	// Reset Bits (just Rows not Layer-Activation-Bits)
	HAL_GPIO_WritePin(GPIOA, 0xC402, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, 0xFFFF, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, 0xFC3F, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOD, 0x01DF, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE, 0xFFFF, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOH, 0x0003, GPIO_PIN_RESET);

	// Set Bits
	HAL_GPIO_WritePin(GPIOA, valueA, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, valueB, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, valueC, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD, valueD, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE, valueE, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOH, valueH, GPIO_PIN_SET);
}

void drawRow(uint8_t row, uint8_t value) {
	switch (row) {
	case 0:
		drawRow0(value);
		break;
	case 1:
		drawRow1(value);
		break;
	case 2:
		drawRow2(value);
		break;
	case 3:
		drawRow3(value);
		break;
	case 4:
		drawRow4(value);
		break;
	case 5:
		drawRow5(value);
		break;
	case 6:
		drawRow6(value);
		break;
	case 7:
		drawRow7(value);
		break;
	default:
		break;
	}
}

void drawRow0(uint8_t value) {
	// Set Bits
	if (extractBit(0, value) != 0)
		valueC |= GPIO_PIN_1;

	if (extractBit(1, value) != 0)
		valueC |= GPIO_PIN_3;

	if (extractBit(2, value) != 0)
		valueA |= GPIO_PIN_1;

	if (extractBit(3, value) != 0)
		valueA |= GPIO_PIN_3;

	if (extractBit(4, value) != 0)
		valueA |= GPIO_PIN_5;

	if (extractBit(5, value) != 0)
		valueA |= GPIO_PIN_7;

	if (extractBit(6, value) != 0)
		valueC |= GPIO_PIN_5;

	if (extractBit(7, value) != 0)
		valueB |= GPIO_PIN_1;
}

void drawRow1(uint8_t value) {
	// Set Bits
	if (extractBit(0, value) != 0)
		valueE |= GPIO_PIN_7;

	if (extractBit(1, value) != 0)
		valueE |= GPIO_PIN_9;

	if (extractBit(2, value) != 0)
		valueE |= GPIO_PIN_11;

	if (extractBit(3, value) != 0)
		valueE |= GPIO_PIN_13;

	if (extractBit(4, value) != 0)
		valueE |= GPIO_PIN_15;

	if (extractBit(5, value) != 0)
		valueB |= GPIO_PIN_11;

	if (extractBit(6, value) != 0)
		valueB |= GPIO_PIN_13;

	if (extractBit(7, value) != 0)
		valueB |= GPIO_PIN_15;
}

void drawRow2(uint8_t value) {
	// Set Bits
	if (extractBit(0, value) != 0)
		valueC |= GPIO_PIN_0;

	if (extractBit(1, value) != 0)
		valueC |= GPIO_PIN_2;

	if (extractBit(2, value) != 0)
		valueA |= GPIO_PIN_2;

	if (extractBit(3, value) != 0)
		valueA |= GPIO_PIN_4;

	if (extractBit(4, value) != 0)
		valueA |= GPIO_PIN_6;

	if (extractBit(5, value) != 0)
		valueC |= GPIO_PIN_4;

	if (extractBit(6, value) != 0)
		valueB |= GPIO_PIN_0;

	if (extractBit(7, value) != 0)
		valueB |= GPIO_PIN_2;
}

void drawRow3(uint8_t value) {
	// Set Bits
	if (extractBit(0, value) != 0)
		valueE |= GPIO_PIN_8;

	if (extractBit(1, value) != 0)
		valueE |= GPIO_PIN_10;

	if (extractBit(2, value) != 0)
		valueE |= GPIO_PIN_12;

	if (extractBit(3, value) != 0)
		valueE |= GPIO_PIN_14;

	if (extractBit(4, value) != 0)
		valueB |= GPIO_PIN_10;

	if (extractBit(5, value) != 0)
		valueB |= GPIO_PIN_12;

	if (extractBit(6, value) != 0)
		valueB |= GPIO_PIN_14;

	if (extractBit(7, value) != 0)
		valueD |= GPIO_PIN_8;
}

void drawRow4(uint8_t value) {
	// Set Bits
	if (extractBit(0, value) != 0)
		valueH |= GPIO_PIN_0;

	if (extractBit(1, value) != 0)
		valueC |= GPIO_PIN_14;

	if (extractBit(2, value) != 0)
		valueE |= GPIO_PIN_6;

	if (extractBit(3, value) != 0)
		valueE |= GPIO_PIN_4;

	if (extractBit(4, value) != 0)
		valueE |= GPIO_PIN_2;

	if (extractBit(5, value) != 0)
		valueE |= GPIO_PIN_0;

	if (extractBit(6, value) != 0)
		valueB |= GPIO_PIN_8;

	if (extractBit(7, value) != 0)
		valueB |= GPIO_PIN_6;
}

void drawRow5(uint8_t value) {
	// Set Bits
	if (extractBit(0, value) != 0)
		valueB |= GPIO_PIN_4;

	if (extractBit(1, value) != 0)
		valueD |= GPIO_PIN_7;

	if (extractBit(2, value) != 0)
		valueD |= GPIO_PIN_3;

	if (extractBit(3, value) != 0)
		valueD |= GPIO_PIN_1;

	if (extractBit(4, value) != 0)
		valueC |= GPIO_PIN_12;

	if (extractBit(5, value) != 0)
		valueC |= GPIO_PIN_10;

	if (extractBit(6, value) != 0)
		valueA |= GPIO_PIN_14;

	if (extractBit(7, value) != 0)
		valueA |= GPIO_PIN_10;
}

void drawRow6(uint8_t value) {
	// Set Bits
	if (extractBit(0, value) != 0)
		valueH |= GPIO_PIN_1;

	if (extractBit(1, value) != 0)
		valueC |= GPIO_PIN_15;

	if (extractBit(2, value) != 0)
		valueC |= GPIO_PIN_13;

	if (extractBit(3, value) != 0)
		valueE |= GPIO_PIN_5;

	if (extractBit(4, value) != 0)
		valueE |= GPIO_PIN_3;

	if (extractBit(5, value) != 0)
		valueE |= GPIO_PIN_1;

	if (extractBit(6, value) != 0)
		valueB |= GPIO_PIN_9;

	if (extractBit(7, value) != 0)
		valueB |= GPIO_PIN_7;
}

void drawRow7(uint8_t value) {
	// Set Bits
	if (extractBit(0, value) != 0)
		valueB |= GPIO_PIN_5;

	if (extractBit(1, value) != 0)
		valueB |= GPIO_PIN_3;

	if (extractBit(2, value) != 0)
		valueD |= GPIO_PIN_6;

	if (extractBit(3, value) != 0)
		valueD |= GPIO_PIN_4;

	if (extractBit(4, value) != 0)
		valueD |= GPIO_PIN_2;

	if (extractBit(5, value) != 0)
		valueD |= GPIO_PIN_0;

	if (extractBit(6, value) != 0)
		valueC |= GPIO_PIN_11;

	if (extractBit(7, value) != 0)
		valueA |= GPIO_PIN_15;
}
