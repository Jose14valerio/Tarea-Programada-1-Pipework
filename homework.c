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
  bool returnBool = true;
  int dimensionCounter =0;
  // cannot go east
  // si no es una fuga ni hidrante

  if((pipe == '4' || pipe == '5'|| pipe=='6'|| pipe=='7'|| pipe=='C'|| pipe =='D'|| pipe =='E'|| pipe=='F') &&
  (matriz[fila][columna+1] =='2'||matriz[fila][columna+1]=='4' ||  matriz[fila][columna+1]=='6'||
  matriz[fila][columna+1]=='8'|| matriz[fila][columna+1]=='A'||matriz[fila][columna+1]=='C'||
  matriz[fila][columna+1]=='E'||matriz[fila][columna+1]=='0'||matriz[fila][columna+1]==-1)){
    pipeType->direction = 'E';
    //printf("%c", pipeType->direction);
    returnBool = false;
  }
  //cannot go south
  if((pipe =='2'||pipe=='3'||pipe == '6'||pipe=='7'||pipe=='A'||pipe=='B'||pipe == 'E'||pipe =='F')&&
  (matriz[fila+1][columna]=='2'||matriz[fila+1][columna]=='3'||matriz[fila+1][columna]=='4'
  ||matriz[fila+1][columna]=='5'||matriz[fila+1][columna]=='6'||matriz[fila+1][columna]=='7'
  ||matriz[fila+1][columna]=='1'||matriz[fila+1][columna]=='0'||matriz[fila+1][columna]==-1)){
    pipeType->direction ='S';
    //  printf("%c", pipeType->direction);
    returnBool = false;
  }
  //cannot go west
  if((pipe =='1'||pipe=='3'||pipe == '5'||pipe=='7'||pipe=='9'||pipe=='B'||pipe == 'D'||pipe == 'F')&&
  (matriz[fila][columna-1]=='1'||matriz[fila][columna-1]=='2'||matriz[fila][columna-1]=='3'
  ||matriz[fila][columna-1]=='8'||matriz[fila][columna-1]=='9'||matriz[fila][columna-1]=='A'
  ||matriz[fila][columna-1]=='B'||matriz[fila][columna-1]=='0'||matriz[fila][columna-1]==-1)){
    pipeType->direction ='W';
    //  printf("%c", pipeType->direction);
    returnBool = false;
  }
  //cannot go north
  if((pipe =='8'||pipe=='9'||pipe == 'A'||pipe=='B'||pipe=='C'||pipe=='D'||pipe == 'E'||pipe == 'F')&&
  (matriz[fila-1][columna]=='1'||matriz[fila-1][columna]=='4'||matriz[fila-1][columna]=='5'
  ||matriz[fila-1][columna]=='8'||matriz[fila-1][columna]=='9'||matriz[fila-1][columna]=='C'
  ||matriz[fila-1][columna]=='D'||matriz[fila-1][columna]=='0'||matriz[fila-1][columna]==-1)){
    pipeType->direction ='N';
    //    printf("%c", pipeType->direction);
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
  //memory allocation
  matriz = (char**)malloc(sizeof(char*)*filas+2);
  for (int filaCounter=0; filaCounter<filas+2; filaCounter++){
    matriz[filaCounter] = (char*)malloc(sizeof(char)*columnas+2);
  }
  // llena el rededor con -1
  for (int filaCounter= 0; filaCounter< filas+2; filaCounter++ ){
    for (int columnaCounter=0; columnaCounter<columnas+2; columnaCounter++){
      if(filaCounter ==0 ||columnaCounter ==0 ||filaCounter ==filas+1 || columnaCounter==columnas+1){
        matriz[filaCounter][columnaCounter] = -1;
      }
      else{
        scanf("%s", &matriz[filaCounter][columnaCounter]);
      }
    }
  }
}
void findLeaks(struct Pipe *pipeType, struct Location where[]){

  char focus;
  int dimensionCounter =0;
  // mientras haya revisado todas las fugas y hidrantes
  while (dimensionCounter<fugas+hidrantes){
    // por toda la matriz
    for(int filaCounter =0; filaCounter<filas+2; filaCounter++){
      for(int columnaCounter=0; columnaCounter<columnas+2; columnaCounter++){
        // si hay una fuga y no es una salida ni hidrante
        if(!isCompatible(matriz[filaCounter][columnaCounter], filaCounter, columnaCounter, pipeType)){
          if (filaCounter == where[dimensionCounter].row && columnaCounter == where[dimensionCounter].column){dimensionCounter++;}
          else{
            pipeType->hex = matriz[filaCounter][columnaCounter];
            printf("leak %d %d %c\n",filaCounter,columnaCounter,pipeType->direction);
          }
        }
      }
    }
    dimensionCounter++;
  }

  /*
int filaCounter =0;
int columnaCounter =0;

while(filaCounter<filas+2){
  while (columnaCounter<columnas+2){
    // si hay una fuga y no es una salida ni hidrante
    if(!isCompatible(matriz[filaCounter][columnaCounter], filaCounter, columnaCounter, pipeType)){
      int dimensionCounter =0;
      while (dimensionCounter<fugas+hidrantes){
        // si no es un hidrante o salida
        if ((filaCounter == where[dimensionCounter].row && columnaCounter == where[dimensionCounter].column)){
          columnaCounter++;
          dimensionCounter++;
        }
        else{
          // imprima el tubo
          pipeType->hex = matriz[filaCounter][columnaCounter];
          printf("%c%c %d%d ",pipeType->direction,matriz[filaCounter][columnaCounter],filaCounter,columnaCounter);
          columnaCounter++;
        }


      }

    }
    columnaCounter++;
  }
  filaCounter++;
}
*/
}






void printMatrix(){
  printf("\n");
  for (int filaCounter= 0; filaCounter< filas+2; filaCounter++ ){
    for (int columnaCounter=0; columnaCounter<columnas+2; columnaCounter++){
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
  receiveDetails(where);
  receiveMatrix();
  int dimensionCounter = 0;
  while (dimensionCounter<hidrantes+fugas){
    //scanf("%d %d %c",&where[dimensionCounter].row,&where[dimensionCounter].column,&where[dimensionCounter].cardinal);
    printf("%d %d %c\n",where[dimensionCounter].row,where[dimensionCounter].column,where[dimensionCounter].cardinal);
    dimensionCounter++;
  }
  printMatrix();
  findLeaks(&pipeType, where);



  //findLeaks(pipeType);

  for (int i =0; i<filas+2; i++){
    free(matriz[i]);
  }
  free(matriz);

  return 0;
}
