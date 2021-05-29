#ifndef OMSU_2020_STACK_H
#define OMSU_2020_STACK_H

#define MAX 50


using namespace std;


class Stack {
    int top;
    int code = 0;

public:
    int getCode() const;

    char a[MAX]{}; // Maximum size of Stack

    Stack() { top = -1; }

    bool push(char x);

    char pop();

    char peek();

    bool isEmpty() const;
};


#endif //OMSU_2020_STACK_H
