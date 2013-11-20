/*
LANG:C++
TASK:lamps
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
ifstream fin("lamps.in");
ofstream fout("lamps.out");
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
string lamps;
vector<int> on;
vector<int> off;
vector<string> result;
string onoff(string l,const string&button)
{
	if(button[0]=='1')
	{
		for(int i=0;i<l.size();i++)
			l[i]=l[i]=='1'?'0':'1';
	}
	if(button[1]=='1')
	{
		for(int i=0;i*2+1<=l.size();i++)
			l[i*2]=l[i*2]=='1'?'0':'1';
	}
	if(button[2]=='1')
	{
		for(int i=1;i*2<=l.size();i++)
			l[i*2-1]=l[i*2-1]=='1'?'0':'1';
	}
	if(button[3]=='1')
	{
		for(int i=0;i*3+1<=l.size();i++)
			l[i*3]=l[i*3]=='1'?'0':'1';
	}
	return l;
}
bool checkon(const string&s)
{
	for(int i=0;i<on.size();i++)
	{
		if(s[on[i]-1]!='1')
			return false;
	}
	return true;
}
bool checkoff(const string&s)
{
	for(int i=0;i<off.size();i++)
	{
		if(s[off[i]-1]!='0')
			return false;
	}
	return true;
}

void gen(string&button,int i,int n,int c)
{
	if(i==n)
	{
		//	cout<<onoff(lamps,button)<<endl;
		string s=onoff(lamps,button);
		if(checkon(s)&&checkoff(s))
		{
			result.push_back(s);
		}	
	}else
	{
		if(c==n-i)
		{
			button[i]='1';
			gen(button,i+1,n,c-1);
			button[i]='0';
		}else
		{
			if(c>0)
			{
				for(int j='0';j<='1';j++)
				{
					button[i]=j;
					if(j=='0')
					{
						gen(button,i+1,n,c);
					}else
					{
						gen(button,i+1,n,c-1);
					}
					button[i]='0';
				}
			}
			else
			{
				button[i]='0';
				gen(button,i+1,n,c);
				button[i]='0';
			}
		}
	}
}
int main() {
	int n,c;
	fin>>n>>c;
	for(int i=0;i<n;i++)
	{
		lamps+='1';
	}
	int l;
	fin>>l;
	while(l!=-1)
	{
		on.push_back(l);
		fin>>l;
	}
	fin>>l;
	while(l!=-1)
	{
		off.push_back(l);
		fin>>l;
	}
	while(c>4)
	{
		c=c-2;
	}
	while(c>=0)
	{
		string button="0000";
		gen(button,0,4,c);
		c=c-2;
	}
	if(result.size()==0)
		fout<<"IMPOSSIBLE"<<endl;
	else
	{
		sort(result.begin(),result.end(),comp<string>());
		for(int i=0;i<result.size();i++)
			fout<<result[i]<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}
