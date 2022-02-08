#include <stdio.h>
#include "logic.h"
#include "complement.h"
#include "conversion.h"
#include "arithmetic.h"
#define MAX 8//Byte = 8 bits



int main(void) {
    setbuf(stdout, NULL);



    int x[MAX];
    int y[MAX];
    int command;
    int command2;

    //loop stopper variable
    int loop = 0;

    while(loop ==0){
        printf("#please enter the command number:\n");
        printf("0) Exit\n1) Addition in signed-2's complement \n2) subtraction in signed-2's complement \n");
        scanf("%d", &command);
        //makes sure user enter the correct i
        // input for command

        switch(command){
            case 1:
                //first binary number
                //these next loops make sure that the user
                // enters the correct input format.
                printf("Enter the first binary number:\n");

                for(int i=0; i < MAX; i = i + 1){
                    while(1){
                        printf("x%d = ", i+1);
                        scanf("%d", &x[i]);
                        if(x[i] == 1 || x[i] == 0){
                            break;
                        }
                        else{
                            printf("Invalid entry; Try again!\n");
                            continue;
                        }
                    }
                }

                //second binary number
                printf("Enter the second binary number:\n");

                for(int i=0; i < MAX; i = i + 1){
                    while(1){
                        printf("y%d = ", i+1);
                        scanf("%d", &y[i]);
                        if(y[i] == 1 || y[i] == 0){
                            break;
                        }
                        else{
                            printf("Invalid entry; Try again!\n");
                            continue;
                        }
                    }
                }

                printf("\nEnter the out-put base:\n1) Binary \n2)Octal \n3)Decimal \n4)Hexadecimal\n");
                while(1){
                    scanf("%d" , &command2);

                    if(command2 == 1 || command2==2 || command2==3 || command2==4){
                        break;
                    }
                    else{
                        printf("Enter a valid number!\n");
                        continue;
                    }
                }

                int z[MAX];

                //the place to call the addition func
                func_signed_2s_addition(x,y,z);




                //this condition checks if there was an over flow in the function

                if(z[0] == 5 ){
                    printf("Error detected! An OverFlow Happened During The Process\n");
                    printf("___________________(- _ - ) ( - _ -)___________________ \n");
                }

                else {
                    printf("\nThe 1st number + 2nd number yield:\n");
                    if (command2 == 1) {
                        for (int i = 0; i < MAX; i = i + 1) {
                            printf("%d ", z[i]);
                        }
                    } else if (command2 == 2) {
                        to_octal(z);
                    } else if (command2 == 3) {
                        to_decimal(z);
                    } else if (command2 == 4) {
                        to_hexadecimal(z);
                    }

                    puts("");
                    puts("___________________________________________");
                }

                break;//this is for the case1



            case 2:
                //first binary number
                //these nexted loops make sure that the user
                // enters the correct input format.
                printf("Enter the first binary number:\n");

                for(int i=0; i < MAX; i = i + 1){
                    while(1){
                        printf("x%d = ", i+1);
                        scanf("%d", &x[i]);
                        if(x[i] == 1 || x[i] == 0){
                            break;
                        }
                        else{
                            printf("Invalid entry; Try again!\n");
                            continue;
                        }
                    }
                }

                //second binary number
                printf("Enter the second binary number:\n");

                for(int i=0; i < MAX; i = i + 1){
                    while(1){
                        printf("y%d = ", i+1);
                        scanf("%d", &y[i]);
                        if(y[i] == 1 || y[i] == 0){
                            break;
                        }
                        else{
                            printf("Invalid entry; Try again!\n");
                            continue;
                        }
                    }
                }
                printf("\nEnter the out-put base:\n1) Binary \n2)Octal \n3)Decimal \n4)Hexadecimal\n");
                while(1){
                    scanf("%d" , &command2);

                    if(command2 == 1 || command2==2 || command2==3 || command2==4){
                        break;
                    }
                    else{
                        printf("Enter a valid number!\n");
                        continue;
                    }
                }
                //these conditional statements:
                //they check whether the sign of the second number would be same as the first one
                // and if yes , so we would perform addition ( after changing the sign ) instead of subtraction

                func_signed_2s_subtraction(x,y,z);



                if(z[0] == 5 ){
                    printf("Error detected! An OverFlow Happened During The Process\n");
                    printf("___________________(- _ - ) ( - _ -)___________________ \n");
                }

                else {
                    printf("\nThe 1st number - 2nd number yield:\n");
                    if (command2 == 1) {
                        for (int i = 0; i < MAX; i = i + 1) {
                            printf("%d ", z[i]);
                        }
                    } else if (command2 == 2) {
                        to_octal(z);
                    } else if (command2 == 3) {
                        to_decimal(z);
                    } else if (command2 == 4) {
                        to_hexadecimal(z);
                    }

                    puts("");
                    puts("___________________________________________");
                }

                break;//this is for the case2




            case 0 :
                printf("_______________________\n");
                printf("\\(^-^)/Good bye \\(^-^)/\n");
                printf("_______________________\n");
                loop =1 ;

                break;





            default:
                puts("invalid input, try again.");
                continue;
        }//this is for switch


    }//this is for the while(1)


    return 0;
}





