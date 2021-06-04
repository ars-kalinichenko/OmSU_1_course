#include "include/utils.h"
#include <iostream>
#include <fstream>

using namespace std;

int InputSizeMatrix(int &countRows, int &countCols) {
    do {
        cout << "Введите количество строк: ";
        cin >> countRows;
    } while (countRows <= 0);

    do {
        printf("Введите количество столбцов: ");
        cin >> countCols;
    } while (countCols <= 0);
    return 0;
}

Matrix *CreateZeroMatrix(int &rows, int &columns) {
    auto *matrix = new Matrix(rows, columns);
    for (int column = 0; column < columns; column++) {
        for (int row = 0; row < rows; row++) {
            matrix->changeElement(column, row, 0);
        }
    }
    return matrix;
}

Matrix *CreateRandomMatrix(int &rows, int &columns) {
    auto *matrix = new Matrix(rows, columns);
    matrix->randomFillMatrix();
    return matrix;
}

int SaveMatrixToFile(Matrix *matrix, ofstream &fileStream) {
    if (!fileStream.is_open()) {
        return -1;
    }
    fileStream << matrix->getColumnsCount();
    fileStream << " ";
    fileStream << matrix->getRowsCount();
    fileStream << " ";
    for (int col = 0; col < matrix->getColumnsCount(); col++) {  // stop loops if nothing to read
        for (int row = 0; row < matrix->getRowsCount(); row++) {
            fileStream << matrix->getElement(col, row);
            fileStream << " ";
        }
    }
    return 0;
}

Matrix *CreateMatrixFromFile(fstream &fin) {
    int rowsCount = 0;
    int colsCount = 0;

    int element;
    if (fin.is_open()) {
        fin >> colsCount;
        fin >> rowsCount;
        auto *matrix = new Matrix(rowsCount, colsCount);

        for (int col = 0; col < colsCount; col++) {  // stop loops if nothing to read
            for (int row = 0; row < rowsCount; row++) {
                fin >> element;
                matrix->changeElement(col, row, element);
            }
        }
        return matrix;
    }
    return nullptr;
}

Matrix *CreateMatrixFromKeyboard(int rows, int cols) {
    int element;

    auto *matrix = new Matrix(rows, cols);

    cout << "Введите элементы матрицы: ";
    for (int col = 0; col < cols; col++) {  // stop loops if nothing to read
        for (int row = 0; row < rows; row++) {
            cin >> element;
            matrix->changeElement(col, row, element);
        }
    }
    return matrix;
}