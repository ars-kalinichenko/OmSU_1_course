#include <include/cli.h>
#include <iostream>
#include <ncurses.h>

using namespace std;

void clearScreen() {
    cout << string(100, '\n');
}

void UpdateScreen(Matrix *matrix, int inputtedRow, int inputtedColumn, int element) {
    clearScreen();
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