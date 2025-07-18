#include<iostream>
using namespace std;

struct dado
{
	int info1;
	int info2;
	
};

int main()
{
	dado *produto = NULL; // Apontando o ponteiro para uma variavel segura
	// Obs: O ponteiro apontar para NULL e uma otima pratica de segurança
	
	produto = new dado; // Apontando o ponteiro para a struct
	
	produto->info1=2; // Para o ponteiro apontar para os valores da struct e nessario mudar o simbolo
	produto->info2=3;
	
	cout << produto->info1 << endl;
	cout << produto->info2 << endl;
	
	delete produto;
	
	return 0;
}