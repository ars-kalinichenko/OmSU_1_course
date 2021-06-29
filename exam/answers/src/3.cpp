#include <fstream>
#include <iostream>
#include "queue"
#include "deque"

void Inverse(std::queue<int> &first, std::queue<int> &second) {
    std::deque<int> tmp_deque;
    std::queue<int> tmp_q;

    int element;
    while (!first.empty()) {
        element = first.front();
        if (element < 0) tmp_deque.push_back(element);
        else tmp_q.push(element);
        first.pop();
    }
    first = tmp_q;
    while (!tmp_deque.empty()) {
        element = tmp_deque.back();
        second.push(element);
        tmp_deque.pop_back();
    }
}

int main() {
    std::ifstream in;
    in.open("input.txt");
    int n, elem;
    std::queue<int> que1, que2;
    in >> n;

    for (int i = 0; i < n; i++) {
        in >> elem;
        que1.push(elem);
    }

    Inverse(que1, que2);
    while (!que1.empty()) {
        std::cout << que1.front() << " ";
        que1.pop();
    }
    std::cout << std::endl;

    while (!que2.empty()) {
        std::cout << que2.front() << " ";
        que2.pop();
    }
    in.close();
}