#include<iostream>
using namespace std;

int main()
{
	int V[100]; // Vetor no qual sera varrido
	int X,N; // Variavel N responsavel pela posição e a Variavel X e responsavel pelo valor desejado
	bool S=false; // variavel responsavel por dizer se o numero pedido esta dentro do vetor
	
	cin >> N; // Leitura do numero de posições
	cin >> X; // Leitura do numero desejado a ser encontrado no vetor
	
	int i; // Variavel para realizar o for
	for(i=0;i<N;i++) // For responsavel por colocar os valores no vetor e varrelo
	{
		cin >> V[i];
		if(X==V[i])
			S=true;
	}
		
	if(S==true) // Saida mostrando que o vetor foi encontrado
		cout << "O valor se encontra no vetor" << endl;
	else // Saida mostrando que o vetor não foi encontrado
		cout << "Nao se encontra no vetor" << endl;	
	
}