#ifndef OMSU_2020_DEQUE_H
#define OMSU_2020_DEQUE_H

struct Node {
    int data;
    Node *prev, *next;
};

class Deque {
    Node *front;
    Node *rear;
    int Size;

public:
    Deque() {
        front = rear = nullptr;
        Size = 0;
    }

    // Operations on Deque
    void insertFront(int data);

    void insertRear(int data);

    void deleteFront();

    void deleteRear();

    int getFront();

    int getRear();

    int size() const;

    bool isEmpty();

    void erase();
};

#endif //OMSU_2020_DEQUE_H
