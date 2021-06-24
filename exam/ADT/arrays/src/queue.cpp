#include <climits>
#include "include/queue.h"

Queue::Queue(int capacity) {
    this->capacity = capacity;
    front = 0;
    size = 0;
    rear = capacity - 1;
    array = new int[capacity];
}


Queue::~Queue() {
    delete[] array;
}

bool Queue::isFull() const {
    return size == capacity;
}

bool Queue::isEmpty() const {
    return size == 0;
}

bool Queue::enqueue(int item) {
    if (isFull()) return false;
    rear = (rear + 1) % (int) capacity;
    array[rear] = item;
    size++;
    return true;
}

int Queue::dequeue() {
    if (isEmpty()) return INT_MIN;
    int item = array[front];
    front = (front + 1) % (int) capacity;
    size--;
    return item;
}

int Queue::getFront() {
    if (isEmpty()) return INT_MIN;
    return array[front];
}

int Queue::getRear() {
    if (isEmpty()) return INT_MIN;
    return array[rear];
}


