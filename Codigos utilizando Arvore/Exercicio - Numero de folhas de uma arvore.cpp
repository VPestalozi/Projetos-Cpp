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

void contaPreOrdem (treenodeptr arvore,int &N)
{
	if (arvore != NULL)
	{
		if(arvore->esq==NULL && arvore->dir==NULL)
			N++;
		contaPreOrdem(arvore->esq,N);
		contaPreOrdem(arvore->dir,N);
	}
}

//retorna o numero de folhas da arvore
int contaFolhas(treenodeptr arvore)
{
	int N=0; // Numero de folhas da arvore
	contaPreOrdem(arvore,N); // Chamando a função para varrer arvore econtar as folhas
	
	return N;
}

int main()
{
	treenodeptr arvore = NULL; // ponteiro para a arvore
	int x; // var aux para leitura de dados
	int f; // Numero de folhas da arvore
			
	// Inserindo dados na arvore
	cin >> x;
	while(x!=-1){
		tInsere(arvore,x);
		cin >> x;
	}
	f = contaFolhas(arvore);
	
	cout << f << endl;
	
	return 0;
	}
