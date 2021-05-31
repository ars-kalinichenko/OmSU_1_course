#include <iostream>
#include<string>
#include <include/matrix.h>
#include <include/cli.h>
#include <fstream>
#include <include/utils.h>

using namespace std;


int main() {
    int num;
    bool isCreated = false;
    int rows, columns;
    Matrix *matrix;

    do {
        clearScreen();
        cout << "1. Создать таблицу с клавиатуры" << endl;
        cout << "2. Заполнить таблицу случайным образом" << endl;
        cout << "3. Заполнить таблицу из файла (input.txt)" << endl;
        cout << "4. Показать матрицу" << endl;
        cout << "5. Сохранить матрицу в файл (output.txt)" << endl;
        cout << "6. Выполнить сортировку" << endl;
        cout << "7. Завершить работу" << endl;
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
            fstream fin;
            string path;
            cout << "Введите полный путь до файла: ";
            cin >> path;
            fin.open(path);
            matrix = CreateMatrixFromFile(9, 9, fin);
            if (matrix)
                isCreated = true;
            fin.close();
        } else if (num == 4) {
            if (isCreated) {
                MatrixEditor(matrix);
            } else cout << "Матрица не задана!" << endl;
        } else if (num == 5) {
            ofstream myFile;
            string path;
            cout << "Введите полный путь до файла: ";
            cin >> path;
            myFile.open(path);
            SaveMatrixToFile(matrix, myFile);
            myFile.close();
        } else if (num == 6) {
            if (isCreated) {
                int *keys = new int[matrix->getColumnsCount()];
                matrix->sortMatrix();
                delete[] keys;
            } else cout << "Матрица не задана!" << endl;

        } else if (num == 7) {
            exit(0);
        }
    } while (num != 6);
}