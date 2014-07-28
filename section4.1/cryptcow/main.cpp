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
map<long,int> m;
inline long elf(const char *str) {

	int i=0;
	long g,sum=0;
	while (*str)
	{
		sum=(sum<<4)+((*str++)-97+1);//将hash值左移4位后加上字符ascii
		g=sum & 0xf0000000;//取出hash值的高4位
		if (g) sum^=g>>24;//因为下一步仍要左移4位，所以如果高4位不为0，进行下面处理，防止丢失信息 将高4位与5~8位xor
		sum&=~g;//消除下次可能被移到符号位的4个位
		i++;
	}
	return sum%99991;
}
inline int search(string&word)
{
	//const char *str=word.c_str();
	//long hash=elf(str);
	//if(m[hash]!=0)
	//	return m[hash];
	if(target.find(word)==string::npos)
	{
	//	m[hash]=-1;
		return -1;
	}
	else
	{
	//	m[hash]=1;
		return 1;
	}
}

inline int find(string&input)
{
	if(m.find(elf(input.c_str()))!=m.end())
	{
	//	cout<<m.find(elf(input.c_str()))->first<<endl;
		return 0;
	}
	Position cpos,opos,wpos;
	//SubString words;
	string word="",co="",ow="";
	string state="S";
	for(int i=0;i<input.size();i++)
	{
		char c=input.at(i);
		//cout<<state<<"\t"<<c<<endl;
		switch(c){
			case 'C':
				cpos.push_back(i);
				if(state=="S")
				{
					state="C";
					if(word!="")
					{
						if(target.find(word)!=0)
							return 0;
						word="";
					}
				}else if(state=="C"||state=="CO"||state=="O"||state=="W")
				{
					state="C";
					if(word!="")
					{
						if(search(word)==-1)
						{
							return 0;
						}
						word="";
					}

				}
				break;
			case 'O':
				opos.push_back(i);
				if(state=="S")
				{
					return 0;
				}else if(state=="C")
				{
					state="CO";
					co=word;
					if(word!="")
					{
						if(search(word)==-1)
							return 0;
						word="";
					}

				}else if(state=="CO"||state=="O"||state=="W")
				{
					state="O";
					if(word!="")
					{

						if(search(word)==-1)
							return 0;
						word="";
					}
				}
				break;
			case 'W':
				wpos.push_back(i);
				if(state=="S")
				{
					return 0;
				}else if(state=="C"||state=="O"||state=="W")
				{
					state="W";
					if(word!="")
					{

						if(search(word)==-1)
							return 0;
						word="";
					}


				}else if(state=="CO")
				{
					state="W";
					ow=word;
					if(target.find(ow+co)==string::npos)
						return 0;
					word="";
				}
				break;
			default:
				word+=c;
		}
	}
	if(state!="W"&&state!="S")
	{
		return 0;

	}
	else if(state=="W"&&input.find_last_of(word)!=input.size()-1)
	{
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
	/*if(!(cpos.front()<opos.front()&&opos.back()<wpos.back()))
	{
		return 0;
	}*/
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
					else
						m[elf(newInput.c_str())]=0;
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
