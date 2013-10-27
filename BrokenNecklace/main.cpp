/*
LANG:C++
TASK:beads
*/
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
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
	for(int i=0;i<n;i++)
	{
		int a=find(necklace,i,n,true);
		int b=find(necklace,i-1,n,false);
		if(a+b>max)
			max=a+b;
	}	
	if(max>n)
		max=n;
	out<<max<<endl;
	in.close();
	out.close();
	//bool removed[29];
	//cout<<find("wwwbbrwrbrbrrbrbrwrwwrbwrwrrb",removed,28,29,true)<<endl;
	//cout<<removed[0]<<" "<<removed[1]<<endl;
	//cout<<find("wwwbbrwrbrbrrbrbrwrwwrbwrwrrb",removed,27,29,false)<<endl;
	return 0;
}
