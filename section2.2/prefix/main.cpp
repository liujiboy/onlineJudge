/*
LANG:C++
TASK:prefix
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
ifstream fin("prefix.in");
ofstream fout("prefix.out");
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
int maxp[200000];
bool start_with(const string&sequence,const string&s,int start)
{
	//cout<<"search:"<<start<<" "<<s<<endl;
	if(start+s.size()>sequence.size())
		return false;
	for(int i=0;i<s.size();i++)
	{
		if(sequence[i+start]!=s[i])
			return false;
	}
	return true;
}
int search(const string&sequence,int start,const vector<string>&primitives)
{
	if(start>=sequence.size())
		return 0;
	if(maxp[start]!=-1)
		return maxp[start];
	maxp[start]=0;
	for(int i=0;i<primitives.size();i++)
	{
		string s=primitives[i];
		if(start_with(sequence,s,start))
		{
			int len=s.size()+search(sequence,start+s.size(),primitives);
			if(maxp[start]<len)
				maxp[start]=len;
		}
	}
	return maxp[start];
}
int main() {
	init(maxp,200000,-1);
	string s;
	vector<string> primitives;
	string sequence;
	fin>>s;
	while(s!=".")
	{
		primitives.push_back(s);
		fin>>s;
	}
	fin>>s;
	while(fin.good())
	{
		sequence+=s;
		fin>>s;
	}
	for(int i=sequence.size()-1;i>=0;i--)
	{
		search(sequence,i,primitives);
	}
	fout<<maxp[0]<<endl;
	fin.close();
	fout.close();
	return 0;
}
