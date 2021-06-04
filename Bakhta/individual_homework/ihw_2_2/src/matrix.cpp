#include "../include/matrix.h"
#include <iostream>
#include "../include/constants.h"
#include <algorithm>
#include <random>

using namespace std;
void swapCols(const int *swaps, int **matrix, int columnCount, int rowCount) {
    int tempIndex;
    int **tempMatrix = new int *[columnCount];
    for (int i = 0; i < columnCount; i++) {
        tempMatrix[i] = matrix[i];
    }
    for (int col = 0; col < columnCount; col++) {
        tempIndex = swaps[col];
        matrix[col] = tempMatrix[tempIndex];
    }
    delete[] tempMatrix;
}

Matrix::Matrix(int rows, int columns) {
    if (rows > 0 and columns > 0) {
        _rows = rows;
        _columns = columns;
        _matrix = new int *[columns];
        for (int column = 0; column < columns; column++) {
            _matrix[column] = new int[rows];
        }
    } else {
        _processError(INIT_ERROR);
        _rows = 0;
        _columns = 0;
    }
}

Matrix::Matrix(const Matrix &matrix) {
    _rows = matrix._rows;
    _columns = matrix._columns;
    _matrix = new int *[_columns];
    for (int i = 0; i < _columns; i++) {
        for (int j = 0; j < _rows; j++) {
            _matrix[i][j] = matrix._matrix[i][j];
        }
    }
}

void Matrix::randomFillMatrix() {
    if (nullptr != _matrix) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(-10, 30);
        for (int col = 0; col < _columns; col++) {
            for (int row = 0; row < _rows; row++) {
                changeElement(col, row, dist(gen));
            }
        }
    }
}

void Matrix::_processError(int numError) {
    std::string message = errors.at(numError);
    std::cout << message << std::endl;
}

void Matrix::changeElement(int column, int row, int element) {
    if (row >= 0 and column >= 0 and row < _rows and column < _columns) {
        _matrix[column][row] = element;
    } else {
        _processError(CHANGE_ERROR);
    }
}

int Matrix::getElement(int column, int row) {
    if (column >= 0 and row >= 0 and row < _rows and column < _columns) {
        return _matrix[column][row];
    } else {
        _processError(GET_ERROR);
        return -1;
    }
}

int Matrix::getRowsCount() const {
    return _rows;
}

int Matrix::getColumnsCount() const {
    return _columns;
}

Matrix::~Matrix() {
    if (nullptr != _matrix) {
        for (int row = 0; row < _rows; row++) {
            delete[] _matrix[row];
        }
        delete[] _matrix;
        _rows = 0;
        _columns = 0;
    }
}

void Matrix::_calculateKeys(int *keys) {
    if (_rows > 0 and _columns > 0) {
        int count;
        for (int column = 0; column < _columns; column++) {
            count = 0;
            for (int element = 0; element < _rows; element++) {
                if (_matrix[column][element] < 0) {
                    count++;
                }
            }
            keys[column] = count;
        }
    } else {
        _processError(ROW_KEY_ERROR);
    }
}


void Matrix::sortMatrix() {
    if (_rows > 0 and _columns > 0) {
        int *keys = new int[_columns];
        int *swaps = new int[_columns];
        for (int col = 0; col < _columns; col++) {
            swaps[col] = col;
        }

        _calculateKeys(keys);
        _printKeys(keys);
        mergeSort(keys, 0, _columns - 1, swaps);
        swapCols(swaps, _matrix, _columns, _rows);
        for (int i = 0; i < _columns; i++) {
            cout << i << " -> " << swaps[i] << endl;
        }
        _printKeys(keys);
        delete[] keys;
    } else _processError(SORT_ERROR);
}

void Matrix::_printKeys(int *keys) const {
    std::cout << endl << "Ключи: ";
    for (int i = 0; i < _columns; i++) {
        std::cout << keys[i] << " ";
    }
    std::cout << std::endl;
}

void Matrix::merge(int *keys, int *colsSwap, int low, int high, int mid) const {
    int i, j, k;
    int *temp = new int[_columns];

    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (keys[i] < keys[j]) {
            temp[k] = keys[i];
            colsSwap[k] = i;
            i++;
        } else {
            temp[k] = keys[j];
            colsSwap[k] = j;
            j++;
        }
        k++;
    }
    while (i <= mid) {
        temp[k] = keys[i];
        colsSwap[k] = i;
        k++;
        i++;
    }
    while (j <= high) {
        temp[k] = keys[j];
        colsSwap[k] = j;
        k++;
        j++;
    }

    for (i = low; i < k; i++) {
        keys[i] = temp[i];
    }


    delete[] temp;
}


void Matrix::mergeSort(int *keys, int low, int high, int *swaps) {
    int mid;

    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(keys, low, mid, swaps);
        mergeSort(keys, mid + 1, high, swaps);
        merge(keys, swaps, low, high, mid);
    }
}