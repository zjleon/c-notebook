#define UPRINTF_IMPLEMENTATION
#include "../libs/uprintf.h"
#define ElemType char
#include <string.h>

struct Stacks {
    struct StackNode* top;
    struct StackNode* base;
    int length;
};
struct StackNode {
    ElemType elem;
    struct StackNode* next;
};

int initStack(struct Stacks *_stack) {
    _stack->length = 0;
    _stack->base = NULL;
    _stack->top = _stack->base;
    return 0;
}

int stackLength(struct Stacks *_stack) {
    return _stack->length;
}

void stackPush(struct Stacks *_stack, ElemType e) {
    int l = _stack->length;
    // struct StackNode node = {e, NULL};
    struct StackNode *node = (struct StackNode*)malloc(sizeof(struct StackNode));
    node->elem = e;
    node->next = NULL;
    if (l == 0) {
        // alter the base pointer in a null stack
        _stack->base = node;
    } else {
        // alter the pointer of the last node before inserting new node
        _stack->top->next = node;
    }
    _stack->top = node;
    // uprintf("%S\n", _stack->top);
    _stack->length += 1;
};
int stackPop(struct Stacks *_stack) {
    if (_stack->base == NULL) {
        return 1;
    }

    struct StackNode *ptr = _stack->base;
    while(ptr->next != _stack->top && ptr->next) {
        ptr = ptr->next;
    }
    
    _stack->length -= 1;
    // uprintf("%S\n", ptr->next);
    if (ptr->next != NULL) {
        ptr->next = NULL;
        free(_stack->top);
        _stack->top = ptr;
    } else {
        // free(_stack->top);
        free(_stack->base);
        _stack->base = NULL;
        _stack->top = NULL;
    }
    ptr = NULL;
    return 0;
};
ElemType stackLastElem(struct Stacks *_stack) {
    if (_stack->top == NULL) {
        return "";
    }
    return _stack->top->elem;
}

int main() {
    // struct Stacks stack1 = {NULL, NULL, 0, {}};
    struct Stacks stack1;
    initStack(&stack1);
    // stackPush(&stack1, '[');
    // // uprintf("%S\n", &stack1);
    // // stackPush(&stack1, '(');
    // // uprintf("%S\n", &stack1);
    // stackPop(&stack1);

    char sample1[] = "[(()())";
    int length = strlen(sample1);
    // printf("bb %d\n", length);
    char letter;
    for( int i = 0; i<length ; i++) {
        letter = stackLastElem(&stack1);
        // printf("aa %c\n", letter);
        // uprintf("%S\n", &stack1);
        if (sample1[i] == ']' && letter == '[') {
            stackPop(&stack1);
            // printf("1 %c|%c\n", letter, sample1[i]);
        } else if (sample1[i] == ')' && letter == '(') {
            stackPop(&stack1);
            // printf("2 %c|%c\n", letter, sample1[i]);
        } else {
            stackPush(&stack1, sample1[i]);
            // printf("3 %c|%c\n", letter, sample1[i]);
        }
    }
    // uprintf("%S\n", &stack1);
    if (stackLength(&stack1) > 0){
        return 1;
    } else {
        return 0;
    }
}



