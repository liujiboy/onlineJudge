/*
LANG:C++
TASK:fence
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
ifstream fin("fence.in");
ofstream fout("fence.out");
map<int,list<int> > graph;
int F;
int N=0;
vector<int> result;
int min_length=0x7FFFFFFF;
void insert(int i,list<int>& nodes)
{
	list<int>::iterator it=nodes.begin();
	for(;it!=nodes.end();it++)
	{
		if(i<*it)
		{
			break;
		}
	}
	nodes.insert(it,i);
}
void erase(int i,list<int>&nodes)
{
	list<int>::iterator it=find(nodes.begin(),nodes.end(),i);
	nodes.erase(it);
}
void findbest(int start,map<int,list<int> > graph)
{
		stack<int> s;
		vector<int> r;
		int length=0;
		s.push(start);
		while(!s.empty())
		{
			int i=s.top();
			if(graph[i].size()>0)
			{
				list<int>::iterator it=graph[i].begin();
				s.push(*it);
				graph[i].erase(it);
				erase(i,graph[*it]);
			}else
			{
				r.push_back(i);
				length+=i;
				s.pop();
			}
		}
		if(length<min_length)
		{
			min_length=length;
			result=r;
		}

}
int main() {
	fin>>F;
	for(int row=0;row<F;row++)
	{
		int i,j;
		fin>>i>>j;
		insert(j,graph[i]);
		insert(i,graph[j]);
	}
	bool circle=true;
	for(map<int,list<int> >::iterator it=graph.begin();it!=graph.end();it++)
	{
		if(it->second.size()%2==1)
		{
			circle=false;
			break;
		}
	}

	for(map<int,list<int> >::iterator it=graph.begin();it!=graph.end();it++)
	{
		if(!circle)
		{
			if(it->second.size()%2==1)
				findbest(it->first,graph);
		}else
		{
			findbest(it->first,graph);
		}
	}
	for(int i=result.size()-1;i>=0;i--)
	{
		fout<<result[i]<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}
