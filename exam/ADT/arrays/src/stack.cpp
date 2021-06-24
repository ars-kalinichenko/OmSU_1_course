#include "include/stack.h"

bool Stack::push(int x) {
    if (isFull()) return false;
    arr[++top] = x;
    return true;
}

bool Stack::isFull() const {
    return top >= (MAX - 1);
}

bool Stack::isEmpty() const {
    return top < 0;
}

int Stack::pop() {
    if (isEmpty()) return -1;
    return arr[top--];
}

int Stack::peek() {
    if (isEmpty()) return -1;
    return arr[top];
}
