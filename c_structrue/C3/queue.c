#define UPRINTF_IMPLEMENTATION
#include "../libs/uprintf.h"
#define ElemType char
#include <string.h>

struct QNode {
    ElemType data;
    struct QNode *next;
};
struct LinkQueue {
    struct QNode *front;
    struct QNode *rear;
};

int InitQueue(struct LinkQueue *queue) {
    queue->rear = queue->front = NULL;
    return 0;
}
bool IsQueueEmpty(struct LinkQueue *queue) {
    return queue->rear == NULL;
}
int GetFront(struct LinkQueue *queue, ElemType *e) {
    if (IsQueueEmpty(queue)) return 1;
    e = queue->front->data;
    return 0;
}
int EnQueue(struct LinkQueue *queue, ElemType e) {
    struct QNode *nodePtr = (struct QNode*)malloc(sizeof(struct QNode));
    nodePtr->data = e;
    nodePtr->next = NULL;
    if (queue->rear != NULL) {
        // change the next pointer of last node to new node
        queue->rear->next = nodePtr;
    } else {
        // if queue is empty, also change the front pointer
        queue->front = nodePtr;
    }
    // change the rear pointer of queue to new node
    queue->rear = nodePtr;
    return 0;
}
int DeQueue(struct LinkQueue *queue, ElemType *e) {
    if (IsQueueEmpty(queue)) return 1;
    e = queue->front->data;
    struct QNode *tmpPtr = queue->front;
    if (queue->front == queue->rear) {
        // in this case, queue has only 1 element
        queue->rear = NULL;
    }
    // change the next pointer of first node to the node next to it
    queue->front = queue->front->next;
    free(tmpPtr);
    return 0;
}

int testQueue() {
    struct LinkQueue q;
    InitQueue(&q);
    bool isEmpty = IsQueueEmpty(&q);
    uprintf("is empty queue: %S\n", &isEmpty);
    EnQueue(&q, "a");
    ElemType tmpStr;
    GetFront(&q, tmpStr);
    isEmpty = IsQueueEmpty(&q);
    uprintf("%S\n el:%S\n is empty:%S\n", &q, &tmpStr, &isEmpty);

    DeQueue(&q, &tmpStr);
    isEmpty = IsQueueEmpty(&q);
    uprintf("%S\n el:%S\n is empty:%S\n", &q, &tmpStr, &isEmpty);
    return 0;
}

int main() {
    return testQueue();
}