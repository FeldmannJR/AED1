#include <stdio.h>
#include <stdlib.h>

char* getVetor(){
    return (char*) realloc(NULL,sizeof(char)*17);
}

int main(){
  unsigned short leitura = 0;
  printf("Digite um numero para converter(0-65535): \n");
  char* vetor = getVetor();
  scanf("%hu",&leitura);
  unsigned short num = leitura;
  char* finalV = vetor+16;
  *finalV = '\0';
  finalV--;
  while(num>0){
    unsigned short resto = num%2;
    num/=2;
    if(resto){
        *finalV = '1';
    }else{
        *finalV = '0';
    }
    finalV--;
  }
  while(finalV>=vetor){
    *finalV ='0';
    finalV--;
  }
  printf("%s\n",vetor);

}
