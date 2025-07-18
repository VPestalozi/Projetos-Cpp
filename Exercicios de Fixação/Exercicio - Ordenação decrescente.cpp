#include<iostream>
using namespace std;

struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode* treenodeptr;

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
// Boas praticas de programação:
// Sempre mude p nome da função quando você a modificar
// devido ao modo de operação da função mudar

void emOrdemdecr (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		emOrdemdecr(arvore->dir);
		cout << arvore->info << " ";
		emOrdemdecr(arvore->esq);
	}
}

int main()
{
	treenodeptr arvore = NULL; // ponteiro para a arvore
	int x; // var aux para leitura de dados
			
	// Inserindo dados na arvore
	cin >> x;
	while(x!=-1){
		tInsere(arvore,x);
		cin >> x;
	}
	
	emOrdemdecr(arvore); // Demonstrando a arvore em ordem decrescente
	
	return 0;
}