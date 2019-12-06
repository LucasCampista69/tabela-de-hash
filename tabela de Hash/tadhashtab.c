#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tadhashtab.h"

Phashtable initHashTab(int tam){
	int h;
  Phashtable tab = (Phashtable) malloc(sizeof(Thashtable));
  tab->entradas = (Plista*)malloc(tam * sizeof(Tlista));
  tab->tam = tam; 
	if(tab != NULL){
		for(h=0;h<tam;h++){
			tab->entradas[h] = init_lst();
		}
	}else{
		printf("Erro de alocação");
	}
	return tab;
}
int hash(int mat,int tam){
	return mat % tam;
}
void insHashTab(Phashtable tab,int mat,Paluno aluno){
	int h;
	Plista lst;
	h = hash(mat,tab->tam);
  printf("%d",h);
	if(tab->entradas[h]->tam > 0){
    //insert_lst(tab->entradas[h], 0, aluno);
		insOrdLst(tab->entradas[h],aluno);
	}else{
		lst = init_lst();
		append_lst(lst,aluno);
		tab->entradas[h] = lst;    
	}
}
void elimHashTab( Phashtable tab, int mat ){
	if (tab->tam > 0){
		int h = hash(mat,tab->tam);
		if(tab->entradas[h] != NULL){
			del_info_lst(tab->entradas[h],mat);
		}
	}
}
Paluno infoHashTab( Phashtable tab, int mat ){
	if (tab->tam > 0){		
		int h = hash(mat,tab->tam);
		Paluno aluno = init_aluno();
    Plista lst = tab->entradas[h] ;
		if(tab->entradas[h] != NULL){
			if(in_lst(tab->entradas[h],mat)== 1){
        if(mat ==tab->entradas[h]->prim->info->matricula ){
          return tab->entradas[h]->prim->info;
        }else{
          if(tab->entradas[h]->tam % 2 == 0){
            del_pos_lst(lst,0);
          }
				  aluno = buscaBinLst(lst,mat);
          printf("\n%s",aluno->nome);
        }
				return aluno;
			}else{
				printf("Matricula inexistente");
				
			}
		}
	}
	return NULL;
}
int estanaHashTab(Phashtable tab, int mat){}

