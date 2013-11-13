/*
LANG:C++
TASK:holstein
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
ifstream fin("holstein.in");
ofstream fout("holstein.out");
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
int main() {
	fin.close();
	fout.close();
	return 0;
}
