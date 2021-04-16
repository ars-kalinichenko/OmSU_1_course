#ifndef UNTITLED1_QUEUE_H
#define UNTITLED1_QUEUE_H

#include "errors.h"

class Queue {
    int *array;
    int front;
    int rear;
    int size;
    unsigned short code = 0;

public:
    Queue(int);

    Queue(const Queue &);

    ~Queue();

    void clear();

    bool isEmpty() const;

    bool isFull() const;

    /*
     * Put element to rear
     * @params:
     *      int value - the value you want to put
     */
    void put(int);

    /*
     * Take the first item from the queue. This will remove the element.
     */
    int takeFirst();

    /*
     * View the first item from the queue. In this case, the element will remain in place.
     */
    int getFirst();

    /*
     * Delete first element from queue.
     */
    void removeFirst();


    void changeFront(int);

    unsigned short getCode() const;

    int getSize() const;
};

#endif //UNTITLED1_QUEUE_H
