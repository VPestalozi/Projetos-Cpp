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
	else if (x < p->info) // insere na subarvore esquerda
		tInsere(p->esq, x);
	else // insere na subarvore direita
		tInsere(p->dir, x);
}
// Boas praticas de programação:
// Sempre mude p nome da função quando você a modificar
// devido ao modo de operação da função mudar

void contaPreOrdem (treenodeptr arvore,int N,int &i,int &E,int &menor)
{
	if (arvore != NULL)
	{
		i++;
		if(arvore->info==N)
			if(i<E){
				E = i;
				menor = 1;
			}
		contaPreOrdem(arvore->esq,N,i,E,menor);
		contaPreOrdem(arvore->dir,N,i,E,menor);
	}
}

void contaEmOrdem (treenodeptr arvore, int N,int &i,int &E,int &menor)
{
	if (arvore != NULL)
	{
		contaEmOrdem(arvore->esq,N,i,E,menor);
		i++;
		if(arvore->info==N)
			if(i<E){
				E = i;
				menor = 2;
			}
		contaEmOrdem(arvore->dir,N,i,E,menor);
	}
}

void contaPosOrdem (treenodeptr arvore, int N,int &i,int &E,int &menor)
{
	if (arvore != NULL)
	{
		contaPosOrdem(arvore->esq,N,i,E,menor);
		contaPosOrdem(arvore->dir,N,i,E,menor);
		i++;
		if(arvore->info==N)
			if(i<E){
				E = i;
				menor = 0;
			}
	}
}

void tDestruir (treenodeptr &arvore)
{
	if (arvore != NULL)
	{
		tDestruir(arvore->esq);
		tDestruir(arvore->dir);
		delete arvore;
	}
	arvore = NULL;
}


int main()
{
	treenodeptr arvore = NULL; // ponteiro para a arvore
	int x; // var aux para leitura de dados
	int N; // Variavel utilizada para ver o elemento a ser procurado
	int E=1000000; // Variavel auxiliar para a contagem de elementos
	int menor=0; // Menor pesquisa a ser realizada
	int i=0;

	// Inserindo dados na arvore
	cin >> x; // Leitura do elemento na arvore
	while(x != -1)
	{
		tInsere(arvore, x);
		cin >> x;
	}
	
	cin >> N; // Leitura do numero a ser procurado
	contaPreOrdem(arvore,N,i,E,menor);
	i=0;
	contaEmOrdem(arvore,N,i,E,menor);
	i=0;
	contaPosOrdem(arvore,N,i,E,menor);
	if(menor==1)
		cout << "Pre" << endl;
	else if(menor==0)
		cout << "Pos" << endl;
	else
		cout << "Em" << endl;
	
	tDestruir(arvore); // Destruindo a arvore
	
	return 0;
}
