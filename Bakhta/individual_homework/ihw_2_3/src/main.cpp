#include <iostream>
#include <include/stack.h>
#include <cassert>

using namespace std;

bool reverseStack(Stack *, int, int);

//int main() {
//    Stack stack = Stack();
//    Stack *b = &stack;
//    stack.push('a');
//    stack.push('b');
//    stack.push('c');
//    reverseStack(b, 3, 'a');
//    cout << stack.pop() << " " << stack.pop() << " " << stack.pop() << " " << stack.pop() << " " << stack.pop() << endl;
//
//    return 0;
//}

bool reverseStack(Stack *stack, int stackSize, int element) {
    int elementIndex;
    bool isFound = false;
    char tempElement;

    if (stack->isEmpty() or stackSize <= 0) {
        return false;
    }

    char *temp = new char[stackSize];

    for (int i = 0; i < stackSize; i++) {
        tempElement = stack->pop();
        temp[i] = tempElement;
        if (tempElement == element) {
            isFound = true;
            elementIndex = i;
        }
    }

    assert(stack->isEmpty());
    for (int i = 0; i < stackSize; i++) {
        if (isFound and i == elementIndex) {
            stack->push('!');
            stack->push(temp[i]);
            stack->push('!');
        } else {
            stack->push(temp[i]);
        }
    }
    return true;
}