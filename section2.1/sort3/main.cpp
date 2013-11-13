/*
LANG:C++
TASK:sort3
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
ifstream fin("sort3.in");
ofstream fout("sort3.out");
template<class T>
class print{
private:
	bool newline;
	ostream&out;
public:
	print(ostream&o=cout,bool flag=true):out(o),newline(flag)
	{
	}
	print(bool flag):out(cout),newline(flag)
	{
	}

	void operator()(T v)
	{
		if(newline)
			out<<v<<endl;
		else
			out<<v<<" ";
	}
};
template<class T> 
class comp{
public:
	bool operator()(T a,T b)
	{
		return a<b;
	}
};
int sc=0;
bool findswap(vector<int>&list,int i,int v,int start,int end)
{
	for(int j=start;j<end;j++)
	{
		if(list[j]==v)
		{
			//swap i,j
			int tmp=list[i];
			list[i]=list[j];
			list[j]=tmp;
			sc++;
			return true;
		}
	}
	return false;
}
int main() {
	int n;
	fin>>n;
	vector<int> list(n);
	vector<int> m(4);
	for(int i=0;i<n;i++)
	{
		fin>>list[i];
	}
	for(int i=0;i<n;i++)
	{
		m[list[i]]++;
	}
	//for_each(m.begin(),m.end(),print<int>());
	//sort 1
	for(int i=0;i<m[1];i++)
	{
		if(list[i]==2)
		{
			if(!findswap(list,i,1,m[1],m[1]+m[2]))
				findswap(list,i,1,m[1]+m[2],m[1]+m[2]+m[3]);
		}
		if(list[i]==3)
		{
			if(!findswap(list,i,1,m[1]+m[2],m[1]+m[2]+m[3]))
				findswap(list,i,1,m[1],m[1]+m[2]);

		}
	}
	//sort 2
	for(int i=m[1];i<m[1]+m[2];i++)
	{
		if(list[i]==3)
		{
			findswap(list,i,2,m[1]+m[2],m[1]+m[2]+m[3]);
		}
	}
	//for_each(list.begin(),list.end(),print<int>(false));
	fout<<sc<<endl;
	fin.close();
	fout.close();
	return 0;
}
