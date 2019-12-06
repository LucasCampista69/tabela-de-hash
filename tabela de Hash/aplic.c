#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadlistade.h"

int main(int argc, char **argv)
{
	Plista lst1=NULL;
	Plista lstarq;
	FILE *arqin,*arqout;

	Paluno aluno = init_aluno();
	strcpy(aluno->nome,"Assassin");
	aluno->matricula=201720360;
	aluno->turma = 'b';
	strcpy(aluno->email,"gasparzinho_sumiu@ifes.edu.br");

	lst1 = init_lst();
    arqin = fopen("arqin.txt","r");
    lst1 = load_lst(arqin);
    print_lst(lst1);

	if(in_lst(lst1,201927634) == 1){
	  printf("\noh yes");
	}else{
	  printf("\noh no");
	}
	insert_lst(lst1,0,aluno);
	printf("\nPrintando com o novo elemento inserido");
	print_lst(lst1);
	printf("\nPrintando a lista invertida");
	print_reverse_lst(lst1);
	del_ult_lst(lst1);
	printf("\nPrintando a lista com o ultimo no eliminado");
	print_lst(lst1);
	
	Paluno aluno1 = init_aluno();
	strcpy(aluno1->nome,"jorgim");
	aluno1->matricula=201720500;
	aluno1->turma = 'a';
	strcpy(aluno1->email,"yoaluon@ifes.edu.br");
	insert_lst(lst1,0,aluno1);
	
	Paluno aluno2 = init_aluno();
	strcpy(aluno2->nome,"bobo");
	aluno2->matricula=201720666;
	aluno2->turma = 'c';
	strcpy(aluno2->email,"sumiu@ufes.edu.br");
	insert_lst(lst1,0,aluno2);
	
	printf("\nPrintando com os novos elementos inseridos");
	print_lst(lst1);
	
	printf("\napagando o no da posicao 2 da lista");
	del_pos_lst(lst1, 2);
	print_lst(lst1);
	printf("\nobter a posiçao do aluno 201720500 ");
	printf("\n%i",index_lst(lst1,201720500));
	printf("\nobter o aluno na posicao 2");
	printf("\n%i",get_pos_lst(lst1, 2));
 }