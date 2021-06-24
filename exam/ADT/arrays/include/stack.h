#ifndef OMSU_2020_STACK_H
#define OMSU_2020_STACK_H

#define MAX 500

class Stack {
    int top;

public:
    int arr[MAX]{}; // Maximum size of Stack

    Stack() { top = -1; }

    bool push(int x);

    int pop();

    int peek();

    bool isEmpty() const;

    bool isFull() const;
};

#endif //OMSU_2020_STACK_H
