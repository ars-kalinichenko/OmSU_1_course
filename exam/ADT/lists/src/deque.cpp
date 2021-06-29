#include <iostream>
#include "../include/deque.h"


using namespace std;

static Node *getnode(int data) {
    auto *newNode = new Node();
    newNode->data = data;
    newNode->prev = newNode->next = nullptr;
    return newNode;
}

bool Deque::isEmpty() {
    return (front == nullptr);
}

int Deque::size() const {
    return Size;
}

void Deque::insertFront(int data) {
    Node *newNode = getnode(data);
    if (front == nullptr)
        rear = front = newNode;

    else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    Size++;
}

void Deque::insertRear(int data) {
    Node *newNode = getnode(data);
    if (rear == nullptr)
        front = rear = newNode;
    else {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
    Size++;

}

void Deque::deleteFront() {
    if (isEmpty())
        cout << "UnderFlow\n";

    else {
        Node *temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;
        else
            front->prev = nullptr;
        delete temp;
        Size--;
    }
}

void Deque::deleteRear() {
    if (isEmpty())
        cout << "UnderFlow\n";
    else {
        Node *temp = rear;
        rear = rear->prev;

        if (rear == nullptr)
            front = nullptr;
        else
            rear->next = nullptr;
        delete temp;

        Size--;
    }
}


int Deque::getFront() {
    if (isEmpty())
        return -1;
    return front->data;
}

int Deque::getRear() {
    if (isEmpty())
        return -1;
    return rear->data;
}

void Deque::erase() {
    rear = nullptr;
    while (front != nullptr) {
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    Size = 0;
}

