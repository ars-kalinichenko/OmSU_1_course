#ifndef SEMINAR_MATRIX_H
#define SEMINAR_MATRIX_H

#include <string>
#include <map>

class Matrix {
private:
    int **_matrix;
    int _rows;
    int _columns;

    static void _processError(int);

public:

    Matrix(int, int);

    Matrix(const Matrix &);

    /*
     * Заполняет массив элементами row+column
     */
    void fillMatrix();

    void printMatrix();

    /*
     * Method changes the element in the matrix to the given.
     * @params: row
     * @params: column
     * @params: element
     */
    void changeElement(int, int, int);

    /*
     * Method returns the element by row, column.
     * @params: row
     * @params: column
     * @returns: element in matrix[row][column]
     */
    int getElement(int, int);

    int getRowsCount() const;

    int getColumnsCount() const;

    ~Matrix();
};

#endif //SEMINAR_MATRIX_H
