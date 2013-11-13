/*
LANG:C++
TASK:dualpal
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
using namespace std;
char numbers[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};	
void itoa(int n,string&s,int base)
{
	if(n==0)
	{
		s+='0';
	}
	else
	{
		itoa(n/base,s,base);
		if(s=="0")
			s="";
		s+=numbers[n%base];
	}
}
bool ispal(int n,int base)
{
	string s;
	itoa(n,s,base);
	for(int i=0,j=s.size()-1;j-i>0;i++,j--)
		if(s[i]!=s[j])
			return false;
	return true;
}
bool isdualpal(int n)
{
		int count=0;
		for(int base=2;base<=10;base++)
		{
			if(ispal(n,base))
			{
				count++;
				if(count==2)
				{
					return true;
				}
			}
		}
		return false;
}
int main(int argc,char** argv)
{
	ifstream in("dualpal.in");
	ofstream out("dualpal.out");
	int n,start;
	in>>n>>start;
	for(int s=start+1;s<=2147483647&&n>0;s++)
	{
		if(isdualpal(s))
		{
			out<<s<<endl;
			n--;
		}	
	}
	in.close();
	out.close();
	return 0;

}
