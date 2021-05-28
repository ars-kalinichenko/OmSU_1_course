#ifndef OMSU_2020_CLI_H
#define OMSU_2020_CLI_H

#include "matrix.h"

void UpdateScreen(Matrix *, int, int, int);

int InputSizeMatrix(int &, int &);

Matrix *CreateZeroMatrix(int &, int &);

Matrix *CreateRandomMatrix(int &, int &);

Matrix *CreateMatrixFromFile(int &, int &);

void MoveArrow(int &, int, int);

int MatrixEditor(Matrix *);

#endif //OMSU_2020_CLI_H
