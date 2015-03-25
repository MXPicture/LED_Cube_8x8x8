/*
 * cube.h
 *
 *  Created on: 24.03.2015
 *      Author: tobiasbildner
 */

#define CUBE_SIZE	(8)
#define CUBE_BYTES	(64)

volatile unsigned char cube[CUBE_SIZE][CUBE_SIZE];

volatile unsigned char buffer[CUBE_SIZE][CUBE_SIZE];
