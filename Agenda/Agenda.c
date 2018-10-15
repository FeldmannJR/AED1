#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//Preprocessor min function para não usar variaveis
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

//Tamanho de alocação de uma string
#define tamanhoString 32
//Está pré entendido que o maximo de leitura é tamanhoString caracteres

//Structs
typedef struct Pessoa{
    char nome[tamanhoString];
    int numero;
}pessoa;

typedef struct Vars{
    //Salva quantos entries tem na agenda
    int qtd;
    //Usados em funções
    int x;
    int y;
    int z;
    int a;
    int b;
    int c;
    pessoa temp;
    char str[tamanhoString];
    //Variaveis para comparação
    int i;
    int j;
}vars;

//Header das funções
int nameGreaterThen(char* n1,char *n2);
void copy(pessoa*,pessoa*);
void sort();
void insertSort();
void selectSort();
void bubbleSort();
int personGreaterThen(int p1,int p2);

//Variaveis
void *pBuffer;
vars *v;

pessoa* getPessoa(int *index){
  return &pBuffer[sizeof(vars)+((*index)*sizeof(pessoa))];
}

int nomeExiste(char* nome){
    for(v->x = 0; v->x < v->qtd; v->x++){
      if(strcmp(nome,getPessoa(&v->x)->nome)==0){
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
        pessoa *p = getPessoa(&v->x);
        if(strstr(p->nome,v->str)!=NULL){
            v->y++;
            printf("%d - %s : %d\n",v->y,p->nome,p->numero);
        }
    }
    printf("%d found!\n",v->y);
    return 0;

}

void addPessoa(){
    pBuffer = realloc(pBuffer,sizeof(vars)+((v->qtd + 1) * (sizeof(pessoa))));
    v = &pBuffer[0];
    printf("Enter entry name:\n");
    scanf("%[^\n]s",v->str);
    getchar();
    if(nomeExiste(v->str)){
        printf("Already have this name.\n");
        return;
    }
    printf("Enter entry number:\n");
    scanf("%d",&v->x);
    getchar();

    pessoa *p = getPessoa(&v->qtd);
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
            pessoa *p1 = getPessoa(&v->z);
            p1->numero = p->numero;
            strcpy(p1->nome,p->nome);
        }else if(strcmp(p->nome,v->str)==0){
            v->y = 1;
        }
    }
    if(v->y==1){
        printf("Entry deleted!\n");
        v->qtd--;
        pBuffer = realloc(pBuffer,sizeof(vars)+(v->qtd * (sizeof(pessoa))));
        v = &pBuffer[0];
    }else{
        printf("Name not found!\n");
    }
}

void list(){
    printf("%d entries.\n",v->qtd);
    for(v->x = 0;v->x<v->qtd;v->x++){
        pessoa *p = getPessoa(&v->x);
        printf("%d - %s : %d\n",v->x+1,p->nome,p->numero);
    }
}

void printHelp(){
    printf("Available commands: add | remove | list | search | sort | exit\n");
}

int main(){
    pBuffer = malloc(sizeof(vars));
    srand(time(NULL));
    v = &pBuffer[0];
    v->qtd = 0;
    printHelp();
    while(1){
        printf("Enter menu option:\n");
        scanf("%s",v->str);
        getchar();
        if(strcmp(v->str,"add")==0){
            addPessoa();
        }else if(strcmp(v->str,"remove")==0){
            removePessoa();
        }else if(strcmp(v->str,"list")==0){
            list();
        }else if(strcmp(v->str,"search")==0){
            search();
        }else if(strcmp(v->str,"sort")==0){
            sort();
        }else if(strcmp(v->str,"exit")==0){
            printf("Exiting...\n");
            break;
        }else{
            printf("Command not found!\n");
            printHelp();
        }
    }
}


void copy(pessoa *dest, pessoa *src){
    strcpy(dest->nome,src->nome);
    dest->numero = src->numero;
}

void troca(int pos1,int pos2){
    v->temp = *getPessoa(&pos1);
    copy(getPessoa(&pos1),getPessoa(&pos2));
    copy(getPessoa(&pos2),&v->temp);
}


//Sort functions
void sort(){
    printf("Sort algorithm : insert | select | bubble | quick\n");
    scanf("%s",v->str);
    getchar();
    if(strcmp(v->str,"insert")==0){
        insertSort();
    }else if(strcmp(v->str,"select")==0){
        selectSort();
    }else if(strcmp(v->str,"bubble")==0){
        bubbleSort();
    }else if(strcmp(v->str,"quick")==0){
        quickSort(0,v->qtd-1);
    }
    else{
        printf("Option not found using insert!\n");
        insertSort();
    }
}

/* Satan me ajuda aqui
void startMergeSort(){
    pBuffer = realloc(sizeof(vars)+sizeof(pessoa)*(v->qtd)*2);
    v = &pBuffer[0];
    for(v->x = 0;v->x < v->qtd;v->x++){
        pessoa *n = (pessoa*)&pBuffer[(sizeof(vars)+sizeof(pessoa)*(v->qtd + v->x)];
        copy(n,getPessoa(v->x));
    }
    mergeSort();
    pBuffer = realloc(sizeof(vars)+sizeof(pessoa)*(v->qtd));
    v = pBuffer;
}

void mergeSort(int l, int r){
    if(l < r){
        v->a = (l+r)/2;
        sort(l,v->a);
        sort(v->a+1,r);

        merge(l,m,r);
    }
}
void merge(int l,int m,int l){
    v->b = m - l + 1;
    v->c = r -m;
    v->x = 0;
    v->y = 0;
    v->z = l;
    while(v->x < v->b && v->y < v->c){
      //   pBuffer = realloc(sizeof(vars)+sizeof(pessoa)*(v->qtd + ));
    }

}
*/

/*
    Quick sort
    Recursão
    Ele quebra uma lista em duas listas menores aleatoriamente

*/
void quickSort(int start,int end){
    if(end-start <=1)return;
    //Pegando o pivo aleatoriamente
    v->c = rand()%(end-start);
    //A é a esquerda
    v->a = start;
    //B é a direita
    v->b = end;
    do{
        //se o pivot é maior que o da esquerda, empurra pra esquerda
        while(personGreaterThen(v->c,v->a)){
            v->a++;
        }
        //Caso o pivot seja menor que o da direita, diminui a lista
        while(personGreaterThen(v->b,v->c)){
            v->b--;
        }
        //Se o da esquerda for maior que o da direita
        if(v->a <= v->b){
            //Troca
            troca(v->a,v->b);

            v->a++;
            v->b--;
        }
    //Enquanto a esquerda for menor que a direita
    }while(v->a <= v->b);

    if(start < v->b){
        quickSort(start,v->b);
    }
    if(v->a < end){
        quickSort(v->a,end);
    }

}
//Por elemento ele verifica se o da direito é menor que o atual, se for troca, ele percorre n^2 vezes
void bubbleSort(){
    //Percorrendo todos elementos
    for(v->x=0;v->x<v->qtd-1;v->x++){
        //Percorrendo todos elementos menos até onde não foi ordenado
        for(v->y = 0;v->y < v->qtd-v->x-1;v->y++){
            v->z = v->y+1;
            //Verificando se o nome do atual é maior que o proximo
            if(nameGreaterThen(getPessoa(&v->y)->nome,getPessoa(&v->z)->nome)){
                //se for ele troca de lugar eles
                troca(v->y,v->z);
            }
        }
    }
}

//Insert sort = Por elemento ele verifica cada elemento a esquerda dele, até achar um menor, se achar um menor ele bota na frente dele, se n achar menor bota no primeiro slot
void insertSort(){
    //Percorre todos os elementos começando pelo SEGUNDO
    for(v->x=1;v->x<v->qtd;v->x++){
        //Pega o elemento anterior
        v->y = v->x-1;
        //Pega o elemento atual em forma do contato
        v->temp = *getPessoa(&v->x);
        //Enquanto ele achar um numero maior a esquerda ele copia ele para direita
        while(v->y >= 0 && (nameGreaterThen(getPessoa(&v->y)->nome,v->temp.nome))){
            v->z = v->y+1;
            //Troca lugar o lugar dos dois
            copy(getPessoa(&v->z),getPessoa(&v->y));
            //Vai mais pra esquerda
            v->y--;
        }
        //O ultimo da esquerda ele copia o valor inicial
        v->z = v->y+1;
        copy(getPessoa(&v->z),&v->temp);
    }
}
//Percorre cada elemento, achando o minimo na frente dele, ao achar troca o valor do minimo com o atual
void selectSort(){
    //Percorrendo todas as pessoas
    for(v->x =0;v->x<v->qtd;v->x++){
        //Achando o minimo, apartir da pessoa atual
        v->y = v->x;
        for(v->z = v->x+1;v->z < v->qtd;v->z++){
            if(nameGreaterThen(getPessoa(&v->y)->nome,getPessoa(&v->z)->nome)){
                v->y = v->z;
            }
        }
        //Troca a pessoa atual pelo minimo
        troca(v->x,v->y);
    }
}

int personGreaterThen(int p1,int p2){
    return nameGreaterThen(getPessoa(&p1)->nome,getPessoa(&p2)->nome);
}
//Function to compare strings and return 1 if n1 is grater then n2
int nameGreaterThen(char* n1,char *n2){
    v->j = MIN(strlen(n1),strlen(n2));
    for(v->i = 0;v->i < v->j;v->i++){
        if(n1[v->i]>n2[v->i]){
            return 1;
        }else if(n1[v->i] < n2[v->i]){
            return 0;
        }
    }
    if(strlen(n1)>strlen(n2)){
        return 1;
    }
    return 0;
}
