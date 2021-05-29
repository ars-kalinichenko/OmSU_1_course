#include <include/cli.h>
#include <iostream>
#include <ncurses.h>
#include <fstream>
using namespace std;

void UpdateScreen(Matrix *matrix, int inputtedRow, int inputtedColumn, int element) {
    clear();
    for (int row = 0; row < matrix->getRowsCount(); row++) {
        for (int column = 0; column < matrix->getColumnsCount(); column++) {
            if (row == inputtedRow and column == inputtedColumn) {
                printw("[%s]", to_string(matrix->getElement(column, row)).c_str());
            } else {
                printw("%s", to_string(matrix->getElement(column, row)).c_str());
            }
            printw(" ");
            refresh();
        }
        printw("\n");
    }
    printw("Row: %s ", to_string(inputtedRow).c_str());
    printw("Column: %s", to_string(inputtedColumn).c_str());
    printw("\n");

    printw("Current element: ");
    printw(to_string(element).c_str());
}

int InputSizeMatrix(int &countRows, int &countCols)
{
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

bool CreateMatrixFromFile(int rows, int columns, fstream &fin, Matrix *matrix) {
    int element;
    if (fin.is_open()) {
        for (int col = 0; col < columns; col++) {  // stop loops if nothing to read
            for (int row = 0; row < rows; row++) {
                fin >> element;
                matrix->changeElement(col, row, element);
            }
        }
        return true;
    } else {
        return false;
    }
}

void MoveArrow(int &arrow, int direction, int limit) {
    if (arrow + direction >= 0 and arrow + direction < limit) {
        arrow += direction;
    }
}

void MatrixEditor(Matrix *matrix) {
    int c, column = 0, row = 0;
    int element;
    bool enterPressed = false;
    int changedElement;
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    UpdateScreen(matrix, row, column, matrix->getElement(0, 0));

    do {
        c = getch();
        if (c == KEY_RIGHT) {
            MoveArrow(column, 1, matrix->getColumnsCount());
        } else if (c == KEY_LEFT) {
            MoveArrow(column, -1, matrix->getColumnsCount());
        } else if (c == KEY_UP) {
            MoveArrow(row, -1, matrix->getRowsCount());
        } else if (c == KEY_DOWN) {
            MoveArrow(row, 1, matrix->getRowsCount());
        } else if (c == 10) {
            enterPressed = !enterPressed;
            if (enterPressed) {
                printw("\nInput your element ");
                scanw("%i", &changedElement);
                matrix->changeElement(column, row, changedElement);
            }
        }
        element = matrix->getElement(row, column);
        UpdateScreen(matrix, row, column, element);
        refresh();
    } while (c != 27);
    endwin();
}