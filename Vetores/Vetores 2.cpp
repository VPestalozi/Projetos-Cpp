#include<iostream>
using namespace std;

int main()
{
	float *vetor = NULL;
	int N; // Tamanho desejado para o vetor
	int i; // Contador
	
	//Lendo tamanho desejado para o vetor
	cin >> N;
	// Alocando memoria para o vetor
	vetor = new float[N];
	// Lendo e inserindo elementos no vetor
	for(i=0;i<N;i++)
		cin >> vetor[i];
	//Mostrando o vetor
	for(i=0;i<N;i++)
		cout << vetor[i] << endl;
	
	delete[] vetor; // Liberando o memoria alocada
	// Obs: Sempre lembrar de liberar a memoria
	return 0;
}