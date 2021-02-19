const int MAX_ROWS = 10;
int InitMatrix(int arr[][MAX_ROWS], int rows, int columns)
/*
 * Функция заполняет массив элементами i+j,
 *   где i - номер строки, j - номер столбца.
 * Args:
 *      string &msg - Ссылка на сообщение, которое нужно вывести перед вводом
 *      limit - ограничение ввода сверху
 * Returns:
 *      0 - удачное выполнение
 *      -1 - размеры массива отрицательные или больше констант
 */
{
    int result = 0;
    if (rows <= 0 || columns <= 0 || rows > MAX_ROWS || columns > MAX_COLUMNS) result = -1;
    else {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                arr[i][j] = i + j;
            }
        }
    }
    return result;
}
