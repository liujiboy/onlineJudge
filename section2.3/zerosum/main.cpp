/*
LANG:C++
TASK:zerosum
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <stack>
using namespace std;
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
	template<class T>
void print(T a,int row,int col,ostream&out=cout)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(j!=col-1)
				out<<a[i][j]<<" ";
			else
				out<<a[i][j];
		}
		cout<<endl;
	}
}
	template<class T>
void print(T a,int len,ostream&out=cout,bool newline=false)
{
	for(int i=0;i<len;i++)
	{
		if(!newline)
		{
			if(i!=len-1)
				out<<a[i]<<" ";
			else
				out<<a[i]<<endl;
		}
		else
		{
			out<<a[i]<<endl;
		}
	}
}
	template<class T>
void init(T* a,int len,T v)
{
	for(int i=0;i<len;i++)
		a[i]=v;
}
template<class T> 
class comp{
	public:
		bool operator()(T a,T b)
		{
			return a<b;
		}
};
char op[9];
char ch[3]={' ','+','-'};
int num[9];
int n;
bool check(char top,char ch)
{
	if(ch=='+'&&top=='#')
		return true;
	if(ch=='+'&&top!='#')
		return false;
	if(ch=='-'&&top=='#')
		return true;
	if(ch=='-'&&top!='#')
		return false;
	if(ch=='#'&&top!='#')
		return false;
	if(ch=='#'&&top=='#')
		return true;
	if(ch==' '&&top==' ')
		return false;
	if(ch==' '&&top!=' ')
		return true;
	return true;
}
int sum()
{
	stack<int> ns;
	stack<char> os;
	os.push('#');
	for(int i=0;i<n;i++)
	{
		ns.push(num[i]);
		int a;
		int b;
		//cout<<os.top()<<","<<op[i]<<" "<<!check(os.top(),op[i])<<endl;
		while(!check(os.top(),op[i]))
		{
			//cout<<"add"<<endl;
			a=ns.top();
			ns.pop();
			//cout<<"kkk"<<ns.top()<<endl;
			b=ns.top();
		//	cout<<b<<endl;
			ns.pop();
			//cout<<a<<" "<<b<<" "<<ns.top()<<" "<<os.size()<<endl;
		//	cout<<a<<" "<<b<<endl;
			if(os.top()==' ')
				 ns.push(b*10+a);
			else if(os.top()=='+')
				ns.push(b+a);
			else if(os.top()=='-')
				ns.push(b-a);
			os.pop();
		//	cout<<ns.size()<<" "<<os.size()<<" "<<os.top()<<endl;
		}
		os.push(op[i]);
	}
	return ns.top();
}
void find(int i)
{
	if(i==n-1)
	{
		if(sum()==0)
		{
			for(int i=0;i<n;i++)
			{
				if(i<n-1)
					fout<<num[i]<<op[i];
				else
					fout<<num[i]<<endl;
			}
		}
	//	print(op,n);
		//cout<<sum()<<endl;
		//cin.get();
		return;
	}
	for(int j=0;j<3;j++)
	{
		op[i]=ch[j];
		find(i+1);
	}
}
int main() {
	fin>>n;
	//cout<<(int)'+'<<(int)'-'<<(int)' '<<endl;
	for(int i=0;i<n;i++)
	{
		num[i]=i+1;
	}
	op[n-1]='#';
	find(0);
	fin.close();
	fout.close();
	return 0;
}
