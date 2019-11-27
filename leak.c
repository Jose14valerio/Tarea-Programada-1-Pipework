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
bool isLeaking(char pipe, int fila, int columna, struct Pipe *pipeType, struct Location *leakage){
  bool returnBool = false;
  int fakeLeak =0;

  // cannot go NORTH
  // si no es una entrada ni salida
  // If it cant go north
  for (int counter= 0; counter<entradas+salidas; counter++){
    if( fila ==leakage[counter].row && columna == leakage[counter].column && leakage[counter].cardinal =='N' ){
      if(matriz[fila][columna]==0||matriz[fila][columna]==1||matriz[fila][columna]==2||matriz[fila][columna]==3
        ||matriz[fila][columna]==4||matriz[fila][columna]==5||matriz[fila][columna]==6||matriz[fila][columna]==7){
          pipeType[totalLeaks].direction ='N';
          pipeType[totalLeaks].row =fila;
          pipeType[totalLeaks].column = columna;
          pipeType[totalLeaks].hex = pipe;
          totalLeaks++;
        }
        else{
          fakeLeak++;
        }
      }

    }
    if((pipe =='8'||pipe=='9'||pipe == 'A'||pipe=='B'||pipe=='C'||pipe=='D'||pipe == 'E'||pipe == 'F')&&
    (matriz[fila-1][columna]=='1'||matriz[fila-1][columna]=='4'||matriz[fila-1][columna]=='5'
    ||matriz[fila-1][columna]=='8'||matriz[fila-1][columna]=='9'||matriz[fila-1][columna]=='C'
    ||matriz[fila-1][columna]=='D'||matriz[fila-1][columna]=='0'||matriz[fila-1][columna]==-1)){
      // si no encontro entrada o salida, asigne como leak
      if (fakeLeak==0){
        pipeType[totalLeaks].direction ='N';
        pipeType[totalLeaks].row = fila;
        pipeType[totalLeaks].column = columna;
        pipeType[totalLeaks].hex = pipe;
        totalLeaks++;
        //    printf("%d %d %c",pipeType[totalLeaks].row,pipeType[totalLeaks].column,pipeType[totalLeaks].direction);
        returnBool = true;

      }
      fakeLeak=0;
    }
    //CANNOT GO EAST
    for (int counter= 0; counter<entradas+salidas; counter++){
      if( fila ==leakage[counter].row && columna == leakage[counter].column && leakage[counter].cardinal =='E' ){
        if(matriz[fila][columna]=='0'||matriz[fila][columna]=='1'||matriz[fila][columna]=='2'||matriz[fila][columna]=='3'
        ||matriz[fila][columna]=='8'||matriz[fila][columna]=='9'||matriz[fila][columna]=='A'||matriz[fila][columna]=='B'){
          pipeType[totalLeaks].direction ='E';
          pipeType[totalLeaks].row =fila;
          pipeType[totalLeaks].column = columna;
          pipeType[totalLeaks].hex = pipe;
          totalLeaks++;
        }
        else{
          fakeLeak++;
        }
      }
    }
    if((pipe == '4' || pipe == '5'|| pipe=='6'|| pipe=='7'|| pipe=='C'|| pipe =='D'|| pipe =='E'|| pipe=='F') &&
    (matriz[fila][columna+1] =='2'||matriz[fila][columna+1]=='4' ||  matriz[fila][columna+1]=='6'||
    matriz[fila][columna+1]=='8'|| matriz[fila][columna+1]=='A'||matriz[fila][columna+1]=='C'||
    matriz[fila][columna+1]=='E'||matriz[fila][columna+1]=='0'||matriz[fila][columna+1]==-1)){
      if(fakeLeak==0){
        pipeType[totalLeaks].direction = 'E';
        pipeType[totalLeaks].row = fila;
        pipeType[totalLeaks].column = columna;
        pipeType[totalLeaks].hex = pipe;
        totalLeaks++;
        //    printf("%d %d %c",pipeType[totalLeaks].row,pipeType[totalLeaks].column,pipeType[totalLeaks].direction);
        returnBool = true;
      }
      fakeLeak=0;
    }
    //CANNOT GO SOUTH
    for (int counter= 0; counter<entradas+salidas; counter++){
      if(fila ==leakage[counter].row && columna == leakage[counter].column && leakage[counter].cardinal =='S' ){
        if(matriz[fila][columna]=='0'||matriz[fila][columna]=='1'||matriz[fila][columna]=='4'||matriz[fila][columna]=='5'
        ||matriz[fila][columna]=='8'||matriz[fila][columna]=='9'||matriz[fila][columna]=='C'||matriz[fila][columna]=='D'){
          pipeType[totalLeaks].direction ='S';
          pipeType[totalLeaks].row =fila;
          pipeType[totalLeaks].column = columna;
          pipeType[totalLeaks].hex = pipe;
          totalLeaks++;
        }
        else{
          fakeLeak++;
        }
      }
    }
    if((pipe =='2'||pipe=='3'||pipe == '6'||pipe=='7'||pipe=='A'||pipe=='B'||pipe == 'E'||pipe =='F')&&
    (matriz[fila+1][columna]=='2'||matriz[fila+1][columna]=='3'||matriz[fila+1][columna]=='4'
    ||matriz[fila+1][columna]=='5'||matriz[fila+1][columna]=='6'||matriz[fila+1][columna]=='7'
    ||matriz[fila+1][columna]=='1'||matriz[fila+1][columna]=='0'||matriz[fila+1][columna]==-1)){
      if(fakeLeak==0){
        pipeType[totalLeaks].direction = 'S';
        pipeType[totalLeaks].row = fila;
        pipeType[totalLeaks].column = columna;
        pipeType[totalLeaks].hex = pipe;
        totalLeaks++;
        //printf("%d %d %c",pipeType[totalLeaks].row,pipeType[totalLeaks].column,pipeType[totalLeaks].direction);
        returnBool = true;
      }
      fakeLeak=0;
    }
    //CANNOT GO WEST
    for (int counter= 0; counter<entradas+salidas; counter++){
      if(fila ==leakage[counter].row && columna == leakage[counter].column && leakage[counter].cardinal =='W' ){
        if(matriz[fila][columna]=='0'||matriz[fila][columna]=='2'||matriz[fila][columna]=='4'||matriz[fila][columna]=='6'
        ||matriz[fila][columna]=='8'||matriz[fila][columna]=='A'||matriz[fila][columna]=='C'||matriz[fila][columna]=='E'){
          pipeType[totalLeaks].direction ='W';
          pipeType[totalLeaks].row =fila;
          pipeType[totalLeaks].column = columna;
          pipeType[totalLeaks].hex = pipe;
          totalLeaks++;
        }
        else{
          fakeLeak++;
        }
      }
    }
    if((pipe =='1'||pipe=='3'||pipe == '5'||pipe=='7'||pipe=='9'||pipe=='B'||pipe == 'D'||pipe == 'F')&&
    (matriz[fila][columna-1]=='1'||matriz[fila][columna-1]=='2'||matriz[fila][columna-1]=='3'
    ||matriz[fila][columna-1]=='8'||matriz[fila][columna-1]=='9'||matriz[fila][columna-1]=='A'
    ||matriz[fila][columna-1]=='B'||matriz[fila][columna-1]=='0'||matriz[fila][columna-1]==-1)){
      if(fakeLeak==0){
        pipeType[totalLeaks].direction = 'W';
        pipeType[totalLeaks].row = fila;
        pipeType[totalLeaks].column = columna;
        pipeType[totalLeaks].hex = pipe;
        totalLeaks++;
        //printf("%d %d %c",pipeType[totalLeaks].row,pipeType[totalLeaks].column,pipeType[totalLeaks].direction);
        returnBool = true;
      }
      fakeLeak=0;
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
  void findLeaks(struct Pipe *pipeType, struct Location *leakage){
    //reset total leaks in case
    totalLeaks =0;
    char focus;
    // mientras haya revisado todas las salidas y entradas
    // por toda la matriz
    for(int filaCounter =0; filaCounter<filas+2; filaCounter++){
      for(int columnaCounter=0; columnaCounter<columnas+2; columnaCounter++){
        // si hay una fuga y no es una salida ni hidrante
        if(!isLeaking(matriz[filaCounter][columnaCounter], filaCounter, columnaCounter, pipeType, leakage)){
          printf("No leaks detected!");
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
  /*
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
*/
void printLeaks(struct Pipe *pipeType){
  for(int counter3 =0; counter3<totalLeaks;counter3++){
    printf("leaks %d %d %c\n", pipeType[counter3].row, pipeType[counter3].column,pipeType[counter3].direction);
  }
  if (totalLeaks==0){
    printf("solved");
  }
}
