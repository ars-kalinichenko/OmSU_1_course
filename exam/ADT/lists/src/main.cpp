#include <cassert>
#include <include/stack.h>

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

int main() {
    testStack();
}