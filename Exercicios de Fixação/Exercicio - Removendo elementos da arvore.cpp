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

treenodeptr tMenor(treenodeptr &arvore)
{
	treenodeptr t;
	t = arvore;
	if (t->esq == NULL) // encontrou o menor valor
	{
		arvore = arvore->dir;
		return t;
	}
	else // continua a busca na sub´arvore esquerda
		return tMenor(arvore->esq);
}


int tRemove(treenodeptr &arvore, int x)
{
	treenodeptr p;
	if (arvore == NULL) // ´arvore vazia
		return 1;
	if (x == arvore->info)
	{
		p = arvore;
		if (arvore->esq == NULL) // a raiz n~ao tem filho esquerdo
			arvore = arvore->dir;
		else if (arvore->dir == NULL) // a raiz n~ao tem filho direito
			arvore = arvore->esq;
		else // a raiz tem ambos os filhos
		{
			p = tMenor(arvore->dir);
			arvore->info = p->info;
		}
		delete p;
		return 0;
	}
	else if (x < arvore->info)
		return tRemove(arvore->esq, x);
	else
		return tRemove(arvore->dir, x);
}

void contaPreOrdem (treenodeptr arvore, int &N)
{
	if (arvore != NULL)
	{
		N++;
		contaPreOrdem(arvore->esq, N);
		contaPreOrdem(arvore->dir, N);
	}
}

//retorna o numero de nos da arvore
int contaNos(treenodeptr arvore)
{
	int N = 0; // Numero de nos da arvore
	contaPreOrdem(arvore, N); // Chamando a função para varrer arvore econtar os nos

	return N;
}

void emOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		emOrdem(arvore->esq);
		cout << arvore->info << " ";
		emOrdem(arvore->dir);
	}
}

void posOrdem (treenodeptr arvore)
{
	if (arvore != NULL)
	{
		posOrdem(arvore->esq);
		posOrdem(arvore->dir);
		cout << arvore->info << " ";
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
	int n; // Variavel utilizada para ver o elemento a ser removido
	int rev = 2; // Variavel que determina se o numero foi removido ou não

	// Inserindo dados na arvore
	cin >> x; // Leitura do elemento na arvore
	while(x != 0)
	{
		tInsere(arvore, x);
		cin >> x;
	}

	cin >> n; // Leitura do numero a ser removido
	while(rev != 1) // Condição que determina a remocao de todos os numeros desejados
		rev = tRemove(arvore, n); // Removendo os numeros
	
	emOrdem(arvore);  // Demonstrando a arvore de maneira crescente
	tDestruir(arvore); // Destruindo a arvore
	
	return 0;
}
