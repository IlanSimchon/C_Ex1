#include <stdio.h>
#include <math.h>
#include "NumClass.h"

#define FALSE 0
#define TRUE 1

/* A method that calculates a number in a power given a base and a power using recursion */

int powerRec(int base, int exponent) {
    if (exponent != 0) {
        return base * powerRec(base, exponent - 1);
    }
    else {
        return 1;
    }
}
/* the method will take a number and return the reverse of that number using recursion*/

int reverseRec(int n){
    int remainder;
    if (n != 0) {
        remainder = n % 10;
        return ((remainder) * powerRec(10,(int) log10(n)) + reverseRec(n / 10));
    }
    else
        return FALSE;
    }

/* The method will return if a number is a palindrome using recursion */

int isPalindrome(int n) {
    if (n == reverseRec(n)) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}


/* A method will take an input of a number and calculate its number of digits using recursion */

int countDigitsRec(int n) {
    if(n == 0)
        return 0;
    return countDigitsRec(n/10) + 1;
}

/* will return if a number is Armstrong number */
/* An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits */

    int isArmstrongRec(int n, int size) {
        if (n > 0)
            return (powerRec( n%10, size) + isArmstrongRec(n/10, size));
    return FALSE;
}

int isArmstrong(int n)
{
    int input = n;
    int counter_digit = countDigitsRec(n);

    if (n==isArmstrongRec(input,counter_digit))
        return TRUE;
    else
        return FALSE;
}
