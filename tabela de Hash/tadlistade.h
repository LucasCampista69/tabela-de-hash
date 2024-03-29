/* Lucas Campista da Silva 20172bsi0360....
   Jack johnson 20161bsi0268.... */

typedef struct aluno{
	int matricula;
	char nome[81];
	char turma;
	char email[41];
}Taluno,* Paluno;

typedef struct no{
	Paluno info;
	struct no * ante;
	struct no * prox;
} Tno, * Pno ;
	
typedef struct {
	Tno * prim;
	Tno * ulti;
	int tam;
} Tlista, * Plista;

Plista init_lst(void);

Paluno init_aluno(void);

int len_lst(Plista lst);

int in_lst(Plista lst, int elem);

int empty_lst(Plista lst);

void print_lst(Plista lst);

void print_reverse_lst(Plista lst);  

void append_lst(Plista lst, Paluno elem);

void insert_lst(Plista lst, int pos, Paluno elem);

void insOrdLst(Plista lst,Paluno aluno);

void del_ult_lst(Plista lst);

void del_lst(Plista lst);

//Plista load_lst(FILE * arq);

//void save_lst(Plista lst, FILE * arq);

void del_pos_lst(Plista lst, int pos);

void del_info_lst(Plista lst, int elem); 

int index_lst(Plista lst, int elem);

int get_pos_lst (Plista lst, int pos);

Paluno buscaBinLst(Plista lista,int info);

void insOrdLst(Plista lst,Paluno aluno);