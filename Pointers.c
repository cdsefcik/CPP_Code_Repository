#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * This program defines and initializes a pointer. Prints out the values
 * The second part of this program swaps numbers using a pointer. 
 */

void intSwap(int *num1, int *num2){
int temp = *num1;
*num1 = *num2;
*num2 = temp;
printf("The numbers are swapped: ");
};


int main()
{

//Define and initialize and print out the values of a pointer.
int number = 12;
int* numberpoint = &number;

printf("This is the number %d| numberpoint %p| numberpointvalue %d| number address %p| \n", number, numberpoint, *numberpoint, &number);

char a = 'A';
char *ptr = &a;

printf("1 | %c, %c, %u, %X \n", a, *ptr, (uint64_t)ptr, &a);

char b = 'B';
ptr = &b;

//Swap Numbers
int number1 = 10;
int number2 = 12;

int *num1 = &number1;
int *num2 = &number2;

intSwap(num1, num2);

printf("The number 1 is: %d \n", number1);
printf("The number 2 is: %d \n", number2);
    
    return EXIT_SUCCESS;
}
