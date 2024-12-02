#define UPRINTF_IMPLEMENTATION
#include "./libs/uprintf.h"

int main(void) {
    int arr[2] = {1,555};
    uprintf("uprintf's state: %S\n", &arr);
    arr[0] = 99;
    uprintf("uprintf's state: %S\n", &arr);
    return 0;
}