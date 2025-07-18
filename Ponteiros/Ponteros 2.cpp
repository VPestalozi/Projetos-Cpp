#include<iostream>
#include<iomanip>
using namespace std;

struct cofre
{
	float nota1;
	float nota2;
	float nota3;
	float nota4;
	float media;	
};

int main()
{
	cofre *ler;
	
	ler = new cofre=NULL;
	cin >> ler->nota1;
	cin >> ler->nota2;
	cin >> ler->nota3;
	cin >> ler->nota4;
	
	ler->media = (ler->nota1+ler->nota2+ler->nota3+ler->nota4)/4;
	
	cout << fixed << setprecision(2);
	cout << ler->media;
	
	delete ler;
	
	return 0;
}