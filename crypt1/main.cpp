/*
LANG:C++
TASK:crypt1
*/
#include <fstream>
#include <iostream>
using namespace std;
bool test1(int n,bool* map)
{
	if(map[n%10]&&map[n/100%10]&&map[n/10%10]&&map[n/1000])
		return true;
	else
		return false;
}
bool test(int n,bool* map)
{
	if(map[n%10]&&map[n/100]&&map[n/10%10])
		return true;
	else
		return false;
}
int main() {
	ifstream fin ("crypt1.in");
	ofstream fout ("crypt1.out");
	int solution=0;
	int nums[10];
	bool map[10];
	for(int i=0;i<10;i++)
	{
		map[i]=false;
	}
	int n;
	fin>>n;
	for(int i=0;i<n;i++)
	{

		fin>>nums[i];
		map[nums[i]]=true;
	}
	for(int i1=0;i1<n;i1++)
	{
		int a=nums[i1];

		for(int i2=0;i2<n;i2++)
		{
			int b=nums[i2];
			for(int i3=0;i3<n;i3++)
			{
				int c=nums[i3];
				int n1=a*100+b*10+c;
				for(int i4=0;i4<n;i4++)
				{
					int e=nums[i4];
					int n3=n1*e;
					if(n3<=999&&test(n3,map))
					{
						for(int i5=0;i5<n;i5++)
						{
							int d=nums[i5];
							int n4=n1*d;
							if(n4<=999&&test(n4,map))
							{
								int n2=d*10+e;
								int n5=n1*n2;
								if(n5<=9999&&test1(n5,map))
								{
									solution++;

								}
							}

						}
					}
				}
			}
		}
	}
	fout<<solution<<endl;
	fin.close();
	fout.close();
	return 0;
}
