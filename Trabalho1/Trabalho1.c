#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Carlos André Feldmann Júnior - 17200107

#define tamanhoString 20
#define startSize (sizeof(int)+tamanhoString)

void *pBuffer;

int* getQtdNomes(){
    return (int*) &pBuffer[0];
}
char* getTmpString(){
	return (char*)&pBuffer[sizeof(int)];
}

void addNome(){
	(*getQtdNomes())++;
	pBuffer = realloc(pBuffer,startSize+((*getQtdNomes())*tamanhoString));
	char *pointer = &pBuffer[startSize+(((*getQtdNomes())-1)*tamanhoString)];
	strcpy(pointer,getTmpString());
}
	
int main(){
    pBuffer = malloc(startSize);
	*getQtdNomes() = 0;
	while(1){
		//Precisa setar a string vazia, pois ao dar enter sem nenhuma entrada ele continua com a entrada antiga
		strcpy(getTmpString(),"");
		printf("Insira um nome: ");	
		scanf("%[^\n]s",getTmpString());
		getchar();
		if(strcmp("",getTmpString())==0){
			break;
		}
		//Não precisa passar argumento nenhum pq o a função sabe o endereço que está o nome
		addNome();
	}
	//Imprimindo os nomes em ordem inversa para não precisar usar + um int
	if(*getQtdNomes()==0){
		printf("Nenhum nome inserido!");
		return;
	}
	printf("Foram inseridos %d nomes:\n",*getQtdNomes());
	//-- Pra começar no ultimo elemento
	(*getQtdNomes())--;
	for(;(*getQtdNomes())>=0;(*getQtdNomes())--){
		char *nome = &pBuffer[startSize+((*getQtdNomes())*tamanhoString)];
		printf("%d - %s\n",*getQtdNomes(),nome);
	}
}

