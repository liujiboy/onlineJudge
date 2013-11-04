/*
LANG:C++
TASK:packrec
 */
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
#define N 4
#define M 2
typedef struct{
	int w;
	int h;
}rect;
rect rects[N][M];
void swap(int&a,int&b)
{
	int tmp=a;
	a=b;
	b=tmp;
}

class Result{
	private:
		rect rects[384];
		int len;
		int min;
	public:
		Result()
		{
			len=0;
			min=2147483647;
		}
		void insert(int m,int w,int h)
		{
			if(m>0)
			{
				if(w>h) swap(w,h);
				if(m==min)
				{
					bool insert=true;
					for(int i=0;i<len;i++)
					{
						if(rects[i].w==w)
						{
							insert=false;
							break;
						}
					}
					if(insert)
					{
						rects[len].w=w;
						rects[len].h=h;
						len++;
					}
				}
				if(m<min)
				{
					min=m;
					len=0;
					rects[len].w=w;
					rects[len].h=h;
					len++;
				}
			}
		}
		friend ostream&operator<<(ostream&out,Result&r);
};
Result re;
bool cmp(rect r1,rect r2)
{
	return r1.w<r2.w;
}
ostream&operator<<(ostream&out,Result&r)
{
	out<<r.min<<endl;
	sort(r.rects,r.rects+r.len,cmp);
	for(int i=0;i<r.len;i++)
	{
		out<<r.rects[i].w<<" "<<r.rects[i].h<<endl;
	}
	return out;
}
ostream&operator<<(ostream&out,rect r)
{
	out<<"("<<r.w<<","<<r.h<<")";
	return out;
}
int type1(rect r1,rect r2,rect r3,rect r4,int&w,int&h)
{
	w=r1.w+r2.w+r3.w+r4.w;
	h=r1.h>r2.h?r1.h:r2.h;
	h=h>r3.h?h:r3.h;
	h=h>r4.h?h:r4.h;
	return w*h;
}
int type2(rect r1,rect r2,rect r3,rect r4,int&w,int&h)
{
	if(r1.h>r2.h)
		return 0;
	if(r2.h>r3.h)
		return 0;
	if(r1.w+r2.w+r3.w>r4.h)
		return 0;
	w=r4.h;
	h=r3.h+r4.w;
	return w*h;
}
int type3(rect r1,rect r2,rect r3,rect r4,int&w,int&h)
{
	if(r4.h<r2.w)
		return 0;
	w=r1.w+r2.w+r3.w>r4.h+r3.w?r1.w+r2.w+r3.w:r4.h+r3.w;
	h=r1.h+r4.w>r2.h+r4.w?r1.h+r4.w:r2.h+r4.w;
	h=h>r3.h?h:r3.h;
	return w*h;
}
int type4(rect r1,rect r2,rect r3,rect r4,int&w,int&h)
{
	if(r1.h>r2.h+r3.h)
		return 0;
	if(r4.h>r2.h+r3.h)
		return 0;
	if(r2.w>r3.w)
		return 0;
	w=r1.w+r3.w+r4.w;
	h=r2.h+r3.h;
	return w*h;
}
int type5(rect r1,rect r2,rect r3,rect r4,int&w,int&h)
{
	if(r1.h+r2.h>r4.h)
		return 0;
	if(r3.h>r4.h)
		return 0;
	if(r1.w>r2.w)
		return 0;
	w=r2.w+r3.w+r4.w;
	h=r4.h;
	return w*h;
}
int type6(rect r1,rect r2,rect r3,rect r4,int&w,int&h)
{
	if(r1.h+r2.h>r3.w+r4.h)
		return 0;
	if(r3.h<r4.w)
		return 0;
	if(r1.w+r3.h>r2.w+r4.w)
		return 0;
	if(r1.w>r2.w)
		return 0;
	if(r2.h>r4.h)
		return 0;
	w=r2.w+r4.w;
	h=r3.w+r4.h;
	return w*h;
}
void perm(int* nums,int i,int j)
{
	if(i<j)
	{
		perm(nums,i+1,j);
		for(int k=i+1;k<=j;k++)
		{
			swap(nums[i],nums[k]);
			perm(nums,i+1,j);
			swap(nums[k],nums[i]);
		}
	}
	else
	{
		for(int i=0;i<2;i++)
		{
			rect r1=rects[nums[0]][i];
			for(int j=0;j<2;j++)
			{
				rect r2=rects[nums[1]][j];
				for(int k=0;k<2;k++)
				{
					rect r3=rects[nums[2]][k];
					for(int l=0;l<2;l++)
					{
						rect r4=rects[nums[3]][l];
						int w,h;
						int m=type1(r1,r2,r3,r4,w,h);
						cout<<"type1 "<<m<<" "<<w<<" "<<h<<" "<<r1<<r2<<r3<<r4<<endl;
						re.insert(m,w,h);
						m=type2(r1,r2,r3,r4,w,h);
						cout<<"type2 "<<m<<" "<<w<<" "<<h<<" "<<r1<<r2<<r3<<r4<<endl;
						re.insert(m,w,h);
						m=type3(r1,r2,r3,r4,w,h);
						cout<<"type3 "<<m<<" "<<w<<" "<<h<<" "<<r1<<r2<<r3<<r4<<endl;
						re.insert(m,w,h);
						m=type4(r1,r2,r3,r4,w,h);
						cout<<"type4 "<<m<<" "<<w<<" "<<h<<" "<<r1<<r2<<r3<<r4<<endl;
						re.insert(m,w,h);
						m=type5(r1,r2,r3,r4,w,h);
						cout<<"type5 "<<m<<" "<<w<<" "<<h<<" "<<r1<<r2<<r3<<r4<<endl;
						re.insert(m,w,h);
						m=type6(r1,r2,r3,r4,w,h);
						cout<<"type6 "<<m<<" "<<w<<" "<<h<<" "<<r1<<r2<<r3<<r4<<endl;
						re.insert(m,w,h);

					}
				}
			}
		}

	}
}
int main() {
	ifstream fin ("packrec.in");
	ofstream fout ("packrec.out");
	for(int i=0;i<N;i++)
	{
		fin>>rects[i][0].w>>rects[i][0].h;
		rects[i][1].w=rects[i][0].h;
		rects[i][1].h=rects[i][0].w;
	}
	int nums[N]={0,1,2,3};
	perm(nums,0,3);
	fout<<re;
	fin.close();
	fout.close();
	return 0;
}
