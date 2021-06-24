#ifndef OMSU_2020_STACK_H
#define OMSU_2020_STACK_H

class StackNode {
public:
    int data;
    StackNode *next;
};

class Stack {
private:
    StackNode* root;

    static StackNode *createNode(int);

public:
    Stack();

    void push(int x);

    int pop();

    int peek() const;

    bool isEmpty() const;

};

#endif //OMSU_2020_STACK_H
