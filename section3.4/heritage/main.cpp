/*
LANG:C++
TASK:heritage
*/
#include <list>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <map>
#include <cctype>
#include <stack>
#include <algorithm>
using namespace std;
ifstream fin("heritage.in");
ofstream fout("heritage.out");
struct node{
	string s;
	int left;
	int right;
};
node tree[26];
string preorder;
int len=1;
bool search(int index,char c)
{
	node&n=tree[index];
	for(int i=0;i<n.s.size();i++)
	{
		if(n.s[i]==c)
		{
			if(n.s.size()==1)
				return true;
			string ls=n.s.substr(0,i);
			string rs=n.s.substr(i+1);
			if(ls!="")
			{
				tree[len].s=ls;
				n.left=len;
				len++;
			}
			if(rs!="")
			{
				tree[len].s=rs;
				n.right=len;
				len++;
			}
			n.s=n.s.substr(i,1);
			return true;
		}
	}
	if(n.left!=0)
	{
		if(search(n.left,c))
			return true;
	}
	if(n.right!=0)
	{
		if(search(n.right,c))
			return true;
	}
	return false;
}
void postorder(int index)
{
	node&n=tree[index];
	if(n.left!=0)
		postorder(n.left);
	if(n.right!=0)
		postorder(n.right);
	fout<<n.s;
}
int main() {
	fin>>tree[0].s;
	fin>>preorder;
	for(int i=0;i<preorder.size();i++)
	{
		char c=preorder[i];
		search(0,c);
	}
	/*for(int i=0;i<len;i++)
	{
		cout<<i<<" "<<tree[i].s<<" "<<tree[i].left<<" "<<tree[i].right<<endl;
	}*/
	postorder(0);
	fout<<endl;
	fin.close();
	fout.close();
	return 0;
}
