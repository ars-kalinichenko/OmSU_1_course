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
    matrix.sortMatrix();
    cout << endl << "Матрица, отсортированная по максимальной длине положительных цепочек в строках:" << endl;
    matrix.printMatrix();
    return 0;
}
