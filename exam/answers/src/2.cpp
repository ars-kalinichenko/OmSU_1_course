
#include <fstream>
#include <iostream>


struct node {
    int data;
    node *next;
};

class stackList {
private:
    node *Top;
public:
    stackList();

    ~stackList();

    void push(int);

    void pop();

    int top();

    bool empty();
};

stackList::stackList() {
    Top = nullptr;
}

void stackList::push(int x) {
    auto *stackNode = new node();
    stackNode->next = Top;
    stackNode->data = x;
    Top = stackNode;
}

stackList::~stackList() {
    Top = nullptr;
}

void stackList::pop() {
    if (empty()) {
        std::cout << "empty" << std::endl;
        exit(0);
    }
    Top = Top->next;
}

bool stackList::empty() {
    return Top == nullptr;
}

int stackList::top() {
    if (empty()) {
        std::cout << "empty" << std::endl;
        exit(0);
    }
    return Top->data;
}


int main() {
    std::ifstream in;
    in.open("input.txt");
    int n, elem;
    stackList st;
    in >> n;

    for (int i = 0; i < n; i++) {
        in >> elem;
        st.push(elem);
        std::cout << st.top() << " ";
    }
    std::cout << std::endl;


    for (int i = 0; i < n; i++) {
        std::cout << st.top() << " ";
        st.pop();
    }
    std::cout << std::endl;

    in >> n;
    for (int i = 0; i < n; i++) {
        in >> elem;
        st.push(elem);
    }

    std::cout << std::endl;
    while (!st.empty()) {
        std::cout << st.top() << " ";
        st.pop();
    }
    in.close();
}