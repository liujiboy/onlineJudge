/*
LANG:C++
TASK:beads
*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(int argc,char** argv)
{
	ifstream in("beads.in");
	ofstream out("beads.out");
	int n;
	string necklace;
	in>>n;
	in>>necklace;
	necklace+=necklace;
	int m=0;
	int **left=new int*[2*n];
	int **right=new int*[2*n];
	for(int i=0;i<2*n+1;i++)
	{
		left[i]=new int[2];
		right[i]=new int[2];
	}
	left[0][0]=0;
	left[0][1]=0;
	for(int i=1;i<2*n;i++)
	{
		char c=necklace[i-1];
		switch(c)
		{
			case 'r':
				left[i][0]=left[i-1][0]+1;
				left[i][1]=0;
				break;
			case 'b':
				left[i][0]=0;
				left[i][1]=left[i-1][1]+1;
				break;
			case 'w':
				left[i][0]=left[i-1][0]+1;
				left[i][1]=left[i-1][1]+1;
				break;
		}
	}
	if(necklace[2*n-1]=='r')
	{
		right[2*n-1][0]=1;
		right[2*n-1][1]=0;
	}else if(necklace[2*n-1]=='b')
	{
		right[2*n-1][0]=0;
		right[2*n-1][1]=1;
	}else
	{	
		right[2*n-1][0]=1;
		right[2*n-1][1]=1;
	}
	for(int i=2*n-2;i>=0;i--)
	{
		char c=necklace[i];
		switch(c)
		{
			case 'r':
				right[i][0]=right[i+1][0]+1;
				right[i][1]=0;
				break;
			case 'b':
				right[i][0]=0;
				right[i][1]=right[i+1][1]+1;
				break;
			case 'w':
				right[i][0]=right[i+1][0]+1;
				right[i][1]=right[i+1][1]+1;
				break;
		}

	}
	for(int i=0;i<2*n;i++)
	{
		cout<<"r"<<right[i][0]<<endl;
		cout<<"b"<<right[i][1]<<endl;
	}
	for(int i=0;i<2*n;i++)
	{
		int current=max(left[i][0],left[i][1])+max(right[i][0],right[i][1]);
		m=max(current,m);
	}
	if(m>n)
		m=n;
	out<<m<<endl;
	in.close();
	out.close();
	return 0;
}
