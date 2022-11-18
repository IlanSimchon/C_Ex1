
/* The function will return if a number is a palindrome */

#include <stdio.h>
#include <math.h>

#define FALSE 0
#define TRUE 1

int isPalindrome(int n) {
    int input, remainder, reverse = 0;
    printf("Please enter an integer to check and then press Enter or Control+Z");
    scanf("%d", &n);
    input = n;
    while (n != 0)
        {
            remainder = n % 10;
            reverse = reverse * 10;
            reverse += remainder;
            n = n / 10;
        }
    if (input == reverse)
        {
            printf("The number %d is palindrome\n", input);
            return TRUE
        }
    else
        {
            printf("The number %d is not a palindrome\n", input);
            return FALSE
        }
    return FALSE
}

/* A helper function that calculates how many digits are in the input */

int countDigits (int n)
{
    int counter_digit = 0;
    while (n != 0)
        {
            n = n / 10;
            ++counter_digit;
        }
    return counter_digit ;
}

/* will return if a number is Armstrong number*/
/* An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits */

int isArmstrong(int n) {
    int remainder, input, counter_digit,sum = 0;
    printf("Please enter an integer to check and then press Enter or Control+Z");
    scanf("%d", &input);
    if (n == 0) return TRUE;
    input = n;
    counter_digit = countDigits(n);

    while (n > 0)
        {
            remainder = n % 10;
            sum += pow(remainder, counter_digit);
            n = n / 10;
        }
    if (input == sum)
        {
            printf("The number %d is Armstrong\n", input);
            return TRUE;
        }
    else
        {
            printf("The number %d is not Armstrong\n", input);
            return FALSE;
        }
}