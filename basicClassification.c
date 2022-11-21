#include "NumClass.h"
#include <stdio.h>
#include <math.h>


#define True 1;
#define False 0;

// help function for isStrong function
int factorial(int a) {
    if (a == 1 || a == 0)
        return 1;
    return factorial(a-1) * a;
}

int isPrime(int a) {
    int i;
    for(i = a-1 ; i > 1 ; i--){
        if(a % i == 0)
            return False;
    }
    return True;
}
int isStrong(int x) {
    int sum, a = 0, b = x;
    while (b != 0) {
        a = b % 10;
        sum += factorial(a);
        b = b / 10;
    }
    if(sum == x)
        return True
    return False;
}



