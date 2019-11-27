#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int generalInfo[4];
int filas;
int columnas;
int entradas;
int salidas;
int totalLeaks;
struct Location{
  int row;
  int column;
  char cardinal;
};
struct Pipe{
  char direction;
  char hex;
  int row;
  int column;
};

char **matriz;

void receiveInfo();

bool isLeaking(char pipe, int fila, int columna, struct Pipe *pipeType);

void receiveDetails(struct Location leakage[]);

void receiveMatrix();

void findLeaks(struct Pipe *pipeType);

void printMatrix();

void findTrueLeaks(struct Pipe *leakList, struct Pipe *pipeType,struct Location leakage[]);

void printLeaks(struct Pipe *leakList);
