#include <stdio.h>
#include "NumClass.h"

int main(){
    int start , end;
    printf("Please enter the first number from which the check will start""\n");
    scanf("%d", &start);
    printf("Please enter the second number that will determine the check range""\n");
    scanf("%d", &end);

    printf("the prime numbers between %d to %d are : ",start,end);
    for (int i = start; i < end; i++) {
        if(isPrime(i))
            printf("%d" ,i);
    }
    printf("\n");

    printf("the Armstrong numbers between %d to %d are : ",start,end);
    for (int i = start; i < end; i++) {
        if(isArmstrong(i))
            printf("%d" ,i);
    }
    printf("\n");

    printf("the Strong numbers between %d to %d are : ",start,end);
    for (int i = start; i < end; i++) {
        if(isStrong(i))
            printf("%d" ,i);
    }
    printf("\n");

    printf("the Palindrome numbers between %d to %d  are : ",start,end);
    for (int i = start; i < end; i++) {
        if(isPalindrome(i))
            printf("%d" ,i);
    }
    printf("\n");

    return 0;
}