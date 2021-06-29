#ifndef OMSU_2020_L1_LIST_H
#define OMSU_2020_L1_LIST_H
// Thx Arkady

struct node {
    double data;
    node *next;
};

class L1_list {
private:
    node *buf;
    node *curr;
    int error; //1 - not enough memory, 2 - remove from empty,

public:
    L1_list();

    ~L1_list();

    void makeEmpty();

    bool isEmpty();

    bool isEnd();

    void addItem(double);

    double seeItem();

    void changeItem(double);

    double takeItem();

    void removeItem();

    void toStart();

    void toNext();

    int getError() const;

    void print();
};

#endif //OMSU_2020_L1_LIST_H
