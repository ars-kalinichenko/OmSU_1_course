#include "matrix.h"
#include <iostream>
#include "constants.h"
#include <algorithm>
#include <random>

using namespace std;

Matrix::Matrix(int rows, int columns) {
    if (rows > 0 and columns > 0) {
        _rows = rows;
        _columns = columns;
        _matrix = new int *[rows];
        for (int row = 0; row < columns; row++) {
            _matrix[row] = new int[columns];
        }
    } else {
        _processError(INIT_ERROR);
        _rows = 0;
        _columns = 0;
    }
}

Matrix::Matrix(const Matrix &matrix) {
    _matrix = matrix._matrix;
    _rows = matrix._rows;
    _columns = matrix._columns;
}

void Matrix::fillMatrix() {
    if (nullptr != _matrix) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(-10, 30);
        for (int row = 0; row < _rows; ++row) {
            for (int column = 0; column < _columns; ++column) {
                _matrix[row][column] = dist(gen);
            }
        }
    }
}

void Matrix::_processError(int numError) {
    std::string message = errors.at(numError);
    std::cout << message << std::endl;
}

void Matrix::changeElement(int row, int column, int element) {
    if (row >= 0 and column >= 0 and row < _rows and column < _columns) {
        _matrix[row][column] = element;
    } else {
        _processError(CHANGE_ERROR);
    }
}

int Matrix::getElement(int row, int column) {
    if (row >= 0 and column >= 0 and row < _rows and column < _columns) {
        return _matrix[row][column];
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

void Matrix::printMatrix() {
    if (nullptr != _matrix and _rows > 0) {
        for (int row = 0; row < _rows; ++row) {
            for (int column = 0; column < _columns; ++column) {
                std::cout << _matrix[row][column] << " ";
            }
            std::cout << std::endl;
        }
    }
}

void Matrix::_calculateKeys(int *keys) {
    if (_rows > 0 and _columns > 0 and keys != nullptr) {
        int maxLen;

        for (int row = 0; row < _rows; row++) {
            maxLen = 0;
            for (int element = 0; element < _columns; element++) {
                if (_matrix[row][element] > 0) {
                    maxLen++;
                } else if (maxLen > keys[row] and _matrix[row][element] != 0) {
                    keys[row] = maxLen;
                    maxLen = 0;
                }
            }
            if (maxLen > keys[row]) keys[row] = maxLen;
        }
    } else {
        _processError(ROW_KEY_ERROR);
    }
}

void Matrix::sortMatrix() {
    if (_rows > 0 and _columns > 0) {
        int *keys = new int[_rows];
        std::fill_n(keys, _rows, 0);
        _calculateKeys(keys);
        _printKeys(keys);
        int left = 0;
        int right = _rows - 1;
        int control = _rows;
        while (left < right) {
            for (int i = left; i < right; i++) {
                if (keys[i] < keys[i + 1]) {
                    _swapRows(i, i + 1);
                    _swapKeys(i, i + 1, keys);
                    control=i;
                }
            }
            right=control;

            for (int j = right; j > left; j--) {
                if (keys[j - 1] < keys[j]) {
                    _swapRows(j, j - 1);
                    _swapKeys(j, j - 1, keys);
                    control=j;
                }
            }
            left=control;
        }
        delete[] keys;
    } else _processError(SORT_ERROR);
}

void Matrix::_swapRows(int firstRowIndex, int secondRowIndex) {
    int *tempRow = _matrix[firstRowIndex];
    _matrix[firstRowIndex] = _matrix[secondRowIndex];
    _matrix[secondRowIndex] = tempRow;
}

void Matrix::_swapKeys(int firstIndex, int secondIndex, int *keys) {
    int tempKey = keys[firstIndex];
    keys[firstIndex] = keys[secondIndex];
    keys[secondIndex] = tempKey;
}

void Matrix::_printKeys(int *keys) const {
    for (int i = 0; i < _rows; i++) {
        std::cout << keys[i] << " ";
    }
    std::cout << std::endl;
}

