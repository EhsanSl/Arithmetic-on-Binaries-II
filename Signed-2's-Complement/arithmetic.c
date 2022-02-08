
#include "arithmetic.h"
#include "complement.h"
#include <math.h>
#include <stdio.h>
#define MAX 8


void func_signed_2s_addition(int a[], int b[], int result[]){
    int  i = 7 ;
    int car = 0 ;


    while (i >= 0){
        result[i] = a[i] + b[i] + car ;
        if(result[i] == 1 || result[i] ==0 ){
            car = 0 ;
        }

        else if (result[i]  == 2  ){
            car = 1 ;
            result [i] = 0 ;
        }
        else if (result[i]  == 3  ){
            car = 1 ;
            result [i] = 1 ;
        }
        i = i -1 ;
    }

    if( a[0]==b[0] && result[0]!=a[0]){
        result[0] = 5;
    }
}


void func_signed_2s_subtraction(int a[], int b[], int result[]){

    func_2s_comp(b,b);
    func_signed_2s_addition(a,b,result);
}



//________________________________________________________________________________________
//________________________________________________________________________________________

//these functions are for arithmetic in signed magnitude method

void func_signed_mag_addition(int a[], int b[], int result[]) {


    int  i = 7 ;
    int car = 0 ;


    result[0] = a[0] ;
    while (i > 0){
        result[i] = a[i] + b[i] + car ;
        if(result[i] == 1 || result[i] ==0 ){
            car = 0 ;
        }

        else if (result[i]  == 2  ){
            car = 1 ;
            result [i] = 0 ;
        }
        else if (result[i]  == 3  ){
            car = 1 ;
            result [i] = 1 ;
        }
        i = i -1 ;

        if(i == 0 ){
            if(car == 1){
                result[0] = 5  ; // this 5 will be check in the main menu , to inform the overflow

            }

        }


    }


}




void func_signed_mag_subtraction(int a[], int b[], int result[]){
    int decimal_b;
    int decimal_a;
    decimal_a = decimal(a);
    decimal_b = decimal(b);

    if (decimal_a >= decimal_b){
        result[0] = a[0];
    }
    else{
        result[0] =b[0];
    }

    int j = 7 ;
    int  lastBorrow =  0 ;
    int bor = 0 ;

    while( j > 0 ){
        if( a[j] >= b[j] ){
            result[j]  = a[j] - b[j] ;
        }
        else if ( a[j] < b[j]   ){
            int index = j - 1 ;
            //while (index >= 0 ) {
            //this is for time we need last borrow
            if (index ==  0){
                while( index != j-1){
                    a[index++] = 1;

                }
                a[index] = 0 ;
                a[j] = 1;
                lastBorrow = 1;
            }
                //this is for the time we need to borrow from others
            else {
                int ind = j -1 ;
                while(bor != 1 && ind != 0 ){

                    if( a[ind] == 1){
                        bor = 1 ;
                        a[ind] = 0;
                        while(ind != j-1 ){
                            a[ind] = 1 ;
                            ind ++ ;
                        }
                    }
                    else {
                        ind -- ;
                    }

                }
            }

        }
        result[j]  = a[j] - b[j];

        for(int i = 7;  i >= 0 ; i-- ){
            if(result[ i] == -1){
                result[i] = 1;
            }

        }
        -- j;

    }
    if (lastBorrow == 1){
        for(int i = 7;  i >= 0 ; i-- ){
            if(result[ i] == 1){
                result[i] = 0;
            }
            else {
                result [i] = 1 ;
            }
        }
    }



}



// this is a conversion function which returns an int value
// so we can compare the result of decimal and binary arithmetic to
// bre able to detect overflow .

int decimal(int a[]){
    int decimal = 0 ;
    int j = 0 ;
    for(int i = 7 ; i >0 ; i--){
        decimal += a[i] * pow(2,j++);

    }
    return decimal;
}