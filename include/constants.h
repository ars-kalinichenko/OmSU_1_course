#ifndef SEMINAR_CONSTANTS_H
#define SEMINAR_CONSTANTS_H

#include <string>
#include <map>

std::map<int, std::string> errors{{1, "Ошибка инициализации матрицы!"},
                                  {2, "Ошибка изменения элемента!"},
                                  {3, "Ошибка получения элемента!"}};
int INIT_ERROR = 1;
int CHANGE_ERROR = 2;
int GET_ERROR = 3;

#endif //SEMINAR_CONSTANTS_H
