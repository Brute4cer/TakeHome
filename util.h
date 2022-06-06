

#pragma once

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdbool.h>

/******************************************************************************
 * here are some convenience function to aid you in your development. you
 * do not need to utilize the functions if they are not helpful for you
 ******************************************************************************/

/* convenience function. if the debug flag is set, this will become a call to
 * printf. if the debug flag is not set, this call will be ignored */
int print_debug_log(const char *format, ...);

/* set the weight the motor is currently generating. this weight will be applied
 * instantaneously. it is up to you to make subsequent calls to this function
 * to get a weight ramp that follows the bounds of the question - instead of
 * applying the weight, this emulation hardware just logs this to the output
 * file provided in order to generate a plot */
void apply_weight(float weight_lbs);

/* get the starting weight or current weight as set by the command line option */
uint8_t get_start_weight(void);

/* get the ending or desired weight as set by the command line option */
uint8_t get_end_weight(void);

/* this option is false unless the -d flag is set on the cmd line
 * (i.e. "./solution -d") */
bool get_is_debug(void);

/* get the current system time in us */
uint64_t current_timestamp_us(void);

