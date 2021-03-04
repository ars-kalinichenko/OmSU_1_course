#include "tester.h"

void TestFromFile(ofstream &fot, ifstream &fin) {
    int answer = 0;
    int code = EvaluateCountOfMaximums(fin, answer);

    fot << "<TestFromFile> Finished with code: " << code << endl;
    fot << "<TestFromFile> Answer: " << answer << endl << endl;
}

void TestFromFileWithInput(ofstream &fot) {
    string DEFAULT_PATH = "../output.txt";
    string path;
    ifstream fin;

    cout << "Введите путь к файлу с последовательностью: ";
    cin >> path;
    if (path.empty()) path = DEFAULT_PATH;

    fot << "Открывается файл для тестирования: " << path << endl;
    fin.open(path);
    TestFromFile(fot, fin);
    fin.close();
}

void TestRandomSequenceWithParams(ofstream &fot) {
    string GEN_FILE_PATH = "../generated.txt";
    int num, left, right;
    string agree;
    ofstream genFile(GEN_FILE_PATH);

    cout << "Введите количество максимумов, левую границу элементов последовательности и правую: ";
    cin >> num >> left >> right;
    if (left >= right) {
        fot << "Ошибка! Вы указали левую границу больше, чем правую!" << endl;
    }
    GeneratorSettings settings = GeneratorSettings(num, left, right);
    GenerateData(genFile, settings);
    genFile.close();

    fot << "Рандомные данные были записаны в файл: " << GEN_FILE_PATH << endl;
    fot << "Количество заданных максимумов: " << num << endl;
    fot << "Элементы последовательности из [" << left << "; " << right << "]" << endl;

    cout << "Протестировать? y/n: ";
    cin >> agree;
    if (agree == "y" or agree == "Yes" or agree == "Y") {
        ifstream fin(GEN_FILE_PATH);
        TestFromFile(fot, fin);
        fin.close();
    }
}

void TestFullRandom(ofstream &fot) {
    string GEN_FILE_PATH = "../generated.txt";
    srand((int) time(nullptr));
    int num = rand() % 1000;
    int right = rand() % 100;
    int left = -right;

    string agree;
    ofstream genFile(GEN_FILE_PATH);

    GeneratorSettings settings = GeneratorSettings(num, left, right);
    GenerateData(genFile, settings);
    genFile.close();

    fot << "Рандомные данные были записаны в файл: " << GEN_FILE_PATH << endl;
    fot << "Количество заданных максимумов: " << num << endl;
    fot << "Элементы последовательности из [" << left << "; " << right << "]" << endl;

    cout << "Протестировать? y/n: ";
    cin >> agree;
    if (agree == "y" or agree == "Yes" or agree == "Y") {
        ifstream fin(GEN_FILE_PATH);
        TestFromFile(fot, fin);
        fin.close();
    }
}

void TestSequenceResearchModule() {
    string DEFAULT_LOG_FILE = "../seqres.log";
    string logPath;
    ofstream fot;

    cout << "Введите путь для логгирования (для пропуска шага введите no): ";
    cin >> logPath;

    if (logPath == "no") logPath = DEFAULT_LOG_FILE;
    fot.open(logPath, ios_base::app);

    int num;
    do {
        cout << "1. Взять последовательность из файла" << endl;
        cout << "2. Заполнить последовательность случайным образом" << endl;
        cout << "3. Заполнить последовательность случайно, с заданными параметрами" << endl;
        cout << "4. В каком файле находится лог тестирования?" << endl;
        cout << "5. Завершить работу" << endl;
        do {
            cout << "Введите номер команды: ";
            cin >> num;
        } while (num < 1 || num > 5);
        if (num == 1) {
            TestFromFileWithInput(fot);
        } else if (num == 2) {
            TestFullRandom(fot);
        } else if (num == 3) {
            TestRandomSequenceWithParams(fot);
        } else if (num == 4) {
            cout << logPath << endl;
        } else if (num == 5) {
            fot.close();
            exit(0);
        }
    } while (num != 6);
}