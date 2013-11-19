/*
LANG:C++
TASK:runround
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
ifstream fin("runround.in");
ofstream fout("runround.out");
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
bool digits[10];
int number[10];
unsigned long m;
inline bool is_runaround(int *n,int len)
{
	int number[10];
	for(int i=0;i<len;i++)
		number[i]=n[i];
	int next=0;
	while(number[next]!=0)
	{
		int digit=number[next];
		//cout<<next<<" "<<digit<<" "<<len<<endl;
		//cin.get();
		number[next]=0;
		next=(next+digit)%len;	
	}
	if(next!=0)
		return false;
	for(int i=0;i<len;i++)
		if(number[i]!=0)
			return false;
	return true;
}

bool search(int *number,int n,int len)
{
	if(n==len)
	{
		unsigned long num=number[0];
		for(int i=1;i<len;i++)
			num=num*10+number[i];
		if(num>m&&is_runaround(number,len))
		{
			fout<<num<<endl;
			return true;
		}
	}
	else{
		for(int i=1;i<=9;i++)
		{

			if(digits[i]==false)
			{
				digits[i]=true;
				number[n]=i;
				if(search(number,n+1,len))
					return true;
				number[n]=0;
				digits[i]=false;
			}
		}
	}
	return false;
}
int main() {
	fin>>m;
	for(int i=1;i<=10;i++)
	{
		if(search(number,0,i))
			break;
	}
	fin.close();
	fout.close();
	return 0;
}
