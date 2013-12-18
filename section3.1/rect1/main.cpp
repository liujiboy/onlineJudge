/*
LANG:C++
TASK:rect1
*/
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
#include <cctype>
#include <set>
using namespace std;
ifstream fin("rect1.in");
ofstream fout("rect1.out");
int a,b,n;
class rect{
public:
	int llx, lly, urx, ury, color;
	rect(int llx=0,int lly=0,int urx=0,int ury=0,int color=1)
	{
		this->llx=llx;
		this->lly=lly;
		this->urx=urx;
		this->ury=ury;
		this->color=color;
	}
};
ostream&operator<<(ostream&out,const rect&r)
{
	out<<"("<<r.llx<<","<<r.lly<<","<<r.urx<<","<<r.ury<<","<<r.color<<")";
	return out;
}
void intersect(const rect&r1,const rect&r2,vector<rect>& newRect)
{
	bool c1=r2.llx<=r1.urx&&r2.llx>=r1.llx&&r2.lly<=r1.ury&&r2.lly>=r1.lly;
	bool c2=r2.urx<=r1.urx&&r2.urx>=r1.llx&&r2.lly<=r1.ury&&r2.lly>=r1.lly;
	bool c3=r2.urx<=r1.urx&&r2.urx>=r1.llx&&r2.ury<=r1.ury&&r2.ury>=r1.lly;
	bool c4=r2.llx<=r1.urx&&r2.llx>=r1.llx&&r2.ury<=r1.ury&&r2.ury>=r1.lly;
	if(!c1&&!c2&&!c3&&!c4)
	{
		bool c5=r1.llx<=r2.urx&&r1.llx>=r2.llx&&r1.lly<=r2.ury&&r1.lly>=r2.lly;
		bool c6=r1.urx<=r2.urx&&r1.urx>=r2.llx&&r1.lly<=r2.ury&&r1.lly>=r2.lly;
		bool c7=r1.urx<=r2.urx&&r1.urx>=r2.llx&&r1.ury<=r2.ury&&r1.ury>=r2.lly;
		bool c8=r1.llx<=r2.urx&&r1.llx>=r2.llx&&r1.ury<=r2.ury&&r1.ury>=r2.lly;
		if(!c5&&!c6&&!c7&&!c8)
		{
			if(r1.lly>=r2.lly&&r1.ury<=r2.ury&&r2.llx>=r1.llx&&r2.urx<=r1.urx)
			{
				if(r1.ury+1<=r2.ury)
					newRect.push_back(rect(r2.llx,r1.ury+1,r2.urx,r2.ury,r2.color));
				if(r1.lly-1>=r2.lly)
					newRect.push_back(rect(r2.llx,r2.lly,r2.urx,r1.lly-1,r2.color));
			}else if(r1.llx>=r2.llx&&r1.urx<=r2.urx&&r2.lly>=r1.lly&&r2.ury<=r1.ury)
			{
				if(r1.llx-1>=r2.llx)
					newRect.push_back(rect(r2.llx,r2.lly,r1.llx-1,r2.ury,r2.color));
				if(r1.urx+1<=r2.urx)
					newRect.push_back(rect(r1.urx+1,r2.lly,r2.urx,r2.ury,r2.color));
			}else
			{
				newRect.push_back(r2);
			}
		}else if(c5&&c6&&c7&&c8)
		{
			if(r1.lly-1>=r2.lly)
				newRect.push_back(rect(r2.llx,r2.lly,r2.urx,r1.lly-1,r2.color));
			if(r1.llx-1>=r2.llx)
				newRect.push_back(rect(r2.llx,r1.lly,r1.llx-1,r2.ury,r2.color));
			if(r1.ury+1<=r2.ury)
				newRect.push_back(rect(r1.llx,r1.ury+1,r1.urx,r2.ury,r2.color));
			if(r1.urx+1<=r2.urx)
				newRect.push_back(rect(r1.urx+1,r1.lly,r2.urx,r2.ury,r2.color));
		}else if(c5&&c6)
		{
			if(r1.llx-1>=r2.llx)
				newRect.push_back(rect(r2.llx,r2.lly,r1.llx-1,r2.ury,r2.color));
			if(r1.lly-1>=r2.lly)
				newRect.push_back(rect(r1.llx,r2.lly,r1.urx,r1.lly-1,r2.color));
			if(r1.urx+1<=r2.urx)
				newRect.push_back(rect(r1.urx+1,r2.lly,r2.urx,r2.ury,r2.color));
		}else if(c6&&c7)
		{
			if(r1.lly-1>=r2.lly)
				newRect.push_back(rect(r2.llx,r2.lly,r2.urx,r1.lly-1,r2.color));
			if(r1.urx+1<=r2.urx)
				newRect.push_back(rect(r1.urx+1,r1.lly,r2.urx,r1.ury,r2.color));
			if(r1.ury+1<=r2.ury)
				newRect.push_back(rect(r2.llx,r1.ury+1,r2.urx,r2.ury,r2.color));
		}else if(c7&&c8)
		{
			if(r1.llx-1>=r2.llx)
				newRect.push_back(rect(r2.llx,r2.lly,r1.llx-1,r2.ury,r2.color));
			if(r1.ury+1<=r2.ury)
				newRect.push_back(rect(r1.llx,r1.ury+1,r1.urx,r2.ury,r2.color));
			if(r1.urx+1<=r2.urx)
				newRect.push_back(rect(r1.urx+1,r2.lly,r2.urx,r2.ury,r2.color));
		}else if(c5&&c8)
		{
			if(r1.lly-1>=r2.lly)
				newRect.push_back(rect(r2.llx,r2.lly,r2.urx,r1.lly-1,r2.color));
			if(r1.llx-1>=r2.llx)
				newRect.push_back(rect(r2.llx,r1.lly,r1.llx-1,r1.ury,r2.color));
			if(r1.ury+1<=r2.ury)
				newRect.push_back(rect(r2.llx,r1.ury+1,r2.urx,r2.ury,r2.color));
		}
	}else if(c1&&c2&&c3&&c4)
	{
		//r2 in r1
	}
	else if(c1&&c2)
	{
		if(r1.ury+1<=r2.ury)
			newRect.push_back(rect(r2.llx,r1.ury+1,r2.urx,r2.ury,r2.color));
	}else if(c2&&c3)
	{
		if(r1.llx-1>=r2.llx)
			newRect.push_back(rect(r2.llx,r2.lly,r1.llx-1,r2.ury,r2.color));
	}else if(c3&&c4)
	{
		if(r1.lly-1>=r2.lly)
			newRect.push_back(rect(r2.llx,r2.lly,r2.urx,r1.lly-1,r2.color));
	}else if(c1&&c4)
	{
		if(r1.urx+1<=r2.urx)
			newRect.push_back(rect(r1.urx+1,r2.lly,r2.urx,r2.ury,r2.color));
	}else if(c1)
	{
		if(r1.urx+1<=r2.urx)
			newRect.push_back(rect(r1.urx+1,r2.lly,r2.urx,r1.ury,r2.color));
		if(r1.ury+1<=r2.ury)
			newRect.push_back(rect(r2.llx,r1.ury+1,r2.urx,r2.ury,r2.color));
	}else if(c2)
	{
		if(r1.llx-1>=r2.llx)
			newRect.push_back(rect(r2.llx,r2.lly,r1.llx-1,r1.ury,r2.color));
		if(r1.ury+1<=r2.ury)
			newRect.push_back(rect(r2.llx,r1.ury+1,r2.urx,r2.ury,r2.color));
	}else if(c3)
	{
		if(r1.lly-1>=r2.lly)
			newRect.push_back(rect(r2.llx,r2.lly,r2.urx,r1.lly-1,r2.color));
		if(r1.llx-1>=r2.llx)
			newRect.push_back(rect(r2.llx,r1.lly,r1.llx-1,r2.ury,r2.color));
	}else if(c4)
	{
		if(r1.lly-1>=r2.lly)
			newRect.push_back(rect(r2.llx,r2.lly,r2.urx,r1.lly-1,r2.color));
		if(r1.urx+1<=r2.urx)
			newRect.push_back(rect(r1.urx+1,r1.lly,r2.urx,r2.ury,r2.color));
	}

}
vector<rect> *rects=new vector<rect>();
int color[2501];
int main() {
	fin>>a>>b>>n;
	rects->push_back(rect(0,0,a-1,b-1,1));
	for(int i=0;i<n;i++)
	{
		rect r;
		fin>>r.llx>>r.lly>>r.urx>>r.ury>>r.color;
		r.urx=r.urx-1;
		r.ury=r.ury-1;
		vector<rect> *newRects=new vector<rect>();
		for(int i=0;i<rects->size();i++)
		{
			rect r1=rects->at(i);
			intersect(r,r1,*newRects);
			/*cout<<"r:"<<r<<endl;
			cout<<"r1:"<<r1<<endl;
			for(int j=0;j<newRects->size();j++)
			{
				cout<<newRects->at(j)<<endl;
			}
			cin.get();*/
		}
		delete rects;
		rects=newRects;
		rects->push_back(r);
		/*cout<<"rects"<<endl;
		int paper[20][20];
		for(int i=0;i<20;i++)
			for(int j=0;j<20;j++)
				paper[i][j]=0;
		for(int i=0;i<rects->size();i++)
		{
			rect r=rects->at(i);
			cout<<r<<endl;
			for(int x=r.llx;x<=r.urx;x++)
				for(int y=r.lly;y<=r.ury;y++)
				{
					if(r.color==1)
						paper[x][19-y]=r.color;
				}
		}
		for(int y=0;y<20;y++)
		{
			for(int x=0;x<20;x++)
			{
				cout<<paper[x][y]<<" ";
			}
			cout<<endl;
		}
		cin.get();*/
	}
	for(int i=0;i<rects->size();i++)
	{
		rect r=rects->at(i);
		//cout<<r<<endl;
		color[r.color]+=(r.urx-r.llx+1)*(r.ury-r.lly+1);
	}
	for(int i=0;i<=2500;i++)
	{
		if(color[i]!=0)
			fout<<i<<" "<<color[i]<<endl;
	}
	fin.close();
	fout.close();
	/*rect r2(0,0,19,1,1);
	rect r1(0,8,18,18,3);
	vector<rect> newRects;
	intersect(r1,r2,newRects);
	for(int i=0;i<newRects.size();i++)
	{
		cout<<newRects[i]<<endl;
	}*/
	return 0;
}
