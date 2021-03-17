#include <iostream>

using namespace std;

/*Сортирока бинарными включениями*/
void sort_bin(int *data, const int size) {
    int pos;
    int start;
    int end;
    int i;
    int numToInsert;
    int middle;
    for (i = 0; i < size; i++) {
        pos = -1;
        start = 0;
        end = i - 1;
        numToInsert = data[i];
        // Находим место вставки с помощью бинарного поиска
        while (start < end && pos == -1) {
            middle = (start + end) / 2;
            if (numToInsert > data[middle]) {
                start = middle + 1;
            } else if (numToInsert < data[middle]) {
                end = middle - 1;
            } else {
                pos = middle;
            }
        }
        if (end < 0) {
            // определяем позицию в случае если элемент меньше всех отсортированных
            pos = 0;
        } else if (start > i) {
            // определяем позицию в случае если элемент больше всех отсортированных
            pos = i;
        }
        if (pos < i) {
            // сдвигаем элементы вправо на одну позицию
            int j;
            for (j = i; j > pos; j--) {
                data[j] = data[j - 1];
            }
            data[pos] = numToInsert;
        }
    }
}

int main() {
    int data[30];
    int n;
    for (int &i : data) i = -100;
    cout << "Введите длину массива: ";
    cin >> n;
    cout << "Введите сам массив" << endl;
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    cout << endl;
    sort_bin(data, n);
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }
}