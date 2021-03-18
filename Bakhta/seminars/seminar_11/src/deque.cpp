
#include <include/deque.h>

Deque::Deque(int *dynamicArray, int arraySize) {
    array = dynamicArray;
    size = arraySize;
    front = -1;
    rear = 0;
}

Deque::Deque(const Deque &deque) {
    array = deque.array;
    size = deque.size;
    front = deque.front;
    rear = deque.rear;
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

unsigned short Deque::getCode() const {
    return code;
}

void Deque::clear() {
    front = -1;
    rear = 0;
}

void Deque::putFront(int value) {
    if (isFull()) {
        code = STRUCT_FULL;
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
        code = STRUCT_FULL;
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
    if (isEmpty()) {
        code = STRUCT_EMPTY;
        return 0;
    }

    int value = array[front];
    deleteFront();
    return value;
}

int Deque::takeRear() {
    if (isEmpty()) {
        code = STRUCT_EMPTY;
        return 0;
    }

    int value = array[rear];
    deleteRear();
    return value;
}

void Deque::deleteFront() {
    if (isEmpty()) {
        code = STRUCT_EMPTY;
        return;
    }
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
    if (isEmpty()) {
        code = STRUCT_EMPTY;
        return;
    }
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
        code = STRUCT_EMPTY;
        return 0;
    }
    return array[front];
}

int Deque::getRear() {
    if (isEmpty()) {
        code = STRUCT_EMPTY;
        return 0;
    }
    return array[rear];
}

void Deque::changeFront(int value) {
    if (isEmpty()) {
        code = STRUCT_EMPTY;
        return;
    }
    array[front] = value;
}

void Deque::changeRear(int value) {
    if (isEmpty()) {
        code = STRUCT_EMPTY;
        return;
    }
    array[rear] = value;
}