#include "matrix.h"
#include <iostream>
#include "constants.h"

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
        for (int row = 0; row < _rows; ++row) {
            for (int column = 0; column < _columns; ++column) {
                _matrix[row][column] = row + column;
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
