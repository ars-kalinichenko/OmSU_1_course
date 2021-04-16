#include <include/queue.h>

Queue::Queue(int arraySize) {
    array = new int[arraySize];
    size = arraySize;
    front = -1;
    rear = -1;
}

Queue::Queue(const Queue &queue) {
    size = queue.size;
    front = queue.front;
    rear = queue.rear;
    array = new int[queue.size];
    for (int i = 0; i < queue.size; i++) {
        array[i] = queue.array[i];
    }
}

Queue::~Queue() {
    clear();
    delete[] array;
}

bool Queue::isEmpty() const {
    return front == -1 and rear == -1;
}

void Queue::put(int value) {
    if (isFull()) {
        code = STRUCT_FULL;
        return;
    } else if (front == -1)
        front = 0;
    rear++;
    array[rear] = value;
}

bool Queue::isFull() const {
    return rear == size - 1;
}

void Queue::clear() {
    front = -1;
    rear = -1;
}

int Queue::getSize() const {
    return rear + 1;
}

int Queue::takeFirst() {
    if (isEmpty()) {
        code = STRUCT_EMPTY;
        return 0;
    }
    int value = array[front];
    removeFirst();
    return value;
}

void Queue::removeFirst() {
    if (isEmpty()) {
        code = STRUCT_EMPTY;
    } else if (rear == front)
        clear();
    else
        front++;
}

int Queue::getFirst() {
    if (isEmpty()) {
        code = STRUCT_EMPTY;
        return 0;
    }
    return array[front];
}

void Queue::changeFront(int value) {
    if (isEmpty()) {
        code = STRUCT_EMPTY;
    }
    array[front] = value;
}

unsigned short Queue::getCode() const {
    return code;
}
