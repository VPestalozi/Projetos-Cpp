#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

struct ponto
{
	float x;
	float y;
};
typedef ponto vetor;

vetor cria_vetor(ponto A,ponto B)
{
	vetor AB;
	AB.x=B.x-A.x;
	AB.y=B.y-A.y;
	return AB;
}

float vetorial(vetor A,vetor B)
{
	float resultado;
	resultado = A.x*B.y-A.y*B.x;
	return resultado;
}

float escalar(vetor A,vetor B)
{
	float resultado;
	resultado = A.x*B.x+A.y*B.y;
	return resultado;
}

float area_triangulo(ponto A,ponto B,ponto C)
{
	vetor AB;
	vetor AC;
	float area;
	AB = cria_vetor(A,B);
	AC = cria_vetor(A,C);
	area = fabs(vetorial(AB,AC))/2;
	return area;
}

int main()
{
	int n; // numero de triangulos
	int i; // contador para o for
	float area; // Variavel responsavel pelo valor da area
	ponto p1,p2,p3; // definição dos 3 pontos
	
	cin >> n; // leitura da quantidade de triangulos
	
	// Criando os triangulos e verificando suas areas
	for(i=0;i<n;i++){
		cin >> p1.x >> p1.y; // Leitura do primeiro ponto
		cin >> p2.x >> p2.y; // Leitura do segundo ponto
		cin >> p3.x >> p3.y; // Leitura do terceiro ponto
		area=area_triangulo(p1,p2,p3); // Realização da area atraves da função
		if(area==0) // Verificando se o triangulo existe
			cout << "Nao formam triangulo" << endl;
		else // demonstração da area
			cout << fixed << setprecision(2) << area << endl;
	}			
	
	return 0;
}