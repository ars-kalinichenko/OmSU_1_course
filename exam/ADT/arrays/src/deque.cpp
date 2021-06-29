#include <include/deque.h>

Deque::Deque(int arraySize) {
    array = new int[arraySize];
    size = arraySize;
    front = -1;
    rear = -1;
}

Deque::Deque(const Deque &deque) {
    size = deque.size;
    front = deque.front;
    rear = deque.rear;
    array = new int[deque.size];
    for (int i = 0; i < deque.size; i++) {
        array[i] = deque.array[i];
    }
}

Deque::~Deque() {
    clear();
    delete[] array;
}

bool Deque::isEmpty() const {
    return front == -1;
}

bool Deque::isFull() const {
    return ((front == 0 and rear == size - 1) or front == rear + 1);
}

void Deque::clear() {
    front = -1;
    rear = 0;
}

void Deque::putFront(int value) {
    if (isFull()) {
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = size - 1;
    } else {
        front--;
    }
    array[front] = value;
}

void Deque::putRear(int value) {
    if (isFull()) {
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == size - 1) {
        rear = 0;
    } else
        rear++;
    array[rear] = value;
}


int Deque::takeFront() {
    if (isEmpty()) return 0;


    int value = array[front];
    deleteFront();
    return value;
}

int Deque::takeRear() {
    if (isEmpty()) return 0;

    int value = array[rear];
    deleteRear();
    return value;
}

void Deque::deleteFront() {
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == size - 1) {
        front = 0;
    } else {
        front++;
    }

}

void Deque::deleteRear() {
    if (rear == front) {
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = size - 1;
    } else {
        rear--;
    }
}

int Deque::getFront() {
    if (isEmpty()) {
        return 0;
    }
    return array[front];
}

int Deque::getRear() {
    if (isEmpty()) {
        return 0;
    }
    return array[rear];
}
