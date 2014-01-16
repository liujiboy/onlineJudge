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
map<string,int> ms;
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
bool flag=false;
void f(string s);
void testfind(string&s)
{
	if(ms[s]==0)
	{
		if(s==input)
		{
			cout<<"find"<<endl;
			flag=true;
		}
		else{
			ms[s]=1;
			f(s);
		}
	}else
	{
		
	}

}
void f(string s)
{
	string sa=s;
	if(!flag)
	{
		A(sa);
		testfind(sa);
	}
	string sb=s;
	if(!flag)
	{
		B(sb);
		testfind(sb);
	}
	string sc=s;
	if(!flag)
	{
		C(sc);
		testfind(sc);
	}
	
	
}
int main(){

	string s="12345678";
	fin>>input;	
	f(s);
	fin.close();
	fout.close();
	return 0;
}
