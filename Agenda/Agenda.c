#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tamanho de alocação de uma string
#define tamanhoString 32
//0 = Numero de entries, 1,2,3 = Ints para usar em leituras/for
#define ints 4
// Uma string para usar em leituras
#define strings 1
#define start ((sizeof(int)*ints)+(strings*tamanhoString))

//Está pré entendido que o maximo de leitura é tamanhoString caracteres

typedef struct Pessoa{
    char nome[tamanhoString];
    int numero;
}pessoa;


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
int* getThirdInt(){
    return &pBuffer[sizeof(int)*3];
}

int* getQtdPessoas(){
    return &pBuffer[0];
}
pessoa* getPessoa(int *index){
  return &pBuffer[start+((*index)*sizeof(pessoa))];
}

void printHelp(){
    printf("Available commands: add | remove | list | search | exit\n");
}
int nomeExiste(char* nome){
    int *x = getFirstInt();
    for((*x) = 0;(*x)<(*getQtdPessoas());(*x)++){
      if(strcmp(nome,getPessoa(x)->nome)==0){
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
    getchar();
    for((*x) = 0;(*x)<(*getQtdPessoas());(*x)++){
        pessoa *p = getPessoa(x);
        if(strstr(p->nome,getFirstString())!=NULL){
            (*getSecondInt())++;
            printf("%d - %s : %d\n",*getSecondInt(),p->nome,p->numero);
        }
    }
    printf("%d found!\n",*getSecondInt());
    return 0;

}

void addPessoa(){
    pBuffer = realloc(pBuffer,start+(((*getQtdPessoas()) + 1) * sizeof(pessoa)));
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

    pessoa *p = getPessoa(getQtdPessoas());
    p->numero = *getFirstInt();
    strcpy(p->nome,getFirstString());
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
        pessoa *p = getPessoa(x);
        if((*getFirstInt())==1){
            *getThirdInt() = (*x)-1;
            pessoa *p1 = getPessoa(getThirdInt());
            p1->numero = p->numero;
            strcpy(p1->nome,p->nome);
        }else if(strcmp(p->nome,getFirstString())==0){
            *getFirstInt() = 1;
        }
    }
    if((*getFirstInt())==1){
        printf("Entry deleted!\n");
        (*getQtdPessoas())--;
        pBuffer = realloc(pBuffer,start+((*getQtdPessoas()) * sizeof(pessoa)));
    }else{
        printf("Name not found!\n");
    }
}

void list(){
    int *x = getFirstInt();
    printf("%d entries.\n",*getQtdPessoas());
    for((*x) = 0;(*x)<(*getQtdPessoas());(*x)++){
        pessoa *p = getPessoa(x);
        printf("%d - %s : %d\n",(*x)+1,p->nome,p->numero);
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
