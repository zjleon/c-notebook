#define UPRINTF_IMPLEMENTATION
#include "../libs/uprintf.h"
#define ElemType int

typedef struct LinkList{
    // only store head pointer
    // other nodes are linked when created
    struct LNode *head;
    int Length;
} LinkList;
typedef struct LNode{
    /* data */
    ElemType data;
    struct LNode *next;
};



// void createNode(LinkList L, int data) {

// }

void main() {
    struct LinkList list;
    
}