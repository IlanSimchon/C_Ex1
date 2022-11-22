#include <stdio.h>
#include "NumClass.h"

int main(){
    int start , end;
    printf("Please enter the first number from which the check will start""\n");
    scanf("%d", &start);
    printf("Please enter the second number that will determine the check range""\n");
    scanf("%d", &end);

    // Armstrong
    printf("The Armstrong numbers are: ");
    for (int i = start; i < end; i++) {
        if(isArmstrong(i))
            printf("%d " ,i);
    }
    printf("\n");

    // Palindrome
    printf("The Palindrome numbers: ");
    for (int i = start; i < end; i++) {
        if(isPalindrome(i))
            printf("%d " ,i);
    }
    printf("\n");

    // Prime
    printf("The Prime numbers: ");
    for (int i = start; i < end; i++) {
        if(isPrime(i))
            printf("%d " ,i);
    }
    printf("\n");

    //Strong
    printf("The Strong numbers are: ");
    for (int i = start; i < end; i++) {
        if(isStrong(i))
            printf("%d " ,i);
    }
    printf("\n");



    return 0;
}