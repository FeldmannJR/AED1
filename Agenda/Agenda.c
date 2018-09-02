#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tamanho de alocação de uma string
#define tamanhoString 32
//0 = Numero de entries, 1,2 = Ints para usar em leituras/for
#define ints 3
// Uma string para usar em leituras
#define strings 1
#define start ((sizeof(int)*ints)+(strings*tamanhoString))
//Tamanho por entry na agenda
#define per (sizeof(int)+tamanhoString)

//Está pré entendido que o maximo de leitura é tamanhoString caracteres


void *pBuffer;

char* getFirstString(){
    return &pBuffer[ints*sizeof(int)];
}

int* getFirstInt(){
    return &pBuffer[sizeof(int)];
}
int* getSecondInt(){
    return &pBuffer[sizeof(int)*2];
}

int* getQtdPessoas(){
    return &pBuffer[0];
}

void printHelp(){
    printf("Available commands: add | remove | list | search | exit\n");
}
int nomeExiste(char* nome){
    int *x = getFirstInt();
    for((*x) = 0;(*x)<(*getQtdPessoas());(*x)++){
      if(strcmp(nome,&pBuffer[start+((*x)*per)+sizeof(int)])==0){
        return 1;
      }
    }
    return 0;
}

void search(){
    int *x = getFirstInt();
    *getSecondInt() = 0;
    printf("Name to search:\n");
    scanf("%[^\n]s",getFirstString());
    for((*x) = 0;(*x)<(*getQtdPessoas());(*x)++){
        char *nome = &pBuffer[start+((*x)*per)+sizeof(int)];
        int *numero = &pBuffer[start+((*x)*per)];
        //Checa se a strign de entrada esta contida no nome do contato
        if(strstr(nome,getFirstString())!=NULL){
            (*getSecondInt())++;
            printf("%d - %s : %d\n",*getSecondInt(),nome,*numero);
        }
    }
    printf("%d found!\n",*getSecondInt());
    return 0;

}

void addPessoa(){
    pBuffer = realloc(pBuffer,start+(((*getQtdPessoas()) + 1) * per));
    printf("Enter entry name:\n");
    scanf("%[^\n]s",getFirstString());
    getchar();
    if(nomeExiste(getFirstString())){
        printf("Already have this name.\n");
        return;
    }
    printf("Enter entry number:\n");
    scanf("%d",getFirstInt());
    getchar();
    int *number = &pBuffer[start+(*getQtdPessoas() * per)];
    *number = *getFirstInt();
    char *name = &pBuffer[start+(*getQtdPessoas() * per) +sizeof(int)];
    strcpy(name,getFirstString());
    (*getQtdPessoas())++;
    printf("Added number!\n");
}

void removePessoa(){
    int *x = getSecondInt();
    printf("Enter name to remove:\n");
    scanf("%[^\n]s",getFirstString());
    getchar();
    *getFirstInt() = 0;
    for((*x) = 0;(*x)<(*getQtdPessoas());(*x)++){
        char *nome = &pBuffer[start+((*x)*per)+sizeof(int)];
        int *numero = &pBuffer[start+((*x)*per)];

        if((*getFirstInt())==1){
            int *newnumero = &pBuffer[start+(((*x)-1)*per)];
            *newnumero = *numero;
            strcpy(&pBuffer[start+(((*x)-1)*per)+sizeof(int)],nome);
        }else if(strcmp(nome,getFirstString())==0){
            *getFirstInt() = 1;
        }
    }
    if((*getFirstInt())==1){
        printf("Entry deleted!\n");
        (*getQtdPessoas())--;
        pBuffer = realloc(pBuffer,start+((*getQtdPessoas()) * per));
    }else{
        printf("Name not found!\n");
    }
}

void list(){
    int *x = getFirstInt();
    printf("%d entries.\n",*getQtdPessoas());
    for((*x) = 0;(*x)<(*getQtdPessoas());(*x)++){
        int *numero = &pBuffer[start+((*x)*per)];
        char *nome = &pBuffer[start+((*x)*per)+sizeof(int)];
        printf("%d - %s : %d\n",(*x)+1,nome,*numero);
    }
}

int main(){
    pBuffer = malloc(start);
    *getQtdPessoas() = 0;
    printHelp();
    while(1){
        printf("Enter menu option:\n");
        scanf("%s",getFirstString());
        getchar();
        if(strcmp(getFirstString(),"add")==0){
            addPessoa();
        }else if(strcmp(getFirstString(),"remove")==0){
            removePessoa();
        }else if(strcmp(getFirstString(),"list")==0){
            list();
        }else if(strcmp(getFirstString(),"search")==0){
            search();
        }else if(strcmp(getFirstString(),"exit")==0){
            printf("Exiting...\n");
            break;
        }else{
            printf("Command not found!\n");
            printHelp();
        }

    }
}
