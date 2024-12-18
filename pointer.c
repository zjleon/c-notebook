#include <stdio.h>
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

    int a = 1;
    // !,--都是左结合,所以变量左边的优先算第二个式子先!,再--
    printf("%d\n%d\n", !--a, !a--);
    return 0;
    
}
