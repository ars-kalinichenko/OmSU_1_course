#include <cassert>
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

int main() {
    testStack();
    testQueue();
}