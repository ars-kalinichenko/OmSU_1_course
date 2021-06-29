#include "../include/queue.h"

Node *Queue::createNode(int data) {
    auto *queueNode = new Node();
    queueNode->data = data;
    queueNode->next = nullptr;
    return queueNode;
}

Queue::Queue() {
    tail = head = nullptr;
}

void Queue::push(int x) {
    auto *node = createNode(x);

    if (isEmpty()) {
        head = node;
    } else {
        tail->next = node;
    }
    tail = node;
}

bool Queue::isEmpty() const {
    return head == nullptr;
}

int Queue::pop() {
    if (isEmpty()) return -1;
    auto *temp = head;
    head = head->next;
    return temp->data;
}

int Queue::peek() const {
    if (isEmpty()) return -1;
    return head->data;
}

