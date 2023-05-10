#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
  int p;
  struct No *ptrAnterior;
  struct No *PtrPosterior;
} Noo;

typedef struct Cabecalho {
  int tamanho;
  Noo *primeiro;
  Noo *ultimo;
} Cabec;

// adiciona um elemento no ultimo lugar
void append(Cabec *cabec, int valor) {
  Noo *n = (Noo *)malloc(sizeof(Noo));
  n->ptrAnterior = NULL;
  n->PtrPosterior = NULL;
  n->p = valor;
  if (cabec->tamanho == 0) {
    cabec->primeiro = n;
    cabec->ultimo = n;
  } else {
    n->ptrAnterior = cabec->ultimo;
    n->p = valor;
    cabec->ultimo->PtrPosterior = n;
    cabec->ultimo = n;
    cabec->ultimo->PtrPosterior = NULL;
  }

  cabec->tamanho++;
}

// adiciona o elemento em uma posicao específica
void insert(Cabec *cabec, int posicao, int valor) {
  Noo *n = (Noo *)malloc(sizeof(Noo));
  n->PtrPosterior = NULL;
  n->ptrAnterior = NULL;
  n->p = valor;

  Noo *aux;
  Noo *aux2;
  Noo *aux3;

  aux = cabec->primeiro;
  if (posicao <= cabec->tamanho && posicao > 0) {
    for (int x = 1; x <= posicao; x++) {
      aux2 = aux;
      aux = aux->PtrPosterior;
    }

    if (aux2->PtrPosterior == NULL && aux2->ptrAnterior == NULL) {
      aux2->ptrAnterior = n;
      n->PtrPosterior = aux2;
      cabec->primeiro = n;
      cabec->ultimo = aux2;
      cabec->tamanho++;
    }

    else if (aux2->PtrPosterior == NULL) {

      aux3 = aux2->ptrAnterior;
      aux3->PtrPosterior = NULL;
      aux3->PtrPosterior = n;

      cabec->ultimo = NULL;
      cabec->ultimo = aux2;

      n->PtrPosterior = aux2;
      n->ptrAnterior = aux3;

      aux2->ptrAnterior = NULL;
      aux2->ptrAnterior = n;

      cabec->tamanho++;
    }

    else if (aux2->ptrAnterior == NULL) {

      cabec->primeiro = NULL;
      cabec->primeiro = n;

      aux2->ptrAnterior = n;
      aux2->PtrPosterior = aux;

      n->PtrPosterior = aux2;
      cabec->tamanho++;
    }

    else {

      // o anterior do que eu escolhi
      aux3 = aux2->ptrAnterior;
      // o ponteiro do anterior para o prox vira NULL
      aux3->PtrPosterior = NULL;
      // Atribuo o ponteiro de proximo para o novo noh que estou inserindo
      aux3->PtrPosterior = n;

      // aux, que é um a mais do noh que escolhi, tem seu ponteiro de anterior
      // setado para NULL
      aux->ptrAnterior = NULL;

      // seto ponteiro do prox e anterior do que escolhi em NULL
      aux2->ptrAnterior = NULL;
      aux2->PtrPosterior = NULL;

      aux->ptrAnterior = aux2;
      aux2->PtrPosterior = aux;
      aux2->ptrAnterior = n;

      n->PtrPosterior = aux2;
      n->ptrAnterior = aux3;
      cabec->tamanho++;
    }
  } else if (cabec->tamanho == 0) {
    append(cabec, valor);
  } 
  else {
    printf("Erro");
  }
}

int main(void) {

  // inicializa o cabecalho
  Cabec *estrutura = (Cabec *)malloc(sizeof(Cabec));
  // inicializa o tamanho de cabecalho como 0
  estrutura->tamanho = 0;

  //append(estrutura, 49);

  //insert(estrutura, 1, 254);
  insert(estrutura, 1, 11300);
  
  append(estrutura, 888);
 
  insert(estrutura, 2, 2600);
  append(estrutura, 9000);
  insert(estrutura, 1, 8200);
  
  printf("Primeiro:%d\n", estrutura->primeiro->p);
  printf("Ultimo:%d\n", estrutura->ultimo->p);

  printf("Tamanho: %d\n\n", estrutura->tamanho);

  while (estrutura->primeiro) {
    printf("%d\n", estrutura->primeiro->p);
    estrutura->primeiro = estrutura->primeiro->PtrPosterior;
  }

  return 0;
}