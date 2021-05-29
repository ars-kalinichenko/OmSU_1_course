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
     * Подсчитывает количество отрицательных элементов в каждом столбце
     * @params: int* - указатель на массив, в котором будут храниться ключи.
     *                 Индекс ключа в массиве - номер столбца.
     */
    void _calculateKeys(int *);

    void _printKeys(int *) const;

    void merge(int *, int **, int, int, int);

public:

    Matrix(int, int);

    Matrix(const Matrix &);

    void randomFillMatrix();

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

    void mergeSort(int *, int, int);
};

#endif //SEMINAR_MATRIX_H
