#include <cassert>
#include <include/deque.h>
#include <iostream>
#include "include/stack.h"
#include "include/queue.h"

using namespace std;

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

void testQueue() {
    Queue queue(10);
    queue.enqueue(1);
    queue.enqueue(2);
    assert(2 == queue.getRear());
    assert(1 == queue.dequeue());
    queue.dequeue();
    assert(queue.isEmpty());
}

void testDeque() {
    Deque deque = Deque(20);
    assert(deque.isEmpty());
    assert(!deque.isFull());
    deque.putFront(10);
    assert(deque.getFront() == 10);
    deque.putFront(30);
    assert(deque.getFront() == 30);
    deque.deleteFront();
    assert(deque.takeFront() == 10);
    assert(deque.isEmpty());

    deque.putRear(90);
    deque.putRear(70);
    deque.putFront(800);
    assert(deque.takeFront() == 800);
    assert(deque.takeFront() == 90);
    assert(deque.takeFront() == 70);
}

int main() {
    testStack();
    testQueue();
    testDeque();
}