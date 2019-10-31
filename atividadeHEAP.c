/////////////////////////////////////////////////////////////////////////////////////
////////////////////JULIO CESAR BASILIO ALVES////////////////////////////////////////
/////////////////////////20180007631/////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////


#include <stdio.h>

//prototipos
void maxH(int*, int);
void buildmaxH(int*);
void heapSort(int*);
void troca(int*,int, int);
void print(int*);


////////////////////////////////////////////////////
//////                 MAIN                  ///////
////////////////////////////////////////////////////
int main(void){
    int tam=0;
    int aux=0;
    FILE * arq = fopen("couting.txt","r");//abre para leitura a instancia numerica usada como exemplo
    if(!arq) {
            puts("nao foi possivel trabalhar com o arquivo");
            fclose(arq);
            return 1;
    }
    fscanf(arq, "%d", &tam);//lê primeira linha do arquivo(que representa sua quantidade de elementos), e salva na variavel 'tam'
    int vetor[tam+1];//cria vetor de tamanho correto para armazenar dados(numeros inteiros) do arquivo
    vetor[0]=tam;//armazena o tamanho na primeira posição do vetor
    if(tam){
            while(aux<tam+1){//armazena demais valores no vetor criado
                    fscanf(arq, "%d", &vetor[aux+1]);
                    aux++;
            }
    } else printf("arquivo vazio");
    fclose(arq);
    print(vetor);//escreve na tela o vetor antes de ser aplicado o heapSort
    printf("\n");
    heapSort(vetor);
    print(vetor);//escreve na tela o vetor depois de ser aplicado o heapSort
    return 0;
}

////////////////////////////////////////
// funcao abaixo toma como verdade que os
// filhos do 'no' sao heaps maximos.
// e 'no' nao eh heap maximo.
// faz, por recorrencia, que o valor em 'no'
// desca a arvore
////////////////////////////////////////
void maxH(int *a, int no){
    int maior=0;
    int esquerdo = 2*no;
    int direito  = (2*no)+1;
    if((esquerdo <= a[0])&&(a[esquerdo]>a[no])){
        maior = esquerdo;
    } else {
        maior = no;
    }
    if((direito <= a[0])&&(a[direito]>a[maior])){
        maior = direito;
    }
    if(maior != no){
        troca(a, no, maior);
        maxH(a,maior);
    }
}

/////////////////////////////////
// funcao abaixo cria um heap maximo
// a partir de um vetor de inteiro
// qualquer dado
//////////////////////////////////
void buildmaxH(int * a){
    for(int i = a[0]/2 ; i > 0  ; i--)
        maxH(a,i);
}

////////////////////////////////////
// funcao abaixo ordena em ordem
// crescente de valores  um dado
// vetor qualquer de inteiros
/////////////////////////////////////
void heapSort(int* a){
    buildmaxH(a);
    int aux=a[0];
    for(int i = a[0] ; i>1 ; i--){
            troca(a,i,1);
            --a[0];
            maxH(a,1);
    }
    a[0]=aux;
}
//////////////////////////////////
// funcao abaixo troca de posicao
// os valores referentes as posicoes
// 'a' e 'b' do vetor 'vet' informado
//////////////////////////////////
void troca(int *vet, int a, int b){
        int aux = vet[a];
        vet[a] = vet[b];
        vet[b] = aux;


}

///////////////////////////////////////
// funcao abaixo escreve na tela o
// vetor 'a' informado.
/////////////////////////////////////
void print(int *a){
    int aux=0;
    while(aux<=100){
        printf("linha %d: %d\n",aux,a[aux]);
        aux++;
    }
}



