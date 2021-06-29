#include <new>
#include "include/l1_list.h"
#include "iostream"

using namespace std;

int L1_list::getError() const {
    return error;
}

double L1_list::seeItem() {
    if (curr->next != buf) {
        return curr->next->data;
    } else {
        node *tmp = curr->next;
        tmp = tmp->next;
        return tmp->data;
    }
}

L1_list::L1_list() {
    buf = nullptr;
    buf = new(std::nothrow) node;
    if (buf == nullptr) {
        error = 1;
        return;
    }

    buf->next = buf;
    curr = buf;
    error = 0;
}

void L1_list::changeItem(double data) {
    if (isEmpty()) {
        error = 2;
        return;
    }
    curr->next->data = data;
}

void L1_list::toStart() {
    curr = buf;
}

void L1_list::toNext() {
    curr = curr->next;
}

bool L1_list::isEmpty() {
    return buf->next == buf;
}

bool L1_list::isEnd() {
    return curr->next == buf;
}

void L1_list::makeEmpty() {
    node *tmp = buf->next;
    while (!isEmpty()) {
        buf->next = tmp->next;
        delete tmp;
        tmp = buf->next;
    }
    curr = buf;
    error = 0;
}

L1_list::~L1_list() {
    makeEmpty();
    delete buf;
    buf = curr = nullptr;
}

void L1_list::addItem(double d) {
    node *tmp = nullptr;
    tmp = new(std::nothrow) node;
    if (tmp == nullptr) {
        error = 1;
        return;
    }
    tmp->next = curr->next;
    curr->next = tmp;
    tmp->data = d;
    error = 0;
    delete tmp;
}

void L1_list::removeItem() {
    if (isEmpty()) {
        error = 2;
        return;
    }
    error = 0;
    node *tmp = curr->next;
    curr->next = tmp->next;
    delete tmp;
}

double L1_list::takeItem() {
    if (isEmpty()) {
        error = 2;
        return 0;
    }
    double d = curr->next->data;
    removeItem();
    return d;
}

void L1_list::print() {
    if (isEmpty()) {
        error = 2;
        return;
    }
    node *tmp = new node;
    tmp = buf;
    tmp = tmp->next;
    while (tmp->next != buf) {
        cout << tmp->data << ' ';
        tmp = tmp->next;
    }
    cout << tmp->data << endl;

}