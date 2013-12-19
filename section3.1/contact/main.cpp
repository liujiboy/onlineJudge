/*
LANG:C++
TASK:contact
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
ifstream fin("contact.in");
ofstream fout("contact.out");
int a,b,n;
string sequence;
map<string,int> patterns;
typedef struct{
	string first;
	int second;
}kv;
bool cmp(kv v1,kv v2)
{
	if(v1.second<v2.second)
		return false;
	else if(v1.second>v2.second)
		return true;
	else
	{
		if(v1.first.size()<v2.first.size())
				return true;
		else if(v1.first.size()>v2.first.size())
			return false;
		else{
			return v1.first<v2.first;
		}
	}
}
int main() {
	fin>>a>>b>>n;
	while(fin.good())
	{
		string s;
		fin>>s;
		sequence.append(s);
	}
	for(int len=a;len<=b;len++)
	{
		for(int i=0;i<(int)sequence.size()-len+1;i++)
		{
			string s=sequence.substr(i,len);
			patterns[s]++;
		}
	}
	vector<kv> r;
	for(map<string,int>::iterator it=patterns.begin();it!=patterns.end();it++)
	{
		kv a;
		a.first=it->first;
		a.second=it->second;
		r.push_back(a);
	}
	sort(r.begin(),r.end(),cmp);
	int v=r[0].second;
	int k=1;
	int count=0;
	fout<<r[0].second<<endl;
	for(int i=0;i<r.size();)
	{
		if(v==r[i].second)
		{
			count++;
			if(count%6==1)
			{
				fout<<r[i].first;
			}else
			{
				fout<<" "<<r[i].first;
			}
			if(count%6==0)
			{
				fout<<endl;
				count=0;
			}
			i++;
		}else
		{
			k++;
			if(k>n)
				break;
			if(count!=0)
				fout<<endl;
			fout<<r[i].second<<endl;
			v=r[i].second;
			count=0;
		}
	}
	if(count!=0)
		fout<<endl;
	fin.close();
	fout.close();
	return 0;
}
