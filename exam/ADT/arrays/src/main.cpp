#include "include/stack.h"
#include "iostream"

using namespace std;

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    cout << "Is empty? " << stack.isEmpty() << endl;
    cout << "Last element: " << stack.peek() << endl;
    cout << stack.pop() << " " << stack.pop() << endl;
    cout << "Is not empty? " << stack.isEmpty() << endl;
}