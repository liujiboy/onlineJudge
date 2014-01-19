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
	int p;

};
struct offer{
	vector<product> products;
	int p;
};
vector<offer> offers;
map<int,product> products;
int min_p=0x7FFFFFFF;
void cal(map<int,product> products,int total);
bool sub(offer of,map<int,product> products,int total)
{
	for(int i=0;i<of.products.size();i++)
	{
			product pr=of.products[i];
			if(products[pr.c].k>=pr.k)
			{
				products[pr.c].k-=pr.k;	
			}else
			{
				return false;
			}
	}
	cal(products,total+of.p);
	return true;
}
void cal(map<int,product> products,int total)
{
	bool flag=true;
	for(int i=0;i<offers.size();i++)
	{
		offer of=offers[i];
		if(sub(of,products,total))
		{
			flag=false;
		}
	}
	if(flag)
	{
		for(map<int,product>::iterator it=products.begin();it!=products.end();it++)
		{
			product pr=it->second;
			total+=pr.p*pr.k;
		}
		if(total<min_p)
		{
			min_p=total;
		}
	}
}
int main() {
	int n;
	fin>>n;
	for(int i=0;i<n;i++)
	{
		int k;
		fin>>k;
		offer of;
		for(int j=0;j<k;j++)
		{
			product pr;
			fin>>pr.c>>pr.k;
			of.products.push_back(pr);
		}
		fin>>of.p;
		offers.push_back(of);
	}
	fin>>n;
	for(int i=0;i<n;i++)
	{
		product pr;
		fin>>pr.c>>pr.k>>pr.p;
		products[pr.c]=pr;
	}
	cal(products,0);
	fout<<min_p<<endl;
	fin.close();
	fout.close();
	return 0;
}
