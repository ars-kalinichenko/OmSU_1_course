#ifndef IHW_4_ANALYZER_H
#define IHW_4_ANALYZER_H

#include <iostream>
#include <fstream>
#include <random>
#include <cassert>

using namespace std;

struct GeneratorSettings {
    int numberOfMax;
    int left;
    int right;

    /*
    * @params: num - кол-во нестрогих локальных максимумов
    * @params: l - граница отрезка слева
    * @params: r - граница отрезка справа
    */
    GeneratorSettings(int num, int l, int r);
};

/*
 * Функция подсчитывает количество нестрогих локальных максимумов.
 * @params: ifstream& - ссылка на файловый поток
 * @params: int& - ссылка на переменную для ответа
 * @return: Код завершения:
 *              0 - всё ок
 *              1 - проблемы с файловым потоком
 *              2 - ошибка обработки файла
 *              3 - недостаточно данных
 */
int EvaluateCountOfMaximums(ifstream &, int &);

/*
 * Генерирует последовательность чисел внутри файла по заданным параметрам.
 * @params: ofstream & - файловый поток для ввода последовательности
 * @params: GeneratorSettings - ссылка на структуру настроек для генератора
 * @return: Код завершения:
 *              0 - всё ок
 *              1 - проблемы с файловым потоком
 */
int GenerateData(ofstream &, GeneratorSettings &);

#endif //IHW_4_ANALYZER_H
