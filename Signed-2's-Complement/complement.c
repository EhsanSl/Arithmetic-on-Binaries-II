#include <stdio.h>
#include "complement.h"
#include "logic.h"
#include "conversion.h"
#define MAX 8

void func_1s_comp(int a[], int result[]){
    func_not(a, result);
}

void func_2s_comp(int a[], int result[]){
    func_not(a, result);

    int i = MAX -1 ;
    while(i>=0){
        if(result[i] == 0){
            result[i] = 1;
            break;
        }
        else if(result[i] == 1){
            result[i] = 0;
            i--;
        }

    }

}


void func_2s_comp_star(int a[], int result[]){
    int i = MAX -1 ;

    while( i >= 0){
        if(a[i] == 1){
            result[i] = a[i];
            //this for loop NOT every binary number
            // skip the 1 st one we found
            break;
        }
            //skipping the zeros to get to the first 1
        else if (a[i] == 0){
            result[i] = a[i] ;
            i = i - 1  ;
        }
    }

    //this is for the one we skip ,
    // we assign it separately.

    i = i -1 ;

    //now NOT all the numbers before the 1.
    while(0 <= i ){
        if(a[i] == 1){
            result[i] = 0 ;
            i --;
        }
        else if (a[i] ==0){
            result[i] = 1;
            i--;
        }
    }
}
