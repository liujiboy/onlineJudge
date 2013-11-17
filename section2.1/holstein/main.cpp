/*
LANG:C++
TASK:holstein
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
ifstream fin("holstein.in");
ofstream fout("holstein.out");
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
int vitamins[25];
int feeds[15][25];
int n; //the number of types of vitamins
int m; //the number of types of feeds
bool stop=false;
bool isvalid(bool *scoops)
{
	int v[25];
	init(v,25,0);
	for(int i=0;i<m;i++)
	{
		if(scoops[i])
		{
			for(int j=0;j<n;j++)
			{
				v[j]+=feeds[i][j];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(vitamins[i]>v[i])
			return false;
	}
	return true;
}
void cal(bool* scoops,int start,int m,int num)
{
	if(num==0)
	{
		if(isvalid(scoops))
		{
			//print(scoops,m);
			stop=true;
			int count=0;
			stringstream ss;
			for(int i=0;i<m;i++)
			{
				if(scoops[i])
				{
					count++;
					ss<<i+1<<" ";
				}
			}
			fout<<count<<" ";
			string s=ss.str();
			fout<<s.substr(0,s.size()-1)<<endl;	
		}
	}
	else{
		for(int i=start;i<m&&!stop;i++)
		{
			scoops[i]=true;
	//		print(scoops,m);
	//		cin.get();
			cal(scoops,i+1,m,num-1);
			scoops[i]=false;
		}
	}

}
int main() {
	fin>>n;
	for(int i=0;i<n;i++)
		fin>>vitamins[i];
	fin>>m;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			fin>>feeds[i][j];
		}
	}
	//print(feeds,m,n);
	bool scoops[15];
	init(scoops,15,false);
	//print(scoops,m);
	for(int i=0;i<m&&!stop;i++)
	{
		cal(scoops,0,m,i+1);
	}
	fin.close();
	fout.close();
	return 0;
}
