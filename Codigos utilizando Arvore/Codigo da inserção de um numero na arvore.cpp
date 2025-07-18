#include<iostream>
using namespace std;

struct treenode //Struct que vai guardar os elementos
{
	int info;
	treenode *esq; // Ponteiro do filho esquerdo da arvore
	treenode *dir; // ponteiro do filho direito da arvore
};
typedef treenode* treenodeptr; // Mudando a variavel

void tInsere(treenodeptr &p, int x)
{
	if (p == NULL) // insere na raiz
	{
		p = new treenode;
		p->info = x;
		p->esq = NULL;
		p->dir = NULL;
	}
	else
		if (x < p->info) // insere na subarvore esquerda
			tInsere(p->esq,x);
		else // insere na subarvore direita
			tInsere(p->dir,x);
}

int main()
{
	treenodeptr arvore = NULL; // Ponteiro para a raiz
	int x; // var aux p/ inserir dados
	
	x = 14; // Raiz
	arvore = new treenode; // alocando memoria
	arvore->info = x; // preenchendo campo info
	arvore->esq=NULL;
	arvore->dir=NULL;
	
	x = 4; // Filho esquerdo 
	arvore->esq = new treenode; // alocando memoria para um novo nó na arvore
	(arvore->esq)->info=x;
	(arvore->esq)->esq=NULL;
	(arvore->esq)->dir=NULL; 
	
	x=18; // Filho direito
	arvore->dir = new treenode;
	(arvore->dir)->info=x;
	(arvore->dir)->esq=NULL;
	(arvore->dir)->dir=NULL;
	
	//Mostrando arvore
	cout << "raiz: " << arvore->info << endl;
	cout << "filho esquerdo: " << (arvore->esq)->info << endl;
	cout << "filho direito: " << (arvore->dir)->info << endl; 
	 
	return 0;
}