#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
  entradas = generalInfo[2];
  salidas = generalInfo[3];
}
bool isLeaking(char pipe, int fila, int columna, struct Pipe *pipeType){
  bool returnBool = false;


  // cannot go NORTH
  // si no es una entrada ni salida
  if((pipe =='8'||pipe=='9'||pipe == 'A'||pipe=='B'||pipe=='C'||pipe=='D'||pipe == 'E'||pipe == 'F')&&
  (matriz[fila-1][columna]=='1'||matriz[fila-1][columna]=='4'||matriz[fila-1][columna]=='5'
  ||matriz[fila-1][columna]=='8'||matriz[fila-1][columna]=='9'||matriz[fila-1][columna]=='C'
  ||matriz[fila-1][columna]=='D'||matriz[fila-1][columna]=='0'||matriz[fila-1][columna]==-1)){

    pipeType[totalLeaks].direction ='N';
    pipeType[totalLeaks].row = fila;
    pipeType[totalLeaks].column = columna;
    totalLeaks++;
    returnBool = true;
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
    returnBool = true;
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
    returnBool = true;
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
    returnBool = true;
  }
  return returnBool;
}
void receiveDetails(struct Location leakage[]){
  int dimensionCounter = 0;
  while (dimensionCounter<entradas+salidas){
    scanf("%d %d %c",&leakage[dimensionCounter].row,&leakage[dimensionCounter].column,&leakage[dimensionCounter].cardinal);
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
void findLeaks(struct Pipe *pipeType){
  char focus;
  // mientras haya revisado todas las salidas y entradas
  // por toda la matriz
  for(int filaCounter =0; filaCounter<filas+2; filaCounter++){
    for(int columnaCounter=0; columnaCounter<columnas+2; columnaCounter++){
      // si hay una fuga y no es una salida ni hidrante
      if(!isLeaking(matriz[filaCounter][columnaCounter], filaCounter, columnaCounter, pipeType)){
        printf("solved");
      }
      //  printf("TOTAL LEAKS: %d fila: %d columna:%d\n",totalLeaks,filaCounter, columnaCounter);

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
void findTrueLeaks(struct Pipe *leakList, struct Pipe *pipeType,struct Location leakage[]){
  int counter3=0;
  for(int counter =0; counter<totalLeaks;counter++){
    int counter2=0;
    for(int counter1= 0; counter1<entradas+salidas; counter1++){
      if ((pipeType[counter].row ==leakage[counter1].row && pipeType[counter].column ==leakage[counter1].column
        && pipeType[counter].direction == leakage[counter1].cardinal)){
          counter2++;
      }
    }

    if (counter2==0){

      leakList[counter3].row = pipeType[counter].row;
      leakList[counter3].column = pipeType[counter].column;
      leakList[counter3].direction = pipeType[counter].direction;
      counter3++;
    }
  }
}
void printLeaks(struct Pipe *leakList){
  for(int counter3 =0; counter3<totalLeaks-(entradas+salidas);counter3++){
  printf("leaks %d %d %c\n", leakList[counter3].row, leakList[counter3].column,leakList[counter3].direction);
  }
}
int main(){

  receiveInfo();
  // create struct to save variables
  struct Location leakage[entradas+salidas];
  struct Pipe pipeType[(filas*columnas)-(salidas+entradas)];
  // llenarlo con numeros raros para ver si funciona
  /*
  for (int counter =0; counter<(filas*columnas)-(salidas+entradas); counter++){
    pipeType[counter].row = -1 ;
    pipeType[counter].column = -1 ;
    pipeType[counter].direction = 'Q' ;
  }
  */
  receiveDetails(leakage);
  receiveMatrix();
  printMatrix();
  findLeaks(pipeType);
  struct Pipe leakList[totalLeaks-(entradas+salidas)];
  findTrueLeaks(leakList,pipeType, leakage);
  printLeaks(leakList);
//free 2d array
for (int i =0; i<filas+2; i++){
  free(matriz[i]);
}
free(matriz);

return 0;
}
