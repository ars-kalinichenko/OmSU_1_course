#include <iostream>
#include <vector>

using namespace std;

// 1 2 5 -3 7 4 8 -4 -2
// 1 -3 8 2 7 -4 5 4 -2

int getSortedCount(double *table, int rows, int columns) {
    /*
     * Подпрограмма вычисляет количество упорядоченных по неубыванию строк
       в таблице вещественных чисел, заданной 1-мерным динамическим массивом
       (упакованным по строкам).
     * @param:  table - это указатель на массив.
                rows, columns - строки, столбцы.
     * @функция возвращает: число упор.строк или:
                              -1 -- память не выделялась
                              -2 -- rows/columns не корректны
     */

    int result = 0;
    int sorted = 0;

    if (table == nullptr) {
        result = -1;
    } else if (rows < 0 or columns < 0) {
        result = -2;
    } else {
        bool isSorted;
        int j, k;
        for (int i = 0; i < rows; i++) {
            isSorted = true;
            j = 0;
            while (j < (columns - 1) && isSorted) {
                k = i * columns + j;
                isSorted = table[k + 1] > table[k];
                j++;
            }
            if (isSorted) {
                sorted++;
            }
        }
        result = sorted;
    }

    return result;
}

int main() {
    int rows, columns;
    cout << "Введите количество строк, столбцов через пробел: ";
    cin >> rows >> columns;
    double *tableArray = new double[rows * columns];

    // заполнение массив
    double input;
    cout << "Введите элементы массива через пробел: ";
    for (int i = 0; i < rows * columns; i++) {
        cin >> input;
        tableArray[i] = input;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << tableArray[i * columns + j] << " ";
        }
        cout << endl;
    }

    int sorted = getSortedCount(tableArray, rows, columns);

    if (sorted == -1)
        cout << "Память не выделена" << endl;
    if (sorted == -2)
        cout << "Проверьте количество строк или столбцов" << endl;
    if (sorted >= 0)
        cout << "Количество отсортированных строк: " << sorted << endl;

    delete[] tableArray;
}

