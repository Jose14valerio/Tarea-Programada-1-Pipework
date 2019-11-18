
#include "solution.c"
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
