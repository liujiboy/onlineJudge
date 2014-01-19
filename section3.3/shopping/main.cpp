/*
LANG:C++
TASK:shopping
*/
#include <list>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
#include <cctype>
#include <stack>
using namespace std;
ifstream fin("shopping.in");
ofstream fout("shopping.out");
struct product{
	int c;
	int k;
};
struct offer{
	int n;
	product products[6];
	int p;
};
offer offers[100];
int offer_size;
int order[1000];
int order_size;
int many[6];
int price[6];
int best[6][6][6][6][6];
int cal();
int sub(offer& of)
{
	for(int i=1;i<=of.n;i++)
	{
			product pr=of.products[i];
			if(many[order[pr.c]]<pr.k)
				return 0x7FFFFFFF;
	}
	for(int i=1;i<=of.n;i++)
	{
			product pr=of.products[i];
			many[order[pr.c]]-=pr.k;	
	}

	int total=cal()+of.p;
	for(int i=1;i<=of.n;i++)
	{
			product pr=of.products[i];
			many[order[pr.c]]+=pr.k;	
	}
	return total;
}
int cal()
{
	if(best[many[1]][many[2]][many[3]][many[4]][many[5]]!=0)
		return best[many[1]][many[2]][many[3]][many[4]][many[5]];
	int min_p=0x7FFFFFFF;
	for(int i=1;i<=offer_size;i++)
	{
		offer of=offers[i];
		int total=sub(of);
		if(total<min_p)
			min_p=total;
	}
	if(min_p==0x7FFFFFFF)
	{
		int total=0;
		for(int i=1;i<=6;i++)
		{
			total+=many[i]*price[i];
		}
		min_p=total;
	
	}
	best[many[1]][many[2]][many[3]][many[4]][many[5]]=min_p;
	return min_p;
}
int main() {
	fin>>offer_size;
	for(int i=1;i<=offer_size;i++)
	{
		fin>>offers[i].n;
		for(int j=1;j<=offers[i].n;j++)
		{
			fin>>offers[i].products[j].c>>offers[i].products[j].k;			
		}
		fin>>offers[i].p;
	}
	fin>>order_size;
	for(int i=1;i<=order_size;i++)
	{
		int c,k,p;
		fin>>c>>k>>p;
		order[c]=i;
		many[i]=k;
		price[i]=p;
	}
	fout<<cal()<<endl;
	fin.close();
	fout.close();
	return 0;
}
