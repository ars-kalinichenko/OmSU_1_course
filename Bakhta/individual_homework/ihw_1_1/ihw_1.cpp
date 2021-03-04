#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

const double EulerConstant = exp(1.0);
const double Pi = 3.141592653589793238463;
const double uncertainty = 0.3;
const double xn = -2.4, xk = 2.4, h = 0.003;
const double pn = -2.0, pk = 2.0;
const int rowMax = 15, columnMax = 2;
const int widthIntY = 6, widthDoubleY = widthIntY - 3;
const int widthIntX = 7, widthFloatX = widthIntX - 3;

int inputParameter(double, double);

void printHead(int, int, int);

void printX(double);

void printY(double);

double calculateFunction(double, double);


int main() {
    /*
     * Здесь табулируется таблица значений функции (Вариант 1).
     * Очищение экрана будет работать только на Linux. 
     * Для очищения экрана на Windows использовать system("cls")
     */
    double x, y;
    int i, j, p, page = 1;
    x = xn;
    p = inputParameter(pn, pk);
    while (x <= xk + uncertainty * h) {
        printf("Parameter = %d, page %d\n", p, page);
        printHead(columnMax, widthIntX, widthIntY);
        for (i = 1; (i <= rowMax) && (x <= xk + uncertainty * h); i++) {
            for (j = 1; (j <= columnMax) && (x <= xk + uncertainty * h); j++) {
                y = calculateFunction(x, p);
                printX(x);
                printY(y);
                x += h;
            }
            printf("\n");
        }
        page++;
        printf("Press Enter for continue...");
        getchar();
        system("clear");
    }
}

void printX(double x) {
    /*
     * @param: х - аргумент функции
     * Печатает х так, чтобы форматирование таблицы не сбивалось.
     * Если х>0, то вместо минуса используется пробел
     */
    printf("! %*.*lf !", widthIntX, widthFloatX, x);

}

void printY(double y) {
    /*
     * @param: y - значение функции
     * Печатает y так, чтобы форматирование таблицы не сбивалось.
     * Если y>0, то вместо минуса используется пробел
     */
    printf("% *.*e !", widthIntY, widthDoubleY, y);

}

void printHead(int column, int widthX, int widthY) {
    /* @param: column - количество колонок
     * Печатает названия колонок в таблице.
     */
    int stepX = 0;
    int stepY = 0;
    if (widthX % 2 == 0)
        stepX = 1;
    if (widthY % 2 == 0)
        stepY = 1;
    int biasY = widthY - stepY + 5;


    for (int i = 0; i < column; i++) {
        printf("! ");
        printf("%*c", (widthX / 2) - stepX, 'X');
        printf("%*s", widthX - stepX, " ! ");
        printf("%*c", biasY / 2, 'Y');
        printf("%*s", biasY / 2 + stepY, " !");
    }
    printf("\n");
}

int inputParameter(double left, double right) {
    /*
     * @param: left - нижняя граница, right - правая граница отрезка
     * Вводится значение параметера до тех пор, пока p не будет принадлежать [left; right]
     * Функция также обрабатывает \n, которое появляется при вводе значения
     * @return: p - значение параметра
     */
    bool isValid = false;
    int p;
    while (!isValid) {
        printf("Введите значение от %.2f до %.2f \n", left, right);
        scanf("%d", &p);
        getchar(); // handle new line
        if (pn <= p && p <= pk) {
            isValid = true;
        }
    }
    return p;
}

double calculateFunction(double x, double p) {
    /*
     * @param: x - аргумент функции, p - параметр, введеный пользователем
     * Вычисляет значение заданной функции (Вариант 1)
     * @return: result - значение функции (y)
     */
    double result;
    if (pow(x, 9) <= pow(EulerConstant, p)) {
        result = log10(1 + abs(p * x));
    } else {
        result = (Pi - atan(p * x) * atan(p * x)) / sqrt(x);
    }
    return result;
}

