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
ifstream fin("hamming.in");
ofstream fout("hamming.out");
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
int diff(int n1,int n2,int b)
{
	int d=n1^n2;
	int count=0;
	int i=0;
	while(d!=0&&i<b)
	{
		if(d&0x1)
			count++;
		d=d>>1;
		i++;
	}
	return count;
}
int main() {
	int n,b,d;
	fin>>n>>b>>d;
	int max=pow(2,b);
	vector<int> v;
	v.push_back(0);
	for(int i=1;v.size()<n&&i<max;i++)
	{
		bool flag=true;
		for(int j=0;j<v.size();j++)
		{
			if(diff(v[j],i,b)<d)
			{
				flag=false;
				break;
			}
		}
		if(flag)
			v.push_back(i);
//		for_each(v.begin(),v.end(),print<int>(false));
//		cin.get();
	}
	for(int i=0;i<v.size();i++)
	{
		if((i+1)%10==0||i==v.size()-1)
		{
			fout<<v[i]<<endl;
		}else
		{
			fout<<v[i]<<" ";
		}

	}	
	fin.close();
	fout.close();
	return 0;
}
