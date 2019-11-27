#include "leak.c"

void findSolution (int leaksToFix, struct Pipe *pipeToChange){
  // while there are no more leaks
  while(totalLeaks>0){
    // for all the leaks i need to fix
    for (int counter =0; counter<leaksToFix; counter++){
      if (pipeToChange[counter].hex == '1' || pipeToChange[counter].hex ='2'||pipeToChange[counter].hex = '4'||pipeToChange[counter].hex = '8'){
    //    if(matriz[pipeToChange[counter].row][pipeToChange[counter].column]=='1'){
          matriz[pipeToChange[counter].row][pipeToChange[counter].column] = '1';
          findLeaks();
          //  matriz[]
          //findLeaks();
    //    }
      //  if(pipeToChange[counter].hex =='2'){
          matriz[pipeToChange[counter].row][pipeToChange[counter].column] = '4';
          findLeaks();
      //  }
      //if(pipeToChange[counter].hex =='4'){
          matriz[pipeToChange[counter].row][pipeToChange[counter].column] = '8';
          findLeaks();
        //}
      //  if(pipeToChange[counter].hex=='8'){
          matriz[pipeToChange[counter].row][pipeToChange[counter].column] = '2';
          findLeaks();
      //  }
      }
      if (pipeToChange[counter].hex == '3' || pipeToChange[counter].hex ='6'||pipeToChange[counter].hex = '9'||pipeToChange[counter].hex = 'C'){
        matriz[[pipeToChange[counter].row][pipeToChange[counter].column] ='3';
        findLeaks(pipeToChange, leakage);
        matriz[[pipeToChange[counter].row][pipeToChange[counter].column] ='6';
        findLeaks(pipeToChange, leakage);
        pipeToChange[counter].hex = 'C'

      }
      if (pipeToChange[counter].hex == '5' || pipeToChange[counter].hex ='A'){
        matriz[[pipeToChange[counter].row][pipeToChange[counter].column] ='5';
        findLeaks(pipeToChange, leakage);
        matriz[[pipeToChange[counter].row][pipeToChange[counter].column] ='A';
                findLeaks(pipeToChange, leakage);
      }
      if (pipeToChange[counter].hex == '7' || pipeToChange[counter].hex ='B'||pipeToChange[counter].hex = 'D'||pipeToChange[counter].hex = 'E'){
        matriz[[pipeToChange[counter].row][pipeToChange[counter].column] ='7';
        findLeaks(pipeToChange, leakage);
        matriz[[pipeToChange[counter].row][pipeToChange[counter].column] ='B';
                findLeaks(pipeToChange, leakage);
        matriz[[pipeToChange[counter].row][pipeToChange[counter].column] ='D';
                findLeaks(pipeToChange, leakage);
        matriz[[pipeToChange[counter].row][pipeToChange[counter].column] ='E';

        findLeaks(pipeToChange, leakage);
      }
      if (pipeToChange[counter].hex == '1' || pipeToChange[counter].hex ='2'||pipeToChange[counter].hex = '4'||pipeToChange[counter].hex = '8'){
          matriz[[pipeToChange[counter].row][pipeToChange[counter].column] ='1';
            findLeaks(pipeToChange, leakage);
            matriz[[pipeToChange[counter].row][pipeToChange[counter].column] ='2';
              findLeaks(pipeToChange, leakage);
              matriz[[pipeToChange[counter].row][pipeToChange[counter].column] ='4';
                findLeaks(pipeToChange, leakage);
                matriz[[pipeToChange[counter].row][pipeToChange[counter].column] ='8';
        findLeaks(pipeToChange, leakage);
      }

    }
  }
  printf("unsolvable");

}
}
