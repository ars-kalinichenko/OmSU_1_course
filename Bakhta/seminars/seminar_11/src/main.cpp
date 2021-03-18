#include <iostream>
#include <include/deque.h>
#include <include/queue.h>

using namespace std;

void testDeque();

void testQueue();

int main() {
//    testDeque();
    testQueue();
    return 0;
}

void testDeque() {
    int *arr = new int[20];
    Deque deque = Deque(arr, 20);
    cout << deque.isEmpty() << endl;
    cout << deque.isFull() << endl;
    deque.putFront(10);
    cout << deque.getFront() << endl;
    deque.putFront(30);
    cout << deque.getFront() << endl;
    deque.deleteFront();
    cout << deque.takeFront() << endl;
    cout << deque.isEmpty() << endl;

    cout << endl;

    deque.putRear(90);
    deque.putRear(70);
    deque.putFront(800);
    cout << deque.takeFront() << " " << deque.takeFront() << " " << deque.takeFront() << endl;
    cout << deque.takeFront() << " Code: " << deque.getCode() << endl;
}

void testQueue() {
    int *arr = new int[20];
    Queue queue = Queue(arr, 20);
    cout << queue.isEmpty() << endl;
    cout << queue.isFull() << endl;

    queue.put(10);
    queue.put(50);
    cout << queue.getFirst() << endl;
    queue.changeFront(22222);
    cout << queue.getFirst() << endl;
    cout << queue.takeFirst() << endl;
    cout << queue.takeFirst() << endl;
    cout << queue.isEmpty() << endl;
}