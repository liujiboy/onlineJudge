/*
LANG:C++
TASK:transform
*/
#include<iostream>
#include<fstream>
using namespace std;
inline char* readSquare(istream&in,int n)
{
	char* p=new char[n*n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			in>>p[i*n+j];
	}
	return p;
}
inline void printSquare(char*p,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<p[i*n+j];
		}
		cout<<endl;
	}
}
inline bool equal(char*p1,char*p2,int n)
{
	for(int i=0;i<n*n;i++)
	{
		if(p1[i]!=p2[i])
			return false;
	}
	return true;
}
inline void rotate90(char*& src,char*& dest,int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			dest[j*n-i+n-1]=src[i*n+j];
		}
}
inline void rotate180(char*& src,char*& dest,int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			dest[-i*n+n*n-j-1]=src[i*n+j];
			//dest[(-i+n-1)*n-j+n-1]=src[i*n+j];
		}
}
inline void rotate270(char*& src,char*& dest,int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			dest[-j*n+n*n+i-n]=src[i*n+j];
			//dest[(-j+n-1)*n-(-i+n-1)+n-1]=src[i*n+j];
		}
}
inline void mirror(char*& src,char*& dest,int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			dest[i*n-j+n-1]=src[i*n+j];
		}

}
int main(int argc,char** argv)
{
	ifstream in("transform.in");
	ofstream out("transform.out");
	int n;
	in>>n;
	char *p1=readSquare(in,n);
	char *p2=readSquare(in,n);
	char *p3=new char[n*n];
	int type=7;
	rotate90(p1,p3,n);
	if(equal(p3,p2,n))
	{
		type=1;
	}
	else
	{
		rotate180(p1,p3,n);
		if(equal(p3,p2,n))
			type=2;
		else
		{
			rotate270(p1,p3,n);
			if(equal(p3,p2,n))
				type=3;
			else
			{
				mirror(p1,p3,n);
				if(equal(p3,p2,n))
					type=4;
				else
				{
					char* p4=new char[n*n];
					rotate90(p3,p4,n);
					if(equal(p4,p2,n))
					{
						type=5;
					}else
					{
						rotate180(p3,p4,n);
						if(equal(p4,p2,n))
							type=5;
						else
						{
							rotate270(p3,p4,n);
							if(equal(p4,p2,n))
								type=5;
						}
					}
					delete []p4;
				}
			}
		}
	}
	if(type==7)
	{
		if(equal(p1,p2,n))
			type=6;
	}
	delete []p3;
	delete []p2;
	delete []p1;
	out<<type<<endl;
	return 0;
}
