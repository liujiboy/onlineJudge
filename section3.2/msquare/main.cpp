/*
LANG:C++
TASK:msquare
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
ifstream fin("msquare.in");
ofstream fout("msquare.out");
map<string,string> ms;
string input;
void swap(char&a,char&b)
{
	char t=a;
	a=b;
	b=t;
}

void A(string&s)
{
	swap(s[0],s[7]);
	swap(s[1],s[6]);
	swap(s[2],s[5]);
	swap(s[3],s[4]);
}
void B(string&s)
{
	char t=s[3];
	s[3]=s[2];
	s[2]=s[1];
	s[1]=s[0];
	s[0]=t;
	t=s[4];
	s[4]=s[5];
	s[5]=s[6];
	s[6]=s[7];
	s[7]=t;
}
void C(string&s)
{
	char t=s[1];
	s[1]=s[6];
	s[6]=s[5];
	s[5]=s[2];
	s[2]=t;	
}
int main(){

	string s="12345678";
	char c;
	for(int i=0;i<8;i++)
	{
		fin>>c;
		input+=c;
	}
	ms[s]="";
	queue<string> q;
	q.push(s);
	if(s!=input)
	{
		while(!q.empty())
		{
			string sa=q.front();
			A(sa);
			string sb=q.front();
			B(sb);
			string sc=q.front();
			C(sc);
			if(ms[sa]=="")
			{
				q.push(sa);
				ms[sa]=ms[q.front()]+"A";
				if(sa==input)
					break;
			}
			if(ms[sb]=="")
			{
				q.push(sb);
				ms[sb]=ms[q.front()]+"B";
				if(sb==input)
					break;
			}
			if(ms[sc]=="")
			{ 
				q.push(sc);
				ms[sc]=ms[q.front()]+"C";
				if(sc==input)
					break;
			}
			q.pop();
		}
	}
	fout<<ms[input].size()<<endl;
	if(ms[input].size()==0)
	{
		fout<<endl;
	}
	else
	{
		int i=0;
		for(;i<ms[input].size();i++)
		{
			fout<<ms[input][i];
			if(i%60==0&&i!=0)
				fout<<endl;

		}
		if(i%60!=0)
			fout<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}
