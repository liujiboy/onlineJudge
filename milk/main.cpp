/*
LANG:C++
TASK:milk
*/
#include <fstream>
#include <iostream>
#define MAXPRICE 1001
using namespace std;
int main() {
	ifstream fin ("milk.in");
	ofstream fout ("milk.out");
	unsigned int  needed, price, paid, farmers, amount, milk[MAXPRICE];
	for(int i=0;i<MAXPRICE;i++)
	{
		milk[i]=0;
	}
	paid = 0;
	fin>>needed>>farmers;
	for(int i = 0;i<farmers;i++){
		fin>>price>>amount;
		milk[price] += amount;   
	} 
	for(int i = 0; i<MAXPRICE;i++){
		if(needed>=milk[i]) {
			needed -= milk[i];
			paid += milk[i] * i;
		} else if(milk[i]>0) {
			paid += i*needed;
			break;    
		}
	}
	fout << paid << endl; 
	fin.close();
	fout.close();
	return 0;
}
