#ifndef OMSU_2020_DEQUE_H
#define OMSU_2020_DEQUE_H

class Deque {
    int *array;
    int front;
    int rear;
    int size;

public:
    Deque(int);

    Deque(const Deque &);

    ~Deque();

    void clear();

    bool isEmpty() const;

    bool isFull() const;

    void putFront(int);

    void putRear(int);

    int takeFront();

    int takeRear();

    int getFront();

    int getRear();

    void deleteFront();

    void deleteRear();
};

#endif //OMSU_2020_DEQUE_H
