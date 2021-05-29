#ifndef SEMINAR_CONSTANTS_H
#define SEMINAR_CONSTANTS_H

#include <string>
#include <map>

std::map<int, std::string> errors{{1, "Ошибка инициализации матрицы!"},
                                  {2, "Ошибка изменения элемента!"},
                                  {3, "Ошибка получения элемента!"},
                                  {4, "Ошибка получения ключа для строки"},
                                  {5, "Ошибка сортировки"}};
int INIT_ERROR = 1;
int CHANGE_ERROR = 2;
int GET_ERROR = 3;
int ROW_KEY_ERROR = 4;
int SORT_ERROR = 5;

#endif //SEMINAR_CONSTANTS_H