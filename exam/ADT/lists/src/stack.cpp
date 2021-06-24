#include "include/stack.h"

void Stack::push(int x) {
    auto *stackNode = createNode(x);
    stackNode->next = root;
    stackNode->data = x;
    root = stackNode;
}

StackNode *Stack::createNode(int data) {
    auto *stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = nullptr;
    return stackNode;
}

int Stack::pop() {
    if (isEmpty()) return -1;
    StackNode *temp = root;
    root = root->next;
    int data = temp->data;
    delete temp;
    return data;
}

int Stack::peek() const {
    if (isEmpty()) return -1;
    return root->data;
}

bool Stack::isEmpty() const {
    return root == nullptr;
}

Stack::Stack() {
    root = nullptr;
}
