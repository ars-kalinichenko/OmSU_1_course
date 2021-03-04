#ifndef TESTER_TESTER_H
#define TESTER_TESTER_H

#include <iostream>
#include "seqres.h"
#include <cstdlib>
#include <ctime>

void TestFromFile(ofstream &, ifstream &);

void TestFromFileWithInput(ofstream &);

void TestRandomSequenceWithParams(ofstream &);

void TestFullRandom(ofstream &);

void TestSequenceResearchModule();

#endif //TESTER_TESTER_H
