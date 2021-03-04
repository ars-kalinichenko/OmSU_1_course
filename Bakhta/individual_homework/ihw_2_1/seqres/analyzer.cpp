#include "analyzer.h"

GeneratorSettings::GeneratorSettings(int num, int l, int r) {
    assert(l <= r);
    numberOfMax = num;
    left = l;
    right = r;
}

int EvaluateCountOfMaximums(ifstream &fin, int &answer) {
    if (!fin) return 1;
    int current, previous, next;
    int count = 0;
    fin >> previous;
    fin >> current;
    if (fin.eof()) return 3;
    while (fin >> next) {
        if (current >= previous and current >= next and !fin.eof()) {
            count++;
        }
        previous = current;
        current = next;
    }
    if (!fin.eof()) return 2;
    answer = count;
    return 0;
}


int GenerateData(ofstream &fot, GeneratorSettings &settings) {
    if (!fot) return 1;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(settings.left, settings.right);
    int count = 0;
    int previous = distr(gen);
    int current = distr(gen);
    int next;

    fot << previous << " " << current << " ";
    while (count < settings.numberOfMax) {
        next = distr(gen);
        fot << next << " ";
        if (current >= previous and current >= next) {
            count++;
        }
        previous = current;
        current = next;
    }
    return 0;
}