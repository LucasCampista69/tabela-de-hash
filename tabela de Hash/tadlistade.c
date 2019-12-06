
#include <stdlib.h>
#include <stdio.h>
#include "tadlistade.h"

Plista init_lst(void){
    Plista lista = (Plista)malloc(sizeof(Tlista));
	if(lista == NULL){
		printf("Erro de alocação");
	}else{
		lista->prim = NULL;
		lista->ulti = NULL;
		lista->tam = 0;
		
	}
  return lista;
}
Paluno init_aluno(void){
	Paluno aluno = (Paluno)malloc(sizeof(Taluno));
	if(aluno == NULL){
		printf("Erro de alocaçao");
	}
	return aluno;
	
}

int len_lst(Plista lst){
    return lst->tam;
}

int in_lst(Plista lst, int elem){
    if (lst != NULL){
        if (empty_lst(lst) == 1){
            return 0;
        }else{
            Pno no = lst->prim;
            while (no != NULL){
                if (elem == no->info->matricula){
                    return 1;
                }else{
                    no = no->prox;
                }
            }

            return 0;
        }
    }
    else
    {
        return 0;
    }
}
int empty_lst(Plista lst){
	if (lst!= NULL){
		if(lst->tam == 0){
			return 1;
		}else{
			return 0;
		}
	}
  return 0;
}
void print_lst(Plista lst){
	printf("\n");
	if(lst != NULL){
		Pno aux = lst->prim;
		while (aux != NULL){
			printf("\nmatricula %i   ", aux->info->matricula);
			printf("\nnome %s   ", aux->info->nome);
			printf("\nturma %c   ", aux->info->turma);
			printf("\nemail %s   ", aux->info->email);
			printf("\n");
			aux = aux->prox;
		}
	}
}
void print_reverse_lst(Plista lst){
	printf("\n");
	if(lst != NULL){
		Pno aux = lst->ulti;
		while (aux != NULL){
			printf("\nmatricula %i   ", aux->info->matricula);
			printf("\nnome %s   ", aux->info->nome);
			printf("\nturma %c   ", aux->info->turma);
			printf("\nemail %s   ", aux->info->email);
			printf("\n");
			aux = aux->ante;
		}
	}
}
void append_lst(Plista lst, Paluno elem){
    if (lst != NULL){
        Pno novo = (Pno)malloc(sizeof(Tno));		
		if (novo == NULL){
			printf("Erro de alocação");
		}else{
			novo->ante = NULL;
			novo->prox = NULL;
			novo->info = elem;
			if (lst->tam != 0){
				Pno aux = lst->ulti;
				lst->ulti = novo;
				aux->prox = novo;
				novo->ante = aux;
				lst->tam += 1;
			}else{
				lst->ulti = novo;
				lst->prim = novo;
				lst->tam = 1;
			}
		}
    }
}
void insert_lst(Plista lst, int pos, Paluno elem){
    if (lst != NULL){
        Pno novo = (Pno)malloc(sizeof(Tno));
		Pno aux = lst->prim;
		if(novo == NULL){
			printf("Erro de alocação");
		}else{
			novo->ante = NULL;
			novo->prox = NULL;
			novo->info = elem;
			if (pos <= 0){
				lst->prim = novo;
				novo->prox = aux;
				aux->ante = novo;
				lst->tam += 1;
			}else if (pos >= lst->tam){
				Pno aux = lst->ulti;
				lst->ulti = novo;
				novo->ante = aux;
				aux->prox = novo;
				lst->tam += 1;
			}else{
				for (int i = 0; i < lst->tam; i++){
					if (i == pos){
						novo->ante = aux->ante;
						novo->prox = aux;
						aux->ante->prox = novo;
						aux->ante = novo;
						lst->tam += 1;
						i = lst->tam;
					}else{
						aux = aux->prox;
					}
				}
			}
		}
    }
}
void del_ult_lst(Plista lst)
{
    Pno aux = lst->ulti;
    aux->ante->prox = NULL;
    lst->ulti = aux->ante;
	lst->tam -= 1;
    free(aux);
}
void del_lst(Plista lst){
	Pno aux = lst->prim;
	if(lst != NULL){
		if(lst->tam == 1){
			free(lst->prim);
			free(lst);
		
		}else{
			
			while(aux!=NULL){
				lst->prim = aux->prox;
				free(aux);
				aux = lst->prim;
			}
			free(lst);
		}
	}
}
void del_pos_lst(Plista lst, int pos){ 
	if(lst != NULL){
		int i = 0;
		Pno aux = lst->prim;
		if ((lst != NULL) && (lst->tam > 0)){
			if (lst->tam == 1){
				free(lst->prim);
				lst->prim = NULL;
				lst->ulti = NULL;
				lst->tam = 0;
			}else{
				if (pos == lst->tam - 1){
					del_ult_lst(lst);
				}else if (pos == 0){
					lst->prim = aux->prox;
					lst->prim->ante = NULL;
					free(aux);
					lst->tam -= 1;
				}else{
					while (i <= pos){
						if (i == pos){
							aux->ante->prox = aux->prox;
							aux->prox->ante = aux->ante;
							free(aux);
							lst->tam -= 1;
							i++;
						}else{
							i ++;
							aux = aux->prox;
						}
					}
				}
			}
		}
	}
}
void del_info_lst(Plista lst, int info){
	if(lst == NULL){
		printf("lista vazia");
	}else{
		Pno aux = lst->prim;
		int find = 0;
		while((aux !=NULL)&&(find != 1)){
			if(aux->info->matricula == info){
				aux->info = NULL;
				find = 1;
			}else{
				aux = aux->prox;
			}
		}
	}
}
Plista load_lst(FILE *arq){

	Plista lista = init_lst();
	Paluno aluno;
	int tam;
	fscanf(arq,"%i",&tam);	
	if (!feof(arq)){
		aluno = init_aluno();
		fscanf(arq,"%i",&aluno->matricula);
		while(!feof(arq)){
					
				fscanf(arq,"%s\n",aluno->nome);        
				fscanf(arq,"%c",&aluno->turma);
				fscanf(arq,"%s",aluno->email);			
				append_lst(lista, aluno);
				aluno = init_aluno();
				fscanf(arq,"%i",&aluno->matricula);
			}
    printf("\n");
		return lista;
	}else{
		printf("Arquivo vazio");
	}
return NULL;	
}
/*void save_lst(Plista lst,FILE *arq){
	if (lst != NULL){
		if(lst->tam > 0){
			Pno aux = lst->prim;
			while(aux !=NULL){
				fprintf(arq,"%.2lf\n",aux->info);
				aux = aux->prox;
			}
		}
	}
}*/
int index_lst(Plista lst, int elem){
	if (lst != NULL){
		int c = 0;
		Pno aux = lst->prim;
		if(lst->tam > 0){			
			while (aux){	
				if(aux->info->matricula == elem){
					return c;
				}else{
					c++;
					aux = aux->prox;
				}
			}
		}
	}
  return -1;
}
int get_pos_lst(Plista lst, int pos){
	if(lst != NULL){
		Pno aux = lst->prim;
		int c = 0;
		if((pos > lst->tam-1) ||(pos < 0)){
			return 0;
		}
		if(lst->tam > 0){
			while(aux){
				if(pos == c){
					return aux->info->matricula;
				}else{
					aux = aux->prox;
					c++;
				}
			}
		}
	}
  return 0;
}
void insOrdLst(Plista lst,Paluno aluno){
  
	if (lst != NULL){
		Pno aux = lst->prim;
		int i = 0;
		while((aux != NULL)&&(i >= 0)){
      
			if(aux->info->matricula >= aluno->matricula){
				insert_lst(lst,i,aluno);
				i = -1;
			}else{
				aux = aux->prox;
				i++;
			}
		}
	}
}
Paluno buscaBinLst(Plista lista,int info){
	Pno aux = lista->prim;
  int pos,i; 
	pos = lista->tam / 2;
  for(i = 0;i<pos;i++){
			if(i != pos){        
				aux = aux->prox;
			}
	}	
	if(lista != NULL){
		if(lista->tam == 1){
			if(info == aux->info->matricula){
        printf("\n%d",aux->info->matricula);
				return aux->info;
			}else{
				printf("\nNão encontrado");
				return NULL;
			}
		}else{
      //printf("%d",aux->info->matricula);
      lista->tam -= pos + 1;
			if(info == aux->info->matricula){
				return aux->info;
			}else if(info < aux->info->matricula){
        //printf("%d",aux->info->matricula);
				aux->ante->prox = NULL;
				lista->ulti = aux->ante;
        buscaBinLst(lista,info);  
			}else{
				aux->prox->ante = NULL;
				lista->prim = aux->prox;
        //printf("\n%d",lista->prim->info->matricula);
				buscaBinLst(lista,info);	
      
			}
    print_lst(lista);
		}
	}
}
/* void insOrdLst(Plista lst,Paluno aluno){
    if (lst != NULL){
      Pno novo = (Pno)malloc(sizeof(Tno));
      Pno aux;
      if(novo == NULL){
        printf("Erro de alocação");
      }else{
        novo->ante = NULL;
        novo->prox = NULL;
        novo->info = aluno;
        if(lst->tam == 0){
            lst->prim = novo;
            lst->ulti = novo;
            lst->tam = 1;
        }else{
          aux = lst->prim;
          if(lst->tam == 1){
            if(aux->info->matricula > novo->info->matricula){
              lst->prim = novo;
              novo->prox = aux;
              aux->ante = novo;
              lst->ulti = aux;
            }
          }else{
            while(aux != NULL){
              if(aux->info->matricula > novo->info->matricula){
                novo->prox = aux;
                aux->ante = novo;
                if(aux == lst->prim){
                  lst->prim = novo;
                }else{
                  novo->ante = aux->ante;
                  aux->ante->prox = novo; 
                }
                lst->tam++;
              }else{
                aux = aux->prox;
              }
            }
          }
        }
      }
  }
}*/
