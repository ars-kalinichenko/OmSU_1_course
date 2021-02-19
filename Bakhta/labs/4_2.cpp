#include <iostream>

using namespace std;
const int MAX_LENGTH = 100;

int AverageArray(const float *arr, int len, float &ans)
/*
 * Функция считает среднее арифметическое элементов массива.
 * Args:
 *      float *arr - указатель на массив
 *      len - длина массива
 *      &ans - переменная, в которую записывается результат
 *
 * Returns:
 *         0 - удачное выполнение
 *         -1 - если длина отрицательна
 */
{
    float t = 0;
    int result = 0;
    if (len <= 0 || len > MAX_LENGTH) result = -1;
    else {
        for (int i = 0; i < len; i++) {
            t = t + arr[i];
        }

        ans = t / (float) len;
    }
    return result;
}


int main() {
    int a, c;
    float b[MAX_LENGTH], d;
    cout << "Input length of array: ";
    cin >> c;
    cout << "Input array:" << endl;
    if (c < MAX_LENGTH && c > 0) {
        for (int i = 0; i < c; i++) {
            cin >> b[i];
        }
        a = AverageArray(b, c, d);
        cout << "Average is " << d << endl;
    }
}