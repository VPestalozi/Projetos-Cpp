#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <list>

using namespace std;

struct ponto
{
	float x;
	float y;
};
typedef ponto vetor;

struct reta
{
	ponto A;
	ponto B;
};
typedef reta segmento;

vetor cria_vetor(ponto A, ponto B)
{
	vetor AB;
	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	return AB;
}

float vetorial(vetor A, vetor B)
{
	float v;
	v = A.x * B.y - A.y * B.x;
	return v;
}

float escalar(vetor A, vetor B)
{
	float e;
	e = A.x * B.x + A.y * B.y;
	return e;
}

float area_triangulo(ponto A, ponto B, ponto C)
{
	vetor AB;
	vetor AC;
	float area;
	AB = cria_vetor(A, B);
	AC = cria_vetor(A, C);
	area = fabs(vetorial(AB, AC)) / 2;
	return area;
}

int sentido(ponto A,ponto B,ponto C)
{
	vetor AB;
	vetor AC;
	float vet;
	AB=cria_vetor(A,B);
	AC=cria_vetor(A,C);
	vet=vetorial(AB,AC);
	if(vet>0)
		return 1;// Esquerda
	else if(vet<0)
		return -1; //Direita
	else
		return 0; // Colinear
} 

int dentro_triangulo(ponto A,ponto B,ponto C,ponto P)
{
	int s1,s2,s3;
	s1 = sentido(A,B,P);
	s2 = sentido(B,C,P);
	s3 = sentido(C,A,P);
	if(s1==s2 && s2==s3) //dentro do triangulo
		return 1; 
	else if(s1*s2==-1 || s1*s2==-1 || s2*s3==-1) //Fora do triangulo
		return -1; 
	else // Na borda do triangulo(não sabe aonde esta)
		return 0; 
}

float area_poligono(ponto v[],int n)
{
	float area=0;
	for(int i=0;i<n-2;i++)
		area += area_triangulo(v[0],v[i+1],v[i+2]);
	return area;
}

bool ponto_segmento(segmento S,ponto A,ponto B,ponto P)
{
	if(sentido(S.A,S.B,P)!=0)
		return false;
	else if(P.x>S.A.x && P.x<S.B.x)
		return true;
	else if(P.x<S.A.x&&P.x>S.B.x)
		return true;
	else if(P.y<S.A.y&&P.y>S.B.y)
		return true;
	else if(P.y>S.A.y&&P.y<S.B.y)
		return true;
	else
		return false;
}

// Função para comparar dois pontos durante a ordenação por angulos
bool cmp(ponto a,ponto b){
	// atan2((a.y-0),(a.x - 0)) -> arco tangente[(a.y-0)/(a.x-0)]
	float angA = atan2(a.y,a.x);
	float angB = atan2(b.y,b.x);
	if(angA == angB) //se os angulos forem iguais,desempata pelo mais longe
	{
		float distA = sqrt(pow(a.x,2)+pow(a.y,2)); // raiz(a.x-0)^2+(a.y-0)^2
		float distB = sqrt(pow(b.x,2)+pow(b.y,2));
		return distA > distB; // Primeiro o de maior distancia
	} 
	else
		return angA < angB; // Primeiro o de maior angulo
}

void ordenacao_angulo(ponto p[],int n)
{
	ponto pivot; // Sera o ponto mais abaixo
	pivot = p[0];
	int pos_pivot; //encontra o ponto mais baixo para ser o pivo
	pos_pivot=0;
	for(int i=1;i<n;i++)
	{
		if(p[i].y<pivot.y)
		{
			pivot = p[i];
			pos_pivot = i;
		}
		else if(p[i].y==pivot.y && p[i].x<pivot.x)
		{
			pivot=p[i];
			pos_pivot=i;
		}
	}
	
	// Coloca o pivot na posição 0 do vetor
	p[pos_pivot]=p[0];
	p[0]=pivot;
	
	// desloca o pivot para (0,0), e os demais pontos em relação ao pivo
	for(int i=0;i<n;i++)
	{
		p[i].x -= pivot.x;
		p[i].y -= pivot.y;
	}
	
	//Ordenação
	sort(p+1,p+n,cmp);
	
	//Desloca os pontos de volta a posição original
	for(int i=0;i<n;i++)
	{
		p[i].x+=pivot.x;
		p[i].y+=pivot.y;
	}
	
}

//penultimo da pilha
ponto next_to_top(list <ponto> pilha)
{
	pilha.pop_back();
	return pilha.back();
}

// Encontra o fecho convexo de um conjunto de pontos
// retorna uma lista com os pontos que compoem o fecho convexo
list <ponto> Graham_scan(ponto p[],int n)
{
	list <ponto> pilha;
	
	ordenacao_angulo(p,n);
	
	pilha.push_back(p[0]);
	pilha.push_back(p[1]);
	pilha.push_back(p[2]);
	int i=3;
	while(i<n)
	{
		// Curva a esquerda, adicionar
		if(sentido(next_to_top(pilha),pilha.back(),p[i])==1)
		{
			pilha.push_back(p[i]);
			i++;
		}
		// curva a direita (ou mesma linha), remove
		else
			pilha.pop_back();
	}
	return pilha;
}

int main()
{
	ponto v[100];
	int n;
	list <ponto> fecho_convexo;
	int lado;

	cin >> n; // Leitura do numero de lados

	for(int i = 0; i < n; i++)
		cin >> v[i].x >> v[i].y;
	
	fecho_convexo = Graham_scan(v,n);
	lado = fecho_convexo.size();
	
	while(!fecho_convexo.empty())
		fecho_convexo.pop_back();
	
	cout << lado << " lados" << endl; 

	return 0;
}