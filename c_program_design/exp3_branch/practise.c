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
double factor(int n) {
    double result=1;
    for(double i=1; i<=n ; i++) {
        result*=i;
    }
    return result;
}
double Q2() {
    int input1 = 5;
    double result=0;
    for(double i=1; i<=input1 ; i++) {
        result+=factor(i);
    }
    printf("result=%.0f\n", result);
    return 0;
}


int main() {
    // Q1();
    Q2();
    return 0;
}