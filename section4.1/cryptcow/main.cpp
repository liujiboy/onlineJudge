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
#include <map>
using namespace std;
ifstream fin("cryptcow.in");
ofstream fout("cryptcow.out");
string target="Begin the Escape execution at the Break of Dawn";
map<char,int> m;
struct Position{
	int pos[9];
	int len;
	Position():len(0)
	{
	}
       	inline void push_back(int index)
	{
		pos[len++]=index;
	}
	inline int front()
	{
		return pos[0];
	}
	inline int back()
	{
		return pos[len-1];
	}
};
struct SubString{
	string sub[75];
	int len;
	SubString():len(0)
	{
	}
       	inline void push_back(string s)
	{
		sub[len++]=s;
	}
};

inline int find(string&input)
{
	Position cpos,opos,wpos;
	//SubString words;
	string word="";
	for(int i=0;i<input.size();i++)
	{
		char c=input.at(i);
		switch(c){
			case 'C':
				cpos.push_back(i);
				if(word!="")
				{
					//words.push_back(word);
					if(target.find(word)==string::npos)
						return 0;
					word="";
				}
				break;
			case 'O':
				opos.push_back(i);
				if(word!="")
				{
					if(target.find(word)==string::npos)
						return 0;
					word="";
				}

				break;
			case 'W':
				wpos.push_back(i);
				if(word!="")
				{
					if(target.find(word)==string::npos)
						return 0;
					word="";
				}

				break;
			default:
				word+=c;
		}
	}
	if(word!="")
	{
		if(target.find(word)==string::npos)
			return 0;

	}

	if(cpos.len!=wpos.len&&wpos.len!=opos.len)
	{
		return 0;
	}
	if(cpos.len==0)
	{
		if(input==target)
		{
			return 1;
		}else
		{
			return 0;
		}
	}
	/*for(int i=0;i<words.len;i++)
	{
		if(target.find(words.sub[i])==string::npos)
			return 0;
	}*/
	if(!(cpos.front()<opos.front()&&opos.back()<wpos.back()))
	{
		return 0;
	}
	for(int i=0;i<cpos.pos[0];i++)
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
		{

			return 0;

		}
	}
	for(int i=0;i<cpos.len;i++)
	{
		int c=cpos.pos[i];

		for(int j=wpos.len-1;j>=0;j--)
		{
			int w=wpos.pos[j];

			for(int k=0;k<opos.len;k++)
			{
				int o=opos.pos[k];
				if(c<o&&o<w)
				{
					string newInput=input.substr(0,c)+input.substr(o+1,w-o-1)+input.substr(c+1,o-c-1)+input.substr(w+1);
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
	if((input.length()-target.length())%3!=0)
		fout<<0<<" "<<0<<endl;
	else{
		int retval=find(input);
		if(retval)
			fout<<1<<" "<<retval-1<<endl;
		else
			fout<<0<<" "<<0<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}
