#include <stdio.h>
// 函数接受一个指向数组的指针
void print2DArray(int (*arr)[3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
// 定义一个函数，接受一个指向int类型的指针作为参数
void modifyValue(int *ptr) {
    // 通过指针解引用操作修改所指向的int变量的值
    *ptr = 100;
}
// 利用数组内部的连续性,传入第一个元素的地址,通过指针+n的方式来访问剩下的元素
void print2DArr2(int *firstAddress, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(firstAddress + i*cols + j));
        }
        printf("\n");
    }
}
void intermediateFunc(int *arr, int rows, int cols) {
    print2DArr2(arr, rows, cols);
}

int main() {
    // int (*p1)[3];
    // int a1[3];
    // p1 = &a1;

    // printf("%p\n", p1);
    // printf("%p\n", p1[0]);
    // printf("%p\n", p1[1]);
    // printf("%p\n", p1[2]);

    // int *p2[3];
    // int a2[3];
    // p2[0] = &a2[0];
    // p2[1] = &a2[1];
    // p2[2] = &a2[2];

    // printf("%p\n", p2);
    // printf("%p\n", p2[0]);
    // printf("%p\n", p2[1]);
    // printf("%p\n", p2[2]);

    // 左侧指针运算
    // int arr[2] = {1,2};
    // int *p3 = &arr;
    // printf("%p\n", p3);
    // // 先指针取值,然后赋值,最后++,指针指向数组下一个元素
    // *p3++ = 4;
    // printf("%d, %d, %p\n", arr[0], arr[1], p3);
    // // 重置指针
    // *p3 = &arr;
    // // 先移动指针,然后取值,最后赋值
    // *(p3++) = 5;
    // printf("%d, %d, %p\n", arr[0], arr[1], p3);

    // int a = 1;
    // // !,--都是左结合,所以变量左边的优先算第二个式子先!,再--
    // printf("%d\n%d\n", !--a, !a--);

    int arr[][3] = {{1, 2, 3}, {4, 5, 6}};
    int rows = sizeof(arr) / sizeof(arr[0]);
    printf("\nmethod1:\n");
    print2DArray(arr, rows);
    printf("\nmethod2:\n");
    print2DArr2(&arr[0][0], 2, 3);
    printf("\nmethod3:\n");
    intermediateFunc(&arr[0][0], 2, 3);

    int num = 10;
    modifyValue(&num);
    return 0;
    
}
