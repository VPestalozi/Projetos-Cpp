#include <iostream>
using namespace std;

int main(int argc, char** argv)
{	
	int a=1;
	int b=2;
	int c=3;
	int d=4;
	int x=10;
	if(b<a){
		cout << "saida 1" << endl;
		return 0;	
	}
	else if(c>d){
		x = x+1;
		cout << x <<" saida 2" << endl;
		return 0;	
	}
	x=x-1;
	cout << x << endl;	
	return 0;
}