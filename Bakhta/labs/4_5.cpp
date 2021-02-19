#include <iostream>
#include <string>

using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLUMNS = 10;

int InitMatrix(int arr[][MAX_ROWS], int rows, int columns)
/*
 * Функция заполняет массив элементами i+j,
 *   где i - номер строки, j - номер столбца.
 * Args:
 *      string &msg - Ссылка на сообщение, которое нужно вывести перед вводом
 *      limit - ограничение ввода сверху
 * Returns:
 *      0 - удачное выполнение
 *      -1 - размеры массива отрицательные или больше констант
 */
{
    int result = 0;
    if (rows <= 0 || columns <= 0 || rows > MAX_ROWS || columns > MAX_COLUMNS) result = -1;
    else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                arr[i][j] = i + j;
            }
        }
    }
    return result;
}

void PrintMatrix(int arr[][MAX_ROWS], int rows, int columns)
/*
 * Функция печатает полученный массив.
 */
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int InputLength(const string &msg, int limit)
/*
 * Функция вводит значение длины.
 * Если длина не принадлежит [0; limit], то предлагается повторный ввод.
 * Args:
 *      string &msg - Ссылка на сообщение, которое нужно вывести перед вводом
 *      limit - ограничение ввода сверху
 * Returns:
 *       size - введеный размер в [0; limit]
 */
{
    bool isCorrect = false;
    int size;
    while (!isCorrect) {
        cout << msg << ": ";
        cin >> size;
        if (size <= limit && size > 0) {
            isCorrect = true;
        }
    }
    return size;
}

int main() {
    int arr[MAX_ROWS][MAX_COLUMNS];
    int res;
    int rows = InputLength("Введите количество строк", MAX_ROWS);
    int columns = InputLength("Введите количество столбцов", MAX_COLUMNS);
    res = InitMatrix(arr, rows, columns);
    if (res == 0)
        PrintMatrix(arr, rows, columns);
}