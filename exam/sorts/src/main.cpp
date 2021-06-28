#include "iostream"
#include "fstream"

using namespace std;

struct Data {
    int key;
    char data;
};

void InsertionSort(Data *arr, int n) {
    // Устойчивая сортировка вставками. Выбираем один элемент, сравниваем его с предыдущими. Если условие выполняется, вставляем

    Data x{};
    int index;
    for (int i = 1; i < n; i++) {
        x = arr[i];
        index = i;
        while (arr[index - 1].key > x.key && index > 0) {
            arr[index] = arr[index - 1];
            index--;
        }
        arr[index] = x;
    }

}

void SelectionSort(Data *arr, int n) {
    // Устойчивая сортировка выбором. Выбираем минимум, меняем его с первым элементом, находим следующий - меняем со вторым...

    Data min_value{};
    int min_index; // индекс минимума
    for (int i = 0; i < n; i++) {
        min_value = arr[i];
        min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].key < min_value.key) {
                min_value = arr[j];
                min_index = j;
            }
        }
        arr[min_index] = arr[i];
        arr[i] = min_value;
    }
}

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

void ShellSort(Data *arr, int n, int *h, int m) {
    // НЕ устойчивая сортировка

    Data x{};
    int j, k;

    for (int t = 0; t < m; t++) {
        k = h[t]; // текущее смещение
        for (int i = k; i < n; i += k) {
            x = arr[i];
            j = i - k;
            while (arr[j].key > x.key && j >= 0) {
                arr[j + k] = arr[j];
                j -= k;
            }
            arr[j + k] = x;
        }
    }
}

void QuickSort(Data *arr, int l, int r) {
    // НЕ устойчивая сортировка

    Data pivot{}, y{};
    int i = l, j = r;
    pivot = arr[(l + r) / 2];

    while (i < j) {
        while (arr[i].key < pivot.key) i++;
        while (arr[j].key > pivot.key) j--;
        if (i <= j) {
            y = arr[i];
            arr[i] = arr[j];
            arr[j] = y;
            i++;
            j--;
        }
    }
    if (l < j) QuickSort(arr, l, j);
    if (i < r) QuickSort(arr, i, r);
}

int main() {
    ifstream fin;
    fin.open("/home/arseny/projects/OmSU_1_course/exam/sorts/src/input.txt");

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
    QuickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) cout << arr[i].data << " ";


    // Вызов сортировки
    // int h[]{5, 3, 1};
    // ShellSort(arr, n, h, 3);
    // for (int i = 0; i < n; i++) cout << arr[i].data << " ";

}
