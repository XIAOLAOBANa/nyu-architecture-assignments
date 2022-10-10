/* Author: JoannaKl
 * 
 * This program performs basic operations on floating 
 * point numbers to illustrate how they are encoded 
 * using the IEEE754 standard. It reads a sequence of 
 * floating point numbers from the standard input stream
 * and outputs the results to the standard output stream.
 * The input is terminated by a zero.
 * 
 * DO NOT MODIFY THIS FILE
 * 
 */
 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "float.h"

int is_special ( float f ) ;
int get_s ( float f );
int get_E ( float f ) ;
float get_M  ( float f );



int is_special ( float f ) {
    if (get_E(f) == 255)
        return 1;
    return 0;

}


int get_s ( float f ) {
    int *num = (int*)(&f);
	if((*num >> 31) & 1)
	    return -1;
    return 1;
}


int get_E ( float f ) {
	int *num = (int*)(&f);
    // int exponet = (*num >> 23) | (0b011111111);
    unsigned char exponet = (*num >> 23);
    if (exponet == 0)
        return  -126;
    else if(exponet == 255)
        return 255;
    else
        return exponet - 127;
}

float get_M  ( float f ) {
    int *num = (int*)(&f);
    int s1 = ((*num) & 0x007fffff) | 0x3f800000;
    // int s1 = (*num & 0x7fffff);
    // printf("%d\n", s1);
    // float temp = s1 * pow(2, -23) + 1;
    
    // if(f == INFINITY || f == -INFINITY)
    //     return 0;
    // else if(f == NAN || f == -NAN)
    //     return 0.5;
    // else if(get_E(f) == -126)
    //     return *(float*)(&s1) - 1;
    // else
    //     return *(float*)(&s1);

    if(get_E(f) == -126)
        return *(float*)(&s1) - 1; 
    else if(get_E(f) == 255)
        if (f == INFINITY || f == -INFINITY)
            return 0;
        else
            return 0.5;
    else
        return *(float*)(&s1); 
}



int main() {
    
    
    float value;
    int E;
    float M;
    int sign; 
    
    //continue reading values until failure or zero
    while ( scanf("%f", &value) > 0 && value != 0 ) {
        
        //disassemble the number into the three parts 
        sign = get_s ( value );

        E = get_E ( value ) ;

        M = get_M  ( value );
        
        //print each of the three parts 
        printf("%d %d %22.20f\n", sign, E, M); 
        
        //display recalculated value based on the three parts 
        if (! is_special(value) ) {
            //use pow() not shifts since E may be larger than 32
            printf("%.50f\n\n", sign * M * pow(2,E)  ) ; 
        }
        else if (M==0.0){ //these values are infinity
            
            printf("%.50f\n\n", sign*INFINITY  ) ; 
        }
        else { //these values are not numbers 
            printf("%.50f\n\n", sign*NAN  ) ; 
        }
        
    }
	

	return 0;
}




