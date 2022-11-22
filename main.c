#include <stdio.h>
#include "NumClass.h"

int main(){
    int start , end;
    scanf("%d", &start);
    scanf("%d", &end);

    // Armstrong
    printf("The Armstrong numbers are:");
    for (int i = start; i < end; i++) {
        if(isArmstrong(i))
            printf(" %d" ,i);
    }
    printf("\n");

    // Palindrome
    printf("The Palindromes are:");
    for (int i = start; i < end; i++) {
        if(isPalindrome(i))
            printf(" %d" ,i);
    }
    printf("\n");

    // Prime
    printf("The Prime numbers are:");
    for (int i = start; i < end; i++) {
        if(isPrime(i))
            printf(" %d" ,i);
    }
    printf("\n");

    //Strong
    printf("The Strong numbers are:");
    for (int i = start; i < end; i++) {
        if(isStrong(i))
            printf(" %d" ,i);
    }
    printf("\n");



    return 0;
}