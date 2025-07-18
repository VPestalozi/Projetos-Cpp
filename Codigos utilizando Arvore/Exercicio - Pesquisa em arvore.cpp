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
	int N; // Numero de elementos a serem inseridos na arvore
	int a; // Numeros a serem inseridos na arvore
	int x; // Numero a ser pesquisado
	int i; // Variavel para a realização do for
	
	cin >> N; // leitura do numero de elementos
	
	for(i=0;i<N;i++){
		cin >> a; // leitura do elemento a ser inserido na arvore
		tInsere(arvore,a); // Inserindo o elemento na arvore
	} 
	
	cin >> x; // Numero a ser pesquisado
	
	aux = tPesq(arvore,x); //auxiliar utilizada para a realização da pesquisa
	
	if(aux !=NULL) // Verificando se o numero foi encontrado ou não
		cout << "Encontrado" << endl;
	else
		cout << "Nao encontrado" << endl;
	 
	return 0;
}