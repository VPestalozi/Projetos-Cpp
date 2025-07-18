#include <iostream>
#include <iomanip>
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
	float media=0; // Variavel utilizada para ver o elemento a ser removido
	float i=0; // Numero de elementos

	// Inserindo dados na arvore
	cin >> x; // Leitura do elemento na arvore
	while(x != -1)
	{
		tInsere(arvore, x);
		i++;
		media += x;
		cin >> x;
	}
	
	media = media/i;
	cout << fixed << setprecision(2) << "Media: " << media << endl;
	tDestruir(arvore); // Destruindo a arvore
	
	return 0;
}