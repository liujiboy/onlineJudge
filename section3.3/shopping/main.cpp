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
product order[1000];
vector<int> keys;
int best[55556];
int cal();
int sub(offer& of)
{
	for(int i=0;i<of.products.size();i++)
	{
			product pr=of.products[i];
			if(order[pr.c].k<pr.k)
				return 0x7FFFFFFF;
	}
	for(int i=0;i<of.products.size();i++)
	{
			product pr=of.products[i];
			order[pr.c].k-=pr.k;	
	}

	int total=cal()+of.p;
	for(int i=0;i<of.products.size();i++)
	{
			product pr=of.products[i];
			order[pr.c].k+=pr.k;	
	}
/*	for(map<int,product>::iterator it=products.begin();it!=products.end();it++)
		{
			product pr=it->second;
			cout<<pr.c<<" "<<pr.k<<endl;
		}
	cout<<"total:"<<total<<endl;
	cin.get();*/
	return total;
}
int getkey()
{
	int key=0;
	for(int i=0;i<keys.size();i++)
	{
		int index=keys[i];
		key=key*10+order[index].k;
	}
	return key;
}
int cal()
{
	/*string pid=tostring(products);
	if(tmp[pid]!=0)
		return tmp[pid];*/
	int key=getkey();
	if(best[key]!=0)
		return best[key];
	int min_p=0x7FFFFFFF;
	for(int i=0;i<offers.size();i++)
	{
		offer of=offers[i];
		int total=sub(of);
		if(total<min_p)
			min_p=total;
	}
	if(min_p==0x7FFFFFFF)
	{
		int total=0;
		for(int i=1;i<=999;i++)
		{
			product pr=order[i];
			if(pr.k!=0)
				total+=pr.p*pr.k;
		}
		min_p=total;
	
	}
	best[key]=min_p;
	return min_p;
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
		keys.push_back(pr.c);
		order[pr.c]=pr;
	}
	fout<<cal()<<endl;
	fin.close();
	fout.close();
	return 0;
}
