/*
LANG:C++
TASK:preface
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
ifstream fin("preface.in");
ofstream fout("preface.out");
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
int letters[256];
char order[7]={'I','V','X','L','C','D','M'};
string romans[3501]; //the roman numbers
int n;// the number of pages;
string lookup(int num,int n)
{
	if(romans[num]!="")
		return romans[num];
	if(n==0)
		return "";
	string s="";
	int index=num/n*n;
	if(index!=0)
	{
		s=romans[index];
	}
	s+=lookup(num%n,n/10);
	return s;
}
int main() {
	fin>>n;
	init(romans,n,string(""));
	romans[1]="I";
	/*romans[1]="II";
	romans[2]="III";
	romans[3]="IV";*/
	romans[5]="V";
	/*romans[5]="VI";
	romans[6]="VII";
	romans[7]="VIII";
	romans[8]="IX";*/
	romans[10]="X";
	/*romans[19]="XX";
	romans[29]="XXX";
	romans[39]="XL";*/
	romans[50]="L";
	/*romans[59]="LX";
	romans[69]="LXX";
	romans[79]="LXXX";
	romans[89]="XC";*/
	romans[100]="C";
	/*romans[199]="CC";
	romans[299]="CCC";
	romans[399]="CD";*/
	romans[500]="D";
	/*romans[599]="DC";
	romans[699]="DCC";
	romans[799]="DCCC";
	romans[899]="CM";*/
	romans[1000]="M";
	/*romans[1999]="MM";
	romans[2999]="MMM";*/
	for(int i=1;i<=1000;i*=10)
	{
		for(int j=2;j<=3;j++)
		{
			romans[j*i].append(j,romans[1*i][0]);
		//	cout<<j*i<<" "<<romans[j*i]<<endl;
		}
		if(i==1000)
			break;
		romans[4*i]=romans[1*i]+romans[5*i];
		//cout<<4*i<<" "<<romans[4*i]<<endl;
		for(int j=6;j<=8;j++)
		{
			romans[j*i]+=romans[5*i];
			romans[j*i].append(j-5,romans[1*i][0]);
		//	cout<<j*i<<" "<<romans[j*i]<<endl;
		}
		romans[9*i]=romans[1*i]+romans[10*i];
		//cout<<9*i<<" "<<romans[9*i]<<endl;
	}
	//print(romans,3001,true);
	for(int i=1;i<=n;i++)
	{
		if(romans[i]=="")
		{
			romans[i]=lookup(i,1000);
	//		cout<<i<<" "<<romans[i]<<endl;
		}
	}	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<romans[i].size();j++)
		{
			letters[romans[i][j]]++;
		}
	}
	for(int i=0;i<7;i++)
	{
		if(letters[order[i]]!=0)
		{
			fout<<order[i]<<" "<<letters[order[i]]<<endl;
		}
	}
	fin.close();
	fout.close();
	return 0;
}
