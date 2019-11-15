#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int generalInfo[4];
int filas;
int columnas;
int hidrantes;
int fugas;
struct Location{
  int row;
  int column;
  char cardinal;
};
struct Pipe{
  char direction;
  char hex;
};
char **matriz;



void receiveInfo(){

  char removeSpace;
  int counter = 0;
  while(counter<4){
    scanf("%d",&generalInfo[counter]);
    counter++;
  }
  //scanf("%*c");
  filas = generalInfo[0];
  columnas = generalInfo[1];
  hidrantes = generalInfo[2];
  fugas = generalInfo[3];
}
bool isCompatible(char pipe, int fila, int columna, struct Pipe *pipeType){
  bool returnBool;
  // cannot go east
  if((pipe == '4' || pipe == '5'|| pipe=='6'|| pipe=='7'|| pipe=='C'|| pipe =='D'|| pipe =='E'|| pipe=='F') &&
   (matriz[fila][columna+1] !='1'||matriz[fila][columna+1]!='3' ||  matriz[fila][columna+1]!='5'||
   matriz[fila][columna+1]!='7' || matriz[fila][columna+1]!='9'||matriz[fila][columna+1]!='B'||matriz[fila][columna+1]!='D'||matriz[fila][columna+1]!='F')){
    pipeType->direction = 'E';
    returnBool = false;
    }
//cannot go south
  if((pipe =='2'||pipe=='3'||pipe == '6'||pipe=='7'||pipe=='A'||pipe=='B'||pipe == 'E'||pipe =='F')&&(matriz[fila+1][columna]!='8'
  ||matriz[fila+1][columna]!='9'||matriz[fila+1][columna]!='A'
  ||matriz[fila+1][columna]!='B'||matriz[fila+1][columna]!='C'||matriz[fila+1][columna]!='D'||matriz[fila+1][columna]!='E' ||matriz[fila+1][columna]!='F')){
    pipeType->direction ='S';
    returnBool = false;
  }
  //cannot go west
  if((pipe =='1'||pipe=='3'||pipe == '5'||pipe=='7'||pipe=='9'||pipe=='B'||pipe == 'D'||pipe == 'F')&&(matriz[fila+1][columna]!='4'
  ||matriz[fila][columna-1]!='5'||matriz[fila+1][columna]!='6'
  ||matriz[fila][columna-1]!='7'||matriz[fila+1][columna]!='C'||matriz[fila+1][columna]!='D'||matriz[fila+1][columna]!='E' ||matriz[fila+1][columna]!='F')){
    pipeType->direction ='W';
    returnBool = false;
  }
  //cannot go north
  if((pipe =='8'||pipe=='9'||pipe == 'A'||pipe=='B'||pipe=='C'||pipe=='D'||pipe == 'E'||pipe == 'F')&&(matriz[fila+1][columna]!='2'
  ||matriz[fila-1][columna]!='3'||matriz[fila+1][columna]!='6'
  ||matriz[fila-1][columna]!='7'||matriz[fila+1][columna]!='A'||matriz[fila+1][columna]!='B'||matriz[fila+1][columna]!='E' ||matriz[fila+1][columna]!='F')){
    pipeType->direction ='N';
    returnBool = false;
  }
  //cannot go north
  return returnBool;
  }
void receiveDetails(struct Location where[]){
  int dimensionCounter = 0;
  while (dimensionCounter<hidrantes+fugas){
    scanf("%d %d %c",&where[dimensionCounter].row,&where[dimensionCounter].column,&where[dimensionCounter].cardinal);
    //printf("%d %d %c\n",where[dimensionCounter].row,where[dimensionCounter].column,where[dimensionCounter].cardinal);
  dimensionCounter++;
  }
}
void receiveMatrix(){
  matriz = (char**)malloc(sizeof(char*)*filas);
  for (int filaCounter=0; filaCounter<filas; filaCounter++){
    matriz[filaCounter] = (char*)malloc(sizeof(char)*columnas);
  }

   for (int filaCounter= 0; filaCounter< filas; filaCounter++ ){
    for (int columnaCounter=0; columnaCounter<columnas; columnaCounter++){
      scanf("%s", &matriz[filaCounter][columnaCounter]);
    }
  }
}
void findLeaks(struct Pipe *pipeType){
  char focus;
  for(int filaCounter =0; filaCounter<filas; filaCounter++){
    for(int columnaCounter=0; columnaCounter<columnas; columnaCounter++){
      focus = matriz[filaCounter][columnaCounter];
      if(!isCompatible(focus, filaCounter, columnaCounter, &pipeType)){
        pipeType->hex = focus;
      }
    }
  }
}

void printMatrix(){
  printf("\n");
  for (int filaCounter= 0; filaCounter< filas; filaCounter++ ){
    for (int columnaCounter=0; columnaCounter<columnas; columnaCounter++){
      printf("%c", matriz[filaCounter][columnaCounter]);
    }
    printf("\n");
  }
}


int main(){
  struct Pipe pipeType;

  receiveInfo();
  // create struct to save variables
  struct Location where[hidrantes+fugas];
  receiveDetails(&where);
  receiveMatrix();
  // printMatrix();
  findLeaks(&pipeType);

for (int i =0; i<columnas; i++){
  free(matriz[i]);
}
free(matriz);

return 0;
}
