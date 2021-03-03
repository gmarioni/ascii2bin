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
    int number = 0;
    int retval = 1;
    int maxNumber = 0;
    char ascii_value;
    int digit = 0;
    int returnVAlue = 0;
    read(STDIN_FILENO, &ascii_value, 1);
    while (retval == 1){

        if(ascii_value == 10 /* add in null */){
            break;
        }
        if(ascii_value != '0' && ascii_value != '1'){
            returnVAlue =  1;
            break;
        }
        /* recall lecture 2/23 slide title: Base N to Base10
        the way to go from binary to base 10 was v = v*2+d
        WHERE d is the binary digit. SO, "digit" here gets the
        binary digit from the .txt file ONE at a time. THEN it isn't
        getting a 1 or a 0, it's actually getting a 48 or a 49 
        (the ascii encoding of 0 or 1 respectively), SO 48 has
        to be subtracted to actually get a 0 or 1. From there
        number = (number << 1) + digit is the v = v*2+d from lecture */
        digit = ascii_value - offset;
        /* what line 39 does is the conversion from base
        N to Base 10 slide (lecture 2/23: v=v*2+d) 
        WHICH is why number starts at 0. So the first iteration
        is v= 0*2 + 1  WHERE the 1 was read from the read() call.
        The result is 1. The next iteration is 
        1 (which is the result from last time) *2 + 0 WHERE 0 was
        read from the read() call. The RESULT is 2. The next iteration is
        2*2+0 (again from read call). RESULT is 4. The loop iterates
        and reads in all the 1's and 0's one at a time from the file it
        read in */
        number = (number << 1) + digit;  
        //printf("%u", number);
        retval = read(0, &ascii_value, 1);
        

    }
        
    /* this print is what returns the unsigned decimal by using '%u' */    
    printf("%u\n", number);
    return returnVAlue;
    }