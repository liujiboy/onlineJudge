/*
LANG:C++
TASK:milk3
*/
#include <fstream>
#include <iostream>
class milk3;
class bucket{
private:
	int limit;
	int now;
public:
	bucket(int limit=0,int now=0){
		this->limit=limit;
		this->now=now;
	}
friend milk3;
};
class milk3{
private:
public:
	milk3(int a,int b,int c)
	{
	}
}
int main() {
	ifstream fin ("milk3.in");
	ofstream fout ("milk3.out");
	fin.close();
	fout.close();
	return 0;
}
