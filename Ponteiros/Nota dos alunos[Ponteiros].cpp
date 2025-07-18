#include<iostream>
#include<iomanip>
using namespace std;

struct dados
{
	float nota1;
	float nota2;
	float nota3;
	float nota4;
	float media;
};

int main()
{
	int N; // Numero de alunos
	int i; // Contador
	cin >> N;
	dados *alunos=NULL;
	alunos = new dados[N];
	alunos->media=0;
	for(i=0;i<N;i++){
		cin >> alunos[i].nota1;
		cin >> alunos[i].nota2;
		cin >> alunos[i].nota3;
		cin >> alunos[i].nota4;
		alunos->media = alunos->media+((alunos[i].nota1+alunos[i].nota2+alunos[i].nota3+alunos[i].nota4)/4);
	}
	alunos->media=alunos->media/N;
	cout << alunos->media << fixed << setprecision(2);
	
	delete[] alunos;
	
	return 0;
}