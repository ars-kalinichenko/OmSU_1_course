#ifndef SEMINAR_MATRIX_H
#define SEMINAR_MATRIX_H

#include <string>
#include <map>

class Matrix {
private:
    int **_matrix;
    int _rows = 0;
    int _columns = 0;

    static void _processError(int);

    /*
     * Подсчитывает максимальную длину положительных чисел в строке
     * @params: int* - указатель на массив, в котором будут храниться ключи.
     *                 Индекс ключа в массиве - номер строки.
     */
    void _calculateKeys(int *);

    void _printKeys(int *) const;

    static void _swapKeys(int, int, int *);

    void _swapRows(int, int);

public:

    Matrix(int, int);

    Matrix(const Matrix &);

    /*
     * Заполняет массив элементами row+column
     */
    void fillMatrix();

    void printMatrix();

    /*
     * Inplace сортирует строки матрицы по невозрастанию максимальной длины цепочки подряд идущих положительных элементов.
     */
    void sortMatrix();

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
