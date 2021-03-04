#include<iostream>
#include <cstdlib>

using namespace std;
const int MAX_ROWS = 50;
const int MAX_COLUMNS = 50;
typedef double matrix[MAX_ROWS][MAX_COLUMNS];

void ProcessElement(double, bool &, int &);

int Evaluate(matrix, int, int, int &);

int InputSizeMatrix(int, int, int &, int &);

int InputMatrix(matrix mat, int, int);

int RandomInputMatrix(matrix, int, int);

int TestProgram();

int main() {
    TestProgram();
}

void ProcessElement(double element, bool &flag, int &count)
/*
 * Вспомогательная функция для функции Evaluate.
 * Если предыдущий элемент был 0, а новый положительный, то +1 к счетчику.
 * @params:
 *      element - текущий элемент
 *      &flag - показывает, был ли пред.элемент нулем. true - да
 *      &count - количество положительных чисел, до которых был 0
 */
{
    if (flag && element > 0) {
        count++;
        flag = false;
    } else if (element < 0) {
        flag = false;
    } else if (element == 0) {
        flag = true;
    }
}

int Evaluate(matrix arr, int countRows, int countCols, int &result)
/*
 * Функция выполняет основные вычисления - поиск количества положительных чисел, до которых был 0.
 * Матрица перебирается против часовой стрелки, от последнего элемента.
 * @params:
 *      arr - двумерный массив
 *      countRows - количество строк
 *      countCols - количество столбцов
 *      &result - результат вычислений
 * @return:
 *      0 - все прошло штатно
 *      -1 - неправильные размеры массива
 */
{
    int top = 0, bottom = countRows - 1, start = 0, end = countCols - 1;
    bool isZero = false;
    int positiveCount = 0;
    if (countRows <= 0 || countCols <= 0) return -1;
    while (top <= bottom && start <= end) {
        for (int i = bottom; i >= top; --i) {
            ProcessElement(arr[i][end], isZero, positiveCount);
        }
        --end;
        for (int i = end; i >= start; --i) {
            ProcessElement(arr[top][i], isZero, positiveCount);
        }
        ++top;
        for (int i = top; i <= bottom; ++i) {
            ProcessElement(arr[i][start], isZero, positiveCount);
        }
        ++start;    // moving left->right
        for (int i = start; i <= end; ++i) {
            ProcessElement(arr[bottom][i], isZero, positiveCount);
        }
        --bottom;
    }
    result = positiveCount;
    return 0;
}


int InputSizeMatrix(int maxRows, int maxCols, int &countRows, int &countCols)
/*
 * Функция запрашивает у пользователя кол-во строк, столбцов.
 * Больше 0, но меньше максимальных.
 * @params:
 *      maxRows - макс. кол-во строк
 *      maxCols - макс. кол-во столбцов
 * @output by reference:
 *      countRows - кол-во строк
 *      countCols - кол-во столбцов
 */
{
    do {
        cout << "Введите количество строк: ";
        cin >> countRows;
    } while (countRows >= maxRows || countRows <= 0);

    do {
        printf("Введите количество столбцов: ");
        cin >> countCols;
    } while (countCols >= maxCols || countCols <= 0);
    return 0;
}

int InputMatrix(matrix mat, int countRows, int countCols)
/*
 * Функция запрашивает у пользователя элементы матрицы подряд.
 * @params:
 *      mat - двумерный массив вещ.чисел
 *      countRows - количество строк
 *      countCols - количество столбцов
 * @return:
 *      0 - успешное выполнение
 *      -1 - неправильные размеры таблицы
 */
{
    if (countRows <= 0 || countCols <= 0) return -1;
    cout << "Введите элементы матрицы: ";
    for (int i = 0; i < countRows; i++) {
        for (int j = 0; j < countCols; j++) cin >> mat[i][j];
    }
    return 0;
}

int RandomInputMatrix(matrix mat, int rows, int cols)
/*
 * Функция заполняет двумерный массив рандомными числами.
 * @params:
 *      mat - двумерный массив
 *      rows - количество строк
 *      cols - количество столбцов
 * @return:
 *      0 - успешно
 *      -1 - неправильные размеры
 */
{
    int res = 0, i, j;
    if (rows < 1 || rows > MAX_ROWS || cols < 1 || cols > MAX_COLUMNS) { res = -1; }
    else {
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                mat[i][j] = (rand() % 100 - 2);
            }
        }
    }
    return res;
}


int TestProgram()
/*
 * Функция для локального тестирования программы.
 * Интерфейс - меню с 6 командами.
 * @return:
 *      0 - все прошло штатно
 */
{
    int num;
    bool isCreated = false, isEvaluated = false;
    matrix arr;
    int result;
    int rows, columns;

    do {
        cout << "1. Создать таблицу с клавиатуры" << endl;
        cout << "2. Заполнить таблицу случайным образом" << endl;
        cout << "3. Показать таблицу" << endl;
        cout << "4. Выполнить обработку" << endl;
        cout << "5. Показать результат" << endl;
        cout << "6. Завершить работу" << endl;
        do {
            cout << "Введите номер команды: ";
            cin >> num;
        } while (num < 1 || num > 6);
        if (num == 1) {
            InputSizeMatrix(MAX_ROWS, MAX_COLUMNS, rows, columns);
            InputMatrix(arr, rows, columns);
            isCreated = true;
        } else if (num == 2) {
            InputSizeMatrix(MAX_ROWS, MAX_COLUMNS, rows, columns);
            RandomInputMatrix(arr, rows, columns);
            isCreated = true;
        } else if (num == 3) {
            if (isCreated) {
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < columns; j++) printf("%7.2lf  ", arr[i][j]);;
                    cout << endl;
                }
            } else cout << "Матрица не задана!" << endl;
        } else if (num == 4) {
            if (isCreated) {
                Evaluate(arr, rows, columns, result);
                isEvaluated = true;
            } else cout << "Матрица не задана!" << endl;
        } else if (num == 5) {
            if (isEvaluated) {
                cout << "Результат: " << result << endl;
            } else cout << "Невозможно вывести результат. Попробуйте выполнить обработку еще раз!" << endl;
        } else if (num == 6) {
            exit(0);
        }
    } while (num != 6);
    return 0;
}