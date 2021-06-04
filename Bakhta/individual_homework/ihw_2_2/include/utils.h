#ifndef OMSU_2020_UTILS_H
#define OMSU_2020_UTILS_H

#include "matrix.h"

/*
 * Функция запрашивает у пользователя кол-во строк, столбцов.
 * Больше 0, но меньше максимальных.
 * @output by reference:
 *      countRows - кол-во строк
 *      countCols - кол-во столбцов
 */
int InputSizeMatrix(int &, int &);

/*
 * Создает матрицу указанных размеров и заполняет ее нулями
 * @params:
 *      Количество строк
 *      Количество столбцов
 * @returns:
 *      Указатель на созданную матрицу
 */
Matrix *CreateZeroMatrix(int &, int &);


/*
 * Создает матрицу указанных размеров и заполняет ее случайными числами
 * @params:
 *      Количество строк
 *      Количество столбцов
 * @returns:
 *      Указатель на созданную матрицу
 */
Matrix *CreateRandomMatrix(int &, int &);

/*
 * Создает матрицу указанных размеров и заполняет ее из файла
 * @params:
 *      Количество строк
 *      Количество столбцов
 *      Название файла
 * @returns:
 *      Указатель на созданную матрицу
 */
Matrix *CreateMatrixFromFile(std::fstream &);

Matrix *CreateMatrixFromKeyboard(int, int);


int SaveMatrixToFile(Matrix *, std::ofstream &);

#endif //OMSU_2020_UTILS_H
