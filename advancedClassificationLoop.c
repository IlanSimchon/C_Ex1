#include <stdio.h>
#include "NumClass.h"

#define FALSE 0
#define TRUE 1

/* The function will return if a number is a palindrome */

int isPalindrome(int n) {
        int input=n, remainder, reverse = 0;
        while (n != 0) {
            remainder = n % 10;
            reverse = reverse * 10;
            reverse += remainder;
            n = n / 10;
        }
        if (input == reverse) {
            return TRUE;
        } else {
            return FALSE;
        }
    }

/* A method will take an input of a number and calculate its number of digits */

int countDigits(int n) {
    int counter_digit = 0;
    while (n!=0) {
        n = n/10;
        ++counter_digit;
        }
        return counter_digit;
}
/* A method that calculates a number in a power given a base and a power */

int power(int base,int exponent) {
    int result=1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

/* will return if a number is Armstrong number */
/* An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits */

int isArmstrong(int n) {
    int remainder, input=n, counter_digit, sum = 0;
    if (n == 0) return TRUE;
    counter_digit = countDigits(n);

    while (n > 0) {
        remainder = n % 10;
        sum += power(remainder, counter_digit);
        n = n / 10;
    }
    if (input == sum) {
        return TRUE;
    } else {
        return FALSE;
    }
}