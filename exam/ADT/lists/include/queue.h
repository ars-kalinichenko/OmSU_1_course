#ifndef OMSU_2020_QUEUE_H
#define OMSU_2020_QUEUE_H

struct Node {
    int data;
    Node *next;
};

class Queue {
private:
    Node *head;
    Node *tail;

    static Node *createNode(int);

public:
    Queue();

    void push(int x);

    int pop();

    int peek() const;

    bool isEmpty() const;
};


#endif //OMSU_2020_QUEUE_H
