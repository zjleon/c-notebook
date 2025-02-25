#include <stdio.h>
#include <math.h>

// 验证resultValue是不是该列最小,是返回1,否返回0
int getMinOnCol(int *firstAddress, int totalRowNum, int totalColNum, int *resultColNum, int resultValue) {
    for (int i=0; i<totalRowNum; i++) {
        int *currentItem = (firstAddress+i*totalColNum+*resultColNum);
        // printf("%d|%d\n", *currentItem, resultValue);
        if (*currentItem < resultValue) {
            return 0;
        }
    }
    return 1;
}
int getMaxOnRow(int *firstAddress, int totalRowNum, int totalColNum, int *resultRowNum, int *resultColNum, int *resultValue) {
    for (int i=0; i<totalRowNum; i++) {
        for (int j=0; j<totalColNum; j++) {
            int *currentItem = (firstAddress+i*totalColNum+j);
            // printf("%d\n", *currentItem);
            if(*currentItem>*resultValue) {
                *resultValue = *currentItem;
                *resultRowNum = i;
                *resultColNum = j;
            }
        }
        int isMinOnCol = getMinOnCol(firstAddress, totalRowNum, totalColNum, resultColNum, *resultValue);
        // 找到符合条件的元素就直接结束函数,否则重置resultValue
        if (isMinOnCol==1) return 0;
        else *resultValue = -1;
    }
    return 1;
}
int getSaddlePoint(int *firstAddress, int rows, int cols) {
    int rowNum, colNum, temp1=-1;
    getMaxOnRow(firstAddress, rows, cols, &rowNum, &colNum, &temp1);
    
    if (temp1 != -1) {
        printf("a[%d][%d]=%d\n", rowNum, colNum, temp1);
    } else {
        printf("not found\n");
    }
    return 0;
}
int Q1() {
    int matrix1[4][4] = {{1,7,4,1},{4,8,3,6},{1,6,1,2},{0,7,8,9}};
    int matrix2[2][2] ={{1,7},{4,1}};
    getSaddlePoint(&matrix1[0][0], 4, 4);
    getSaddlePoint(&matrix2[0][0], 2, 2);
    
    return 0;
}
// double factor(int n) {
//     double result=1;
//     for(double i=1; i<=n ; i++) {
//         result*=i;
//     }
//     return result;
// }
// double Q2() {
//     int input1 = 5;
//     double result=0;
//     for(double i=1; i<=input1 ; i++) {
//         result+=factor(i);
//     }
//     printf("result=%.0f\n", result);
//     return 0;
// }


int main() {
    Q1();
    // Q2();
    return 0;
}