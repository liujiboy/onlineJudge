/*
LANG:C++
TASK:namenum
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
/*void print(const map<char,vector<string> >::value_type& it )
{
	cout<<it.first<<endl;
	for(vector<string>::const_iterator i=it.second.begin();i!=it.second.end();i++)
			cout<<*i<<" ";
	cout<<endl;
		//<<" "<<it.second<<endl;
}*/
bool cmp(string i,string j)
{
	return i<j;
}
int main(int argc,char** argv)
{
	ifstream in("namenum.in");
	ifstream dictIn("dict.txt");
	ofstream out("namenum.out");
	string id;
	in>>id;
	map<char,vector<string> > dict;
	while(dictIn.good())
	{
		string word;
		dictIn>>word;
		dict[word[0]].push_back(word);
	}
	string letters[8][3]={{"A","B","C"},{"D","E","F"},{"G","H","I"},{"J","K","L"},{"M","N","O"},{"P","R","S"},{"T","U","V"},{"W","X","Y"}};
	vector<string>* names=new vector<string>();
	for(int i=0;i<id.length();i++)
	{
		vector<string> *temp=new vector<string>();
		int index=id[i]-'2';
		for(int j=0;j<3;j++)
		{
			if(i==0)
				temp->push_back(letters[index][j]);
			else{
				for(int k=0;k<names->size();k++)
				{	
					string newname=(*names)[k]+letters[index][j];
					temp->push_back(newname);
				}
			}
		}
		delete names;
		names=temp;
	}
	vector<string> valids;
	for(int i=0;i<names->size();i++)
	{
		vector<string> words=dict[(*names)[i][0]];
		if(binary_search(words.begin(),words.end(),(*names)[i]))
			valids.push_back((*names)[i]);

	}
	if(valids.size()==0)
		out<<"NONE"<<endl;
	else
	{
		sort(valids.begin(),valids.end(),cmp);
		for(int i=0;i<valids.size();i++)
		{
			out<<valids[i]<<endl;
		}
	}
	dictIn.close();
	return 0;
}
