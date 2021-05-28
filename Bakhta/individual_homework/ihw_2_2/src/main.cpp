#include <iostream>
#include<string>
#include <include/matrix.h>
#include <include/cli.h>

using namespace std;


int main() {
    int num;
    bool isCreated = false;
    int rows, columns;
    Matrix *matrix;

    do {
        cout << "1. Создать таблицу с клавиатуры" << endl;
        cout << "2. Заполнить таблицу случайным образом" << endl;
        cout << "3. Заполнить таблицу из файла (input.txt)" << endl;
        cout << "4. Показать матрицу" << endl;
        cout << "5. Выполнить сортировку" << endl;
        cout << "6. Завершить работу" << endl;
        do {
            cout << "Введите номер команды: ";
            cin >> num;
        } while (num < 1 || num > 6);
        if (num == 1) {
            InputSizeMatrix(rows, columns);
            matrix = CreateZeroMatrix(rows, columns);
            isCreated = true;
        } else if (num == 2) {
            InputSizeMatrix(rows, columns);
            matrix = CreateRandomMatrix(rows, columns);
            isCreated = true;
        } else if (num == 3) {
            InputSizeMatrix(rows, columns);
            matrix = CreateMatrixFromFile(rows, columns);
            isCreated = true;
        } else if (num == 4) {
            if (isCreated) {
                MatrixEditor(matrix);
            } else cout << "Матрица не задана!" << endl;
        } else if (num == 5) {
            if (isCreated) {
                matrix->sortMatrix();
            } else cout << "Матрица не задана!" << endl;
        } else if (num == 6) {
            exit(0);
        }
    } while (num != 6);
}

