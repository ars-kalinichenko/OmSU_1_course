#ifndef SEMINAR_CONSTANTS_H
#define SEMINAR_CONSTANTS_H

#include <string>
#include <map>
#include <vector>

std::map<int, std::string> errors{{0, "I'm fine!"},
                                  {1, "Stack Overflow"},
                                  {2, "Stack is empty!"},
                                  {3, "Stack is underflow!"}};
int STACK_OVERFLOW = 1;
int STACK_EMPTY = 2;
int STACK_UNDERFLOW = 3;



#endif //SEMINAR_CONSTANTS_H