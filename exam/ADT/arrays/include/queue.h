#ifndef OMSU_2020_QUEUE_H
#define OMSU_2020_QUEUE_H

class Queue {
private:
    int front, rear, size;
    unsigned capacity;
    int *array;

public:

    Queue(int);

    bool isFull() const;

    bool isEmpty() const;

    bool enqueue(int); // add to queue

    int dequeue(); // take from queue

    int getFront();

    int getRear();

    ~Queue();
};

#endif //OMSU_2020_QUEUE_H
