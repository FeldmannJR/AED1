#include <stdlib.h>
#include <stdio.h>


short** createMatrix(){
  short **ponts= calloc(5,sizeof(short*));
  for(int x =0 ;x<5;x++){
    ponts[x] = (short*)calloc(5,sizeof(short));
  }
  return ponts;
}

//Para ser mais facil de testar uso sempre a entrada do Teste.txt com o comando no bash: cat Teste.txt | ./Main
int main(){
  short **matrix = createMatrix();
  printf("Informe matriz 1\n");
  for(int x=0;x<5;x++){
    for(int y =0;y<5;y++){
       scanf("%hd",&matrix[x][y]);
    }
  }
  for(int x=0;x<5;x++){
    for(int y =0;y<5;y++){
        if(x<=y){
          short tmp = matrix[x][y];
          matrix[x][y] = matrix[y][x];
          matrix[y][x] = tmp;
          }
    }
  }
  for(int x =0;x<5;x++){
    for (int y =0;y<5;y++){
      printf("%hd ",matrix[x][y]);
    }
    printf("\n");
  }

}
