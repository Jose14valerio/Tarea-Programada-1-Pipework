#include <stdio.h>
//
int generalInfo[4];

struct Location{
  int row;
  int column;
  char cardinal;
};
validateLevel();


char* validateLevel(){

  char removeSpace;
  counter = 0;
  dimensionCounter = 0;
  while(counter!=4){
    scanf("%d",generalInfo[counter]);
    counter++;
  }
  //remove a line
  scanf("%*c");
  struct Location where[generalInfo[4]+generalInfo[3]];

  while (dimensionCounter<generalInfo[4]+generalInfo[3]){
    scanf("%d %d %c",where[dimensionCounter].row,where[dimensionCounter].column,where[dimensionCounter].cardinal);
  }
  char matriz[generalInfo[3]][generalInfo[4]];

  return matriz;
}
int main(){
validatLevel();
}
