/*
LANG:C++
TASK:pprime
*/
#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;
int primes[10000];
int pals[12000];
int len=0;
int plen=0;
bool isprime(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
/*bool isPrimefast(int n)
{
	for(int i=0;i<len&&primes[i]<=sqrt(n);i++)
	{
		//cout<<i<<" "<<primes[i]<<endl;
		if(n%primes[i]==0)
		{
			return false;
		}
	}
	return true;
}*/
int main() {
	ifstream fin ("pprime.in");
	ofstream fout ("pprime.out");
	int a,b;
	fin>>a>>b;
	//primes[0]=2;
	//primes[1]=3;
	//len=2;
	/*for(int i=4;i<10000;i++)
	{
		if(isPrime(i))
		{
			primes[len++]=i;
		}
	}*/
	//1
	pals[0]=5;
	pals[1]=7;
	plen=2;
	//2
	for(int d1=1;d1<=9;d1+=2)
	{
		int d=d1*10+d1;
		pals[plen++]=d;
	}
	//3
	for(int d1=1;d1<=9;d1+=2)
	{
		for(int d2=0;d2<=9;d2++)
		{
			int d=d1*100+d2*10+d1;
			pals[plen++]=d;
		}
	}
	//4
	for(int d1=1;d1<=9;d1+=2)
	{
		for(int d2=0;d2<=9;d2++)
		{
			int d=d1*1000+d2*100+d2*10+d1;
			pals[plen++]=d;
		}
	}
	for(int d1=1;d1<=9;d1+=2)
	{
		for(int d2=0;d2<=9;d2++)
		{
			for(int d3=0;d3<=9;d3++)
			{
				int d=d1*10000+d2*1000+d3*100+d2*10+d1;
				pals[plen++]=d;
			}
		}
	}
	for(int d1=1;d1<=9;d1+=2)
	{
		for(int d2=0;d2<=9;d2++)
		{
			for(int d3=0;d3<=9;d3++)
			{
				int d=d1*100000+d2*10000+d3*1000+d3*100+d2*10+d1;
				pals[plen++]=d;
			}
		}
	}
	for(int d1=1;d1<=9;d1+=2)
	{
		for(int d2=0;d2<=9;d2++)
		{
			for(int d3=0;d3<=9;d3++)
			{
				for(int d4=0;d4<=9;d4++)
				{
					int d=d1*1000000+d2*100000+d3*10000+d4*1000+d3*100+d2*10+d1;
					pals[plen++]=d;
				}
			}
		}
	}
	for(int d1=1;d1<=9;d1+=2)
	{
		for(int d2=0;d2<=9;d2++)
		{
			for(int d3=0;d3<=9;d3++)
			{
				for(int d4=0;d4<=9;d4++)
				{
					int d=d1*10000000+d2*1000000+d3*100000+d4*10000+d4*1000+d3*100+d2*10+d1;
					pals[plen++]=d;
				}
			}
		}
	}
	int start=0;
	while(pals[start]<a)
	{
		start++;
	}
	for(int i=start;i<plen&&pals[i]<=b;i++)
	{
			if(isprime(pals[i]))
				fout<<pals[i]<<endl;
	}
	//for(int i=0;i<plen;i++)
	//	fout<<pals[i]<<endl;

	/*


	if(a%2==0)
	{
		for(int i=a+1;i<=b;i+=2)
		{
			if(isPrimefast(i)&&ispal(i))
				fout<<i<<endl;
		}
	}else
	{
		for(int i=a;i<=b;i+=2)
		{
			if(isPrimefast(i)&&ispal(i))
				fout<<i<<endl;
		}

	}*/
	fin.close();
	fout.close();
	return 0;
}
