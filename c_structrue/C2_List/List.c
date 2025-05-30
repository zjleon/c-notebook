#include <stdio.h>
#include <stdlib.h>
#define Size 5
#define ElemType int
typedef struct Table{
    ElemType * head;
    int length;
    int size;
}table;
table initTable(){
    table t;
    // declare a space in memory which size is defined in the second parenthsis
    // then cast this space to int typed pointer
    // finally assign the int typed pointer to t.head
    t.head=(ElemType *)malloc(Size*sizeof(ElemType));
    if (!t.head)
    {
        printf("初始化失败");
        exit(0);
    }
    t.length=0;
    t.size=Size;
    return t;
}
//输出顺序表中元素的函数
void displayTable(table t){
    for (int i=0;i<t.length;i++) {
        printf("%d ",t.head[i]);
    }
    printf("\n");
}
void add(table * t, ElemType value){
    printf(t);
    // int index = t.length;
    // // printf("%d, %d\n", index, value);
    // t.head[index] = value;
    // t.length++;
    // return t;
}
int main(){
    table t=initTable();
    table*ptr = &t;
    //向顺序表中添加元素
    for (int i=1; i<=Size; i++) {
        add(ptr, i);
    }
    printf("顺序表中存储的元素分别是：\n");
    displayTable(t);
    return 0;
}