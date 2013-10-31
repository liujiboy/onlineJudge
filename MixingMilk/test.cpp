#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	const char *s1="abcd";
	string s2="abcd";
	reverse(s2.begin(),s2.end());
	cout<<s2<<endl;
}
