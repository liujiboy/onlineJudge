/*
LANG:C++
TASK:agrinet
*/
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
using namespace std;
ifstream fin("agrinet.in");
ofstream fout("agrinet.out");
int n;
int tree[100];
struct edge{
	int a;
	int b;
	int cost;
	edge(int a,int b,int cost)
	{
		this->a=a;
		this->b=b;
		this->cost=cost;
	}
};
vector<edge> graph;
bool cmp(const edge&e1,const edge&e2)
{
	return e1.cost<e2.cost;
}
int main() {
	fin>>n;
	for(int a=0;a<n;a++)
		for(int b=0;b<n;b++)
		{
			int cost;
			fin>>cost;
			if(b>=a+1&&a!=b)
			{
				edge e(a,b,cost);
				graph.push_back(e);
			}

		}
	sort(graph.begin(),graph.end(),cmp);
	for(int i=0;i<n;i++)
		tree[i]=i;
	int min=0;
	for(int i=0;i<graph.size();i++)
	{
	//	cout<<graph[i].a<<","<<graph[i].b<<","<<graph[i].cost<<endl;
		edge e=graph[i];
		if((tree[e.a]!=tree[e.b]))
		{
			int k=tree[e.b];
			for(int i=0;i<n;i++)
				if(tree[i]==k)
					tree[i]=tree[e.a];
			min+=e.cost;
		}
	}
	fout<<min<<endl;
	fin.close();
	fout.close();
	return 0;
}
