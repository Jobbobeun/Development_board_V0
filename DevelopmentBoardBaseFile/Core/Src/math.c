/*
 * math.c
 *
 *  Created on: May 11, 2020
 *      Author: nlrstem
 */

/**
 * @brief  Re-maps a number from one range to another
 * @param  x is the input value that is mapped
 * @param  in_min minimum of the input range
 * @param  in_max maximum of the input range
 * @param  out_min minimum of the output range
 * @param  out_max maximum of the output range
 */

long map(long x, long in_min, long in_max, long out_min, long out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
