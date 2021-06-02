#include "include/test.h"

#include <string>
#include <fstream>
#include <iostream>
#include <include/stack.h>
#include <cassert>


std::vector<std::vector<std::string>> testFiles = {
        {"/home/arseny/projects/OmSU_1_course/Bakhta/individual_homework/ihw_2_3/test/1.txt",
                "/home/arseny/projects/OmSU_1_course/Bakhta/individual_homework/ihw_2_3/test/1_char.txt",
                "/home/arseny/projects/OmSU_1_course/Bakhta/individual_homework/ihw_2_3/test/1_answer.txt"},

        {"/home/arseny/projects/OmSU_1_course/Bakhta/individual_homework/ihw_2_3/test/2.txt",
                "/home/arseny/projects/OmSU_1_course/Bakhta/individual_homework/ihw_2_3/test/2_c.txt",
                "/home/arseny/projects/OmSU_1_course/Bakhta/individual_homework/ihw_2_3/test/2_a.txt"},

        {"/home/arseny/projects/OmSU_1_course/Bakhta/individual_homework/ihw_2_3/test/3.txt",
                "/home/arseny/projects/OmSU_1_course/Bakhta/individual_homework/ihw_2_3/test/3_c.txt",
                "/home/arseny/projects/OmSU_1_course/Bakhta/individual_homework/ihw_2_3/test/3_a.txt"}};

bool reverseStack(Stack *, int, char);

int fillStackFromFile(Stack *, ifstream &);

char getSepElement(const string &);

bool checkAnswer(Stack *, const string &);

int testProgram() {
    int stackSize;
    char element;
    bool isRight;
    for (int i = 0; i < testFiles.size(); i++) {
        auto *stack = new Stack;
        element = getSepElement(testFiles[i][1]);

        ifstream fin;
        fin.open(testFiles[i][0]);
        fin >> stackSize;
        fillStackFromFile(stack, fin);
        reverseStack(stack, stackSize, element);
        isRight = checkAnswer(stack, testFiles[i][2]);
        if (!isRight) {
            cout << "Ошибка в " << i + 1 << " тесте" << endl;
        }
        fin.close();
    }
    return 0;
}

char getSepElement(const string &path) {
    char x;
    ifstream fin;
    fin.open(path);
    fin >> x;
    fin.close();
    return x;
}

bool checkAnswer(Stack *stack, const string &path) {
    char s, f;
    int ansSize;
    ifstream fin;
    fin.open(path);
    if (!fin.is_open()) return false;
    fin >> ansSize;
    for (int i = 0; i < ansSize; i++) {
        s = stack->pop();
        fin >> f;
        if (f != s) {
            fin.close();
            return false;
        }
    }
    fin.close();
    return true;
}

bool reverseStack(Stack *stack, int stackSize, char element) {
    int elementIndex;
    bool isFound = false;
    char tempElement;

    if (stack->isEmpty() or stackSize <= 0) {
        return false;
    }

    char *temp = new char[stackSize];

    for (int i = 0; i < stackSize; i++) {
        tempElement = stack->pop();
        temp[i] = tempElement;
        if (tempElement == element) {
            isFound = true;
            elementIndex = i;
        }
    }

    assert(stack->isEmpty());
    for (int i = 0; i < stackSize; i++) {
        if (isFound and i == elementIndex) {
            stack->push('!');
            stack->push(temp[i]);
            stack->push('!');
        } else {
            stack->push(temp[i]);
        }
    }
    return true;
}

int fillStackFromFile(Stack *stack, ifstream &file) {
    char element;
    if (!file.is_open()) {
        return 1;
    }
    while (file >> element) {
        stack->push(element);
    }

    file.close();

    if (!file.eof()) {
        return 3;
    }
    return 0;
}