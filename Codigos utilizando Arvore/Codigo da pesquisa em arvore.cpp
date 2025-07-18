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

treenodeptr tPesq(treenodeptr p, int x)
{
	if (p == NULL) // elemento n~ao encontrado
		return NULL;
	else if (x == p->info) // elemento encontrado na raiz
			return p;
	else if (x < p->info) // procura na sub´arvore esquerda
			return tPesq(p->esq,x);
	else // procura na sub´arvore direita
		return tPesq(p->dir,x);
}

int main()
{
	treenodeptr arvore = NULL; // Ponteiro para a raiz
	treenodeptr aux;
	int x;
	
	tInsere(arvore,14);
	tInsere(arvore,4);
	tInsere(arvore,18);
	
	aux = tPesq(arvore,13);
	if(aux !=NULL)
		cout << aux->info << endl;
	else
		cout << "nao encontrado" << endl;
	//Mostrando arvore
	cout << "raiz: " << arvore->info << endl;
	cout << "filho esquerdo: " << (arvore->esq)->info << endl;
	cout << "filho direito: " << (arvore->dir)->info << endl; 
	 
	return 0;
}