#include <iostream>
#include <fstream>
#include <random>
#include <cassert>
#include "analyzer.h"

using namespace std;
//2 вариант.


int main() {
    ofstream fot("../generated.txt");
    GeneratorSettings settings = GeneratorSettings(1000, -500, 500);
    GenerateData(fot, settings);
    fot.close();

    ifstream fin;
    fin.open("../generated.txt");
    int answer = 0;
    int code = EvaluateCountOfMaximums(fin, answer);
    cout << "Finished with code: " << code << endl;
    cout << "Answer: " << answer << endl;
    fin.close();
    return 0;
}


