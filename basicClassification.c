#include "NumClass.h"
#include <stdio.h>
#include <math.h>

#define True 1;
#define False 0;

// help function for isStrong function
int factorial(int a) {
    if (a == 0)
        return 1;
    return factorial(a-1) * a;
}

int isPrime(int a) {
    int i;
    for(i = 2 ; i <= sqrt(a) ; i++){
        if(a % i == 0)
            return False;
    }
    return True;
}

int isStrong(int x) {
    if(x == 0) return False;
    int sum = 0 , a = 0, b = x;
    while (b != 0) {
        a = b % 10;
        sum += factorial(a);
        b = b / 10;
    }
    if(sum == x)
        return True
    return False;
}


