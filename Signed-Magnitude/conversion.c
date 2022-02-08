
#include <stdio.h>
#include "conversion.h"
#include <math.h>


void to_octal(int a[]){


    double octal= 0 ;
    int decimal = 0 ;
    int j = 0 ;

    if(a[0] == 1){
        printf("-");
    }

    for(int i = 7 ; i >0 ; i--){
        decimal += a[i] * pow(2,j++);
    }


    int i = 0;
    for(int k = decimal ; k > 0 ; ){
        int rem = 0;
        rem = k % 8 ;
        octal += (rem * pow(10,i++));
        k = floor(k/8);
    }

    printf("ANS = %d" , decimal );


}



void to_decimal(int a[]){
    int decimal = 0 ;
    int j = 0 ;

    if(a[0] == 1){
        printf("-");
    }

    for(int i = 7 ; i >0 ; i--){
        decimal += a[i] * pow(2,j++);

    }
    printf("ANS = %d\n" ,decimal);
}




void to_hexadecimal(int a[]){

    int i = 0 ;

    if(a[0] == 1){
        printf("-");
    }
    i++;
    int first_half = (a[i++]*8) + (a[i++]*4) +(a[i++]*2) + (a[i++]*1);
    int second_half = (a[i++]*8) + (a[i++]*4) +(a[i++]*2) + (a[i]*1);
    char b , c ;
    b = first_half;
    c = second_half;

    puts("ANS = ");

    if(a[0] == 1){
        printf("-");
    }
    if (first_half > 9 ){
        b = b +87;
        printf("%c" , b);
    }
    else if(first_half <= 9 ){
        printf("%d" , first_half);
    }
    if (second_half > 9 ){
        c = c + 87;
        printf("%c" , c);
    }
    else if(second_half <= 9 ){
        printf("%d" , second_half);
    }



}

/*
 *
 * to change 10 to a we can add it by 55 in the ascii table
 *
*/
