#ifndef UNTITLED1_DEQUE_H
#define UNTITLED1_DEQUE_H

#include "errors.h"

class Deque {
    int *array;
    int front;
    int rear;
    int size;
    unsigned short code = 0;

public:
    Deque(int *, int);

    Deque(const Deque &);

    ~Deque();

    void clear();

    bool isEmpty() const;

    bool isFull() const;

    /*
     * Put element to front. Element will be the first in deque.
     * @params:
     *      int value - the value you want to put
     */
    void putFront(int);

    /*
     * Put element to rear. Element will be the last in deque.
     * @params:
     *      int value - the value you want to put
     */
    void putRear(int);

    /*
     * Take the first item from the deque. This will remove the element.
     */
    int takeFront();

    /*
     * Take the last item from the deque. This will remove the element.
     */
    int takeRear();

    /*
     * View the first item from the deque. In this case, the element will remain in place.
     */
    int getFront();

    /*
     * View the last item from the deque. In this case, the element will remain in place.
     */
    int getRear();

    /*
     * Delete first element from deque.
     */
    void deleteFront();

    /*
     * Delete last element from deque.
     */
    void deleteRear();

    void changeFront(int);

    void changeRear(int);

    unsigned short getCode() const;

};


#endif //UNTITLED1_DEQUE_H
