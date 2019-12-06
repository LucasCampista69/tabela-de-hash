#include "tadlistade.h"

typedef struct hashtable {

  int tam; /* tamanho do vetor de Plista */

  Plista *entradas; /* vetor de Plista */

} Thashtable, * Phashtable;

/*Construtora*/
Phashtable initHashTab(int tam);

/*destrutora*/
void destroyHashTab(Phashtable tab);

int hash(int mat,int tam);

void insHashTab(Phashtable tab,int mat,Paluno aluno);

void elimHashTab( Phashtable tab, int mat );

Paluno infoHashTab( Phashtable tab, int mat );
