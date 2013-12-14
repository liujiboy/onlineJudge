/*
LANG:C++
TASK:comehome
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
using namespace std;
ifstream fin("comehome.in");
ofstream fout("comehome.out");
int n;
int d;
vector<int> digits;
map<int,int> remainders;
map<int,int>::iterator it;
int main() {
	fin>>n>>d;
	bool flag=true;
	int i=0;
	while(n!=0)
	{
		digits.push_back(n/d);
		i++;
		n=(n%d)*10;
		it=remainders.find(n);
		if(it==remainders.end())
		{
			remainders[n]=i;
		}else
		{
			break;
		}	
	}
	stringstream ss;
	string num;
	if(digits.size()==1)
	{
		ss<<digits[0]<<"."<<"0"<<endl;
	}else
	{	
		ss<<digits[0]<<".";
		if(it!=remainders.end())
		{
			for(int i=1;i<it->second;i++)
			{
				ss<<digits[i];
			}
			ss<<"(";
			for(int i=it->second;i<digits.size();i++)
				ss<<digits[i];
			ss<<")";
		}
		else
		{
			for(int i=1;i<digits.size();i++)
				ss<<digits[i];
		}
	}
	ss>>num;
	for(int i=0;i<num.size();i++)
	{
		if(i!=0&&i%76==0)
			fout<<endl;
		fout<<num[i];
	}
	fout<<endl;

	fin.close();
	fout.close();
	return 0;
}
