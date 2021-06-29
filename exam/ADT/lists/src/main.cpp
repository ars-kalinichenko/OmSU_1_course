#include <include/stack.h>
#include <cassert>
#include <include/deque.h>


void testStack() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    assert(!stack.isEmpty());
    assert(20 == stack.peek());
    assert(20 == stack.pop());
    assert(10 == stack.pop());
    assert(stack.isEmpty());
}

void testDeque() {
    Deque deque = Deque();
    assert(deque.isEmpty());
    deque.insertFront(10);
    assert(deque.getFront() == 10);
    deque.insertFront(30);
    assert(deque.getFront() == 30);
    deque.deleteFront();
    assert(deque.getFront() == 10);
    deque.deleteFront();
    assert(deque.isEmpty());

    deque.insertFront(90);
    deque.insertRear(70);
    deque.insertFront(800);
    assert(deque.getFront() == 800);
    deque.deleteFront();
    assert(deque.getFront() == 90);
    deque.deleteFront();
    assert(deque.getFront() == 70);
    deque.deleteFront();
    assert(deque.isEmpty());
}

int main() {
    testStack();
    testDeque();
}