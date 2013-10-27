/*
LANG:C++
TASK:beads
*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
typedef struct{
	int left;
	int right;
}node;
int find(const string&necklace,int start,int n,bool forward)
{
	int count=0;
	int i=0;
	int state=0;
	while(i<n)
	{
		int index=(n+start)%n;
		char c=necklace[index];
		switch(state)
		{
			case 0:
				if(c=='r')
				{
					state=1;
				}else if(c=='b')
				{
					state=2;
				}
				count++;
				break;
			case 1:
				if(c=='b')
				{
					return count;
				}else{
					count++;
				}
				break;
			case 2:
				if(c=='r')
				{
					return count;
				}else{
					count++;
				}
		}

		if(forward)
			start++;
		else
			start--;
		i++;
	}
	return count;
}

int main(int argc,char** argv)
{
	ifstream in("beads.in");
	ofstream out("beads.out");
	int n;
	string necklace;
	in>>n;
	in>>necklace;
	int max=0;
	node* counts=new node[n];
	for(int i=0;i<n;i++)
	{
		counts[i].left=-1;
		counts[i].right=-1;
	}
	for(int i=0;i<n;i++)
	{
		if(counts[i].left==-1)
		{
			counts[i].left=find(necklace,i-1,n,false);			
			counsts[(i-counts[i].left+n)%n].right=counts[i].left;
		}
		if(counts[i].right==-1)
		{
			counts[i].right=find(necklace,i,n,true);
			counts[i+counts[i].right-1].left=counts[i].right;
		}
		int current=counts[i].left+counts[i].right;
		if(current>max)
			max=current;
	}	
	if(max>n)
		max=n;
	out<<max<<endl;
	in.close();
	out.close();
	return 0;
}
