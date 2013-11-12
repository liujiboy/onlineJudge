/*
LANG:C++
TASK:frac1
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
ifstream fin("frac1.in");
ofstream fout("frac1.out");
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
class frac{
public:
	int n;  //numerator
	int d;  //denominator
	frac(int n,int d)
	{
		this->n=n;
		this->d=d;
	}
	bool operator<(const frac& other)
	{
		return n*other.d<other.n*d;
	}
	friend ostream&operator<<(ostream&out,const frac&f)
	{
		out<<f.n<<"/"<<f.d;
		return out;
	}
};
vector<frac> fracs;
inline int divisor(int n,int m)
{
	int r=n%m;
	while(r!=0)
	{
		n=m;
		m=r;
		r=n%m;
	}
	return m;
}
void genfrac(int n)
{
	fracs.push_back(frac(0,1));
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
		{
			if(divisor(j,i)==1)
				fracs.push_back(frac(j,i));
		}
	fracs.push_back(frac(1,1));
	//for_each(fracs.begin(),fracs.end(),print<frac>(false));
}
int main() {
	int n;
	fin>>n;
	genfrac(n);
	sort(fracs.begin(),fracs.end(),comp<frac>());
	for_each(fracs.begin(),fracs.end(),print<frac>(fout));
	fin.close();
	fout.close();
	return 0;
}
