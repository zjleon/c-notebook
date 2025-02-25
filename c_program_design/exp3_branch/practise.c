#include <stdio.h>
#include <math.h>

int Q1() {
    int input1 = 5;
    double result=0;
    for(double i=1; i<=5 ; i++) {
        result+=pow(2, i);
    }
    printf("result=%.0f\n", result);
    
    return 0;
}
double Q2() {
    int input1 = 5;
    double result=0;
    for(double i=1; i<=5 ; i++) {
        result+=pow(2, i);
    }
    printf("result=%.0f\n", result);
    return 0;
}


int main() {
    Q1();
    return 0;
}