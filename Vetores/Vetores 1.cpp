#include<iostream>
using namespace std;

int main()
{
	// Obs: Todo vetor e um ponteiro
	int vetor[3];
	int *p;
	
	vetor[0] = 4;
	vetor[1] = -2;
	vetor[2] = 7;
	
	p=vetor;
	cout << *p << endl;
	p++;
	cout << *p << endl;
	p++;
	cout << *p << endl;
	p=p-2;
	cout << *p << endl;
	
	return 0;
}