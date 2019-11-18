#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int generalInfo[4];
int filas;
int columnas;
int hidrantes;
int fugas;
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


  // cannot go NORTH
  // si no es una fuga ni hidrante
  if((pipe =='8'||pipe=='9'||pipe == 'A'||pipe=='B'||pipe=='C'||pipe=='D'||pipe == 'E'||pipe == 'F')&&
  (matriz[fila-1][columna]=='1'||matriz[fila-1][columna]=='4'||matriz[fila-1][columna]=='5'
  ||matriz[fila-1][columna]=='8'||matriz[fila-1][columna]=='9'||matriz[fila-1][columna]=='C'
  ||matriz[fila-1][columna]=='D'||matriz[fila-1][columna]=='0'||matriz[fila-1][columna]==-1)){

    pipeType[totalLeaks].direction ='N';
    pipeType[totalLeaks].row = fila;
    pipeType[totalLeaks].column = columna;
    totalLeaks++;
    returnBool = false;
  }
  //CANNOT GO EAST
  if((pipe == '4' || pipe == '5'|| pipe=='6'|| pipe=='7'|| pipe=='C'|| pipe =='D'|| pipe =='E'|| pipe=='F') &&
  (matriz[fila][columna+1] =='2'||matriz[fila][columna+1]=='4' ||  matriz[fila][columna+1]=='6'||
  matriz[fila][columna+1]=='8'|| matriz[fila][columna+1]=='A'||matriz[fila][columna+1]=='C'||
  matriz[fila][columna+1]=='E'||matriz[fila][columna+1]=='0'||matriz[fila][columna+1]==-1)){
    pipeType[totalLeaks].direction = 'E';
    pipeType[totalLeaks].row = fila;
    pipeType[totalLeaks].column = columna;
    totalLeaks++;
    returnBool = false;
  }
  //CANNOT GO SOUTH
  if((pipe =='2'||pipe=='3'||pipe == '6'||pipe=='7'||pipe=='A'||pipe=='B'||pipe == 'E'||pipe =='F')&&
  (matriz[fila+1][columna]=='2'||matriz[fila+1][columna]=='3'||matriz[fila+1][columna]=='4'
  ||matriz[fila+1][columna]=='5'||matriz[fila+1][columna]=='6'||matriz[fila+1][columna]=='7'
  ||matriz[fila+1][columna]=='1'||matriz[fila+1][columna]=='0'||matriz[fila+1][columna]==-1)){
    pipeType[totalLeaks].direction = 'S';
    pipeType[totalLeaks].row = fila;
    pipeType[totalLeaks].column = columna;
    totalLeaks++;
    returnBool = false;
  }
  //CANNOT GO WEST
  if((pipe =='1'||pipe=='3'||pipe == '5'||pipe=='7'||pipe=='9'||pipe=='B'||pipe == 'D'||pipe == 'F')&&
  (matriz[fila][columna-1]=='1'||matriz[fila][columna-1]=='2'||matriz[fila][columna-1]=='3'
  ||matriz[fila][columna-1]=='8'||matriz[fila][columna-1]=='9'||matriz[fila][columna-1]=='A'
  ||matriz[fila][columna-1]=='B'||matriz[fila][columna-1]=='0'||matriz[fila][columna-1]==-1)){
    pipeType[totalLeaks].direction = 'W';
    pipeType[totalLeaks].row = fila;
    pipeType[totalLeaks].column = columna;
    totalLeaks++;
    returnBool = false;
  }
  return returnBool;
}
void receiveDetails(struct Location where[]){
  int dimensionCounter = 0;
  while (dimensionCounter<hidrantes+fugas){
    scanf("%d %d %c",&where[dimensionCounter].row,&where[dimensionCounter].column,&where[dimensionCounter].cardinal);
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
  // mientras haya revisado todas las fugas y hidrantes
    // por toda la matriz
    for(int filaCounter =0; filaCounter<filas+2; filaCounter++){
      for(int columnaCounter=0; columnaCounter<columnas+2; columnaCounter++){
        // si hay una fuga y no es una salida ni hidrante
        if(!isCompatible(matriz[filaCounter][columnaCounter], filaCounter, columnaCounter, pipeType)){
            printf("TOTAL LEAKS%d\n",totalLeaks);
        }
      }
    }
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

  receiveInfo();
  // create struct to save variables
  struct Location where[hidrantes+fugas];
  struct Pipe pipeType[(filas*columnas)-(fugas+hidrantes)];
  // llenarlo con numeros raros para ver si funciona
  for (int counter =0; counter<(filas*columnas)-(fugas+hidrantes); counter++){
    pipeType[counter].row = -1 ;
      pipeType[counter].column = -1 ;
        pipeType[counter].direction = 'Q' ;
  }
  receiveDetails(where);
  receiveMatrix();
  int dimensionCounter = 0;
  while (dimensionCounter<hidrantes+fugas){
    //scanf("%d %d %c",&where[dimensionCounter].row,&where[dimensionCounter].column,&where[dimensionCounter].cardinal);
    printf("%d %d %c\n",where[dimensionCounter].row,where[dimensionCounter].column,where[dimensionCounter].cardinal);
    dimensionCounter++;
  }
  printMatrix();
  findLeaks(pipeType, where);

  /** AQUI YO ESTOY INTENTANDO QUITAR LAS SALIDAS Y ENTRADAS DE LAS FUGAS
  int counter1 =0;
    while (counter1<hidrantes+fugas){
      for(int counter =0; counter<totalLeaks;counter++){
    if ((pipeType[counter].row !=where[counter1].row) && (pipeType[counter].column !=where[counter1].column) && (pipeType[counter].direction != where[counter1].cardinal)){
    printf("leak %d %d %c ",pipeType[counter].row,pipeType[counter].column, pipeType[counter].direction);

  }
  counter1++;
  }
  counter1++;
}
*/

  //findLeaks(pipeType);

  for (int i =0; i<filas+2; i++){
    free(matriz[i]);
  }
  free(matriz);

  return 0;
}
