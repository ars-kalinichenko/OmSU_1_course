#include "iostream"
#include "fstream"

using namespace std;

struct Data {
    int key;
    char data;
};

void BubbleSort(Data *arr, int n) {
    // Устойчивая сортировка пузырьком, попарное сравнение - максимальный элемент уходит в конец

    Data temp{};
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            if (arr[j - 1].key > arr[j].key) {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    ifstream fin;
    fin.open("input.txt");

    if (!fin) {
        cout << "File is closed!" << endl;
    }

    // Чтение данных из файла
    int n;
    fin >> n;
    Data *arr = new Data[n];
    for (int i = 0; i < n; i++) {
        fin >> arr[i].data >> arr[i].key;
    }

    // Вызов сортировки
    BubbleSort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i].data << " ";
}