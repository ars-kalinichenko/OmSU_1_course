#include "include/stack.h"

#include "include/constants.h"
using namespace std;

bool Stack::push(char x) {
    if (top >= (MAX - 1)) {
        code = STACK_OVERFLOW;
        return false;
    } else {
        a[++top] = x;
        return true;
    }
}

char Stack::pop() {
    if (top < 0) {
        code = STACK_UNDERFLOW;
        return 0;
    } else {
        char x = a[top--];
        return x;
    }
}

char Stack::peek() {
    if (top < 0) {
        code = STACK_EMPTY;
        return 0;
    } else {
        char x = a[top];
        return x;
    }
}

bool Stack::isEmpty() const {
    return (top < 0);
}

int Stack::getCode() const {
    return code;
}
