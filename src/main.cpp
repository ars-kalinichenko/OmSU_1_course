#include <iostream>
#include "matrix.h"

using namespace std;

int main() {
    int rows, columns;
    cout << "Enter rows, columns: ";
    cin >> rows >> columns;
    Matrix matrix(rows, columns);
    matrix.fillMatrix();
    matrix.printMatrix();
    matrix.getElement(-1, -1);
    matrix.changeElement(0, 0, 99);
    int columnsCount = matrix.getColumnsCount();
    int rowsCount = matrix.getRowsCount();
    matrix.printMatrix();
    cout << rowsCount << " " << columnsCount << endl;

    return 0;
}
