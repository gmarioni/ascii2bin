/********************************/
/* Program Name: ascii2bin.c     */
/* Author:   Gerardo Marioni     */
/* Date:    3-3-2021            */
/********************************/
/* Description:  program that converts ascii to binary */
/* Validation Checks:   none  */
/* Enhancements:       none     */
/********************************/
#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#define byte unsigned char

int main (int argc, char * argv[], char ** envp) {
    int offset = 48;
    unsigned char * number = 0;
    int retval;
    byte ascii_value[10];
    unsigned char * digit;
    retval = read(0, &ascii_value, 1);

    while (retval == 1)
        digit = ascii_value - offset;
        number = (number << 1) + digit;  
        retval = read(0, &ascii_value, 1);
        
    printf("%u\n", number);
    return 0;
    }