/*
LANG:C++
TASK:sprime
*/
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
bool isprime(int n)
{
	for(int i=3;i*i<=n;i+=2)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
int main() {
	ifstream fin ("sprime.in");
	ofstream fout ("sprime.out");
	int n;
	fin>>n;
	vector<int> *primes=new vector<int>();
	primes->push_back(2);
	primes->push_back(3);
	primes->push_back(5);
	primes->push_back(7);
	for(int i=1;i<n;i++)
	{
		vector<int> *newprimes=new vector<int>();
		for(vector<int>::iterator it=primes->begin();it!=primes->end();it++)
		{
			for(int d=1;d<=9;d+=2)
			{
				int newp=(*it)*10+d;
				if(isprime(newp))
					newprimes->push_back(newp);
			}
		}
		delete primes;
		primes=newprimes;
	}
	for(vector<int>::iterator it=primes->begin();it!=primes->end();it++)
		fout<<*it<<endl;
	fin.close();
	fout.close();
	return 0;
}
