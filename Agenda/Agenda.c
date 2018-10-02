#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tamanho de alocação de uma string
#define tamanhoString 32


//Está pré entendido que o maximo de leitura é tamanhoString caracteres

typedef struct Pessoa{
    char nome[tamanhoString];
    int numero;
}pessoa;

typedef struct Vars{
    int qtd;
    int x;
    int y;
    int z;
    int tmp;
    char str[tamanhoString];
}vars;


void *pBuffer;
vars *v;

pessoa* getPessoa(int *index){
  return &pBuffer[sizeof(vars)+((*index)*sizeof(pessoa))];
}
//SORT

void insertSort(){
    for((*x)=1;(*x)<(*getQtdPessoas());(*x)++){
        *y = (*x)-1;
        while()
    }
}

int nameGreaterThen(char* n1,char *n2){


}


void printHelp(){
    printf("Available commands: add | remove | list | search | exit\n");
}
int nomeExiste(char* nome){
    for(v->x = 0; v->x < v->qtd; v->x++){
      if(strcmp(nome,getPessoa(x)->nome)==0){
        return 1;
      }
    }
    return 0;
}

void search(){
    printf("Name to search:\n");
    scanf("%[^\n]s",v->str);
    getchar();
    v->y = 0;
    for(v->x = 0; v->x < v->qtd; v->x++){
        pessoa *p = getPessoa(x);
        if(strstr(p->nome,v->str)=NULL){
            v->y++;
            printf("%d - %s : %d\n",v->y,p->nome,p->numero);
        }
    }
    printf("%d found!\n",v->y);
    return 0;

}

void addPessoa(){
    pBuffer = realloc(pBuffer,sizeof(vars)+(((*getQtdPessoas()) + 1) * sizeof(pessoa)));
    v = &pBuffer[0];
    printf("Enter entry name:\n");
    scanf("%[^\n]s",v->str);
    getchar();
    if(nomeExiste(v->str)){
        printf("Already have this name.\n");
        return;
    }
    printf("Enter entry number:\n");
    scanf("%d",v->x);
    getchar();

    pessoa *p = getPessoa(getQtdPessoas());
    p->numero = v->x;
    strcpy(p->nome,v->str);
    v->qtd++;
    printf("Added number!\n");
}

void removePessoa(){
    printf("Enter name to remove:\n");
    scanf("%[^\n]s",v->str);
    getchar();
    v->y = 0;
    for(v->x = 0;v->x < v->qtd; v->x++){
        pessoa *p = getPessoa(&v->x);
        if(v->y==1){
            v->z = v->x-1;
            pessoa *p1 = getPessoa(v->z);
            p1->numero = p->numero;
            strcpy(p1->nome,p->nome);
        }else if(strcmp(p->nome,v->str)==0){
            v->y = 1;
        }
    }
    if(v->y==1){
        printf("Entry deleted!\n");
        v->qtd--;
        pBuffer = realloc(pBuffer,start+((*getQtdPessoas()) * sizeof(pessoa)));
        v = &pBuffer[0];
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
    v = &pBuffer[0];
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
