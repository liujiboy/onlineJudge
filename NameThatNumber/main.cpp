/*
LANG:C++
TASK:namenum
 */
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<string>
using namespace std;
int main(int argc,char** argv)
{
	ifstream in("namenum.in");
	ifstream dictIn("dict.txt");
	ofstream out("namenum.out");
	string id;
	in>>id;
	in.close();
	int table[26]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','0','7','7','8','8','8','9','9','9','0'};
	bool none=true;
	while(dictIn.good())
	{
		string word;
		dictIn>>word;
		if(word.size()==id.size())
		{
			bool equal=true;
			for(int j=0;j<word.size();j++)
			{

				if(table[word[j]-'A']!=id[j])
				{
					equal=false;
					break;
				}
			}

			if(equal)
			{
				out<<word<<endl;
				none=false;
			}
		}
	}
	if(none)
		out<<"NONE"<<endl;
	out.close();
	return 0;

}
