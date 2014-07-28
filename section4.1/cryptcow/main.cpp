/*
LANG:C++
TASK:cryptcow
*/
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
ifstream fin("cryptcow.in");
ofstream fout("cryptcow.out");
string target="Begin the Escape execution at the Break of Dawn";
int c=0;
int find(string&input)
{
	c++;
	cout<<c<<endl;
	vector<int> cpos,opos,wpos;
	for(int i=0;i<input.size();i++)
	{
		char c=input.at(i);
		switch(c){
			case 'C':
				cpos.push_back(i);
				break;
			case 'O':
				opos.push_back(i);
				break;
			case 'W':
				wpos.push_back(i);
		}
	}
	if(cpos.size()!=wpos.size()&&wpos.size()!=opos.size())
	{
		return 0;
	}
	if(cpos.size()==0)
	{
		if(input==target)
		{
			return 1;
		}else
		{
			return 0;
		}
	}
	for(int i=0;i<cpos[0];i++)
	{
		if(input.at(i)!=target.at(i))
		{
			return 0;
		}
	}
	
	for(int i=0;i<input.size()-wpos.back()-1;i++)
	{
	//	cout<<i<<"\t"<<target.at(target.size()-i-1)<<"\t"<<input.at(input.size()-i-1)<<endl;
		if(target.at(target.size()-i-1)!=input.at(input.size()-i-1))
				return 0;
	}
	for(vector<int>::iterator c=cpos.begin();c!=cpos.end();c++)
	{
		for(vector<int>::iterator o=opos.begin();o!=opos.end();o++)
		{
			for(vector<int>::iterator w=wpos.begin();w!=wpos.end();w++)
			{
				if(*c<*o&&*o<*w)
				{
				string newInput=input.substr(0,*c)+input.substr(*o+1,*w-*o-1)+input.substr(*c+1,*o-*c-1)+input.substr(*w+1);
				//cout<<*c<<" "<<" "<<*o<<" "<<*w<<" "<<newInput<<endl;
				//cin.get();
				int retval=find(newInput);
				if(retval)
					return retval+1;
				}
			}

		}
	}
	return 0;
}
int main() {
	string input;
	getline(fin,input);
	int retval=find(input);
	if(retval)
		fout<<1<<" "<<retval-1<<endl;
	else
		fout<<0<<" "<<0<<endl;
	fin.close();
	fout.close();
	return 0;
}
