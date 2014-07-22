/*
LANG:C++
TASK:fence8
*/
#include<stdio.h>
#include<stdlib.h>
int v[55],wx[55],lwh[1111],ans=0,n,m,sumv=0,maxstep,space;
int minlwh[1111],pp,max1[55],l,r,mid;
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int cmp2(const void *a,const void *b)
{
	return -*(int *)a+*(int *)b;
}
int sou(int step,int pos)
{

	if(step<1)
		return 1;
	if(space>sumv-minlwh[mid])
		return 0;

	/*if(step>mid){
		return 0;
	}*/
	int i,j,k,f[1111]={0};
	for(i=n;i>=pos;i--)
	{

		if(v[i]>=lwh[step])
		{
			//if(f[v[i]]==1)continue;//此优化巨牛X，可惜空间太。。开个f[11111]
			//else f[v[i]]=1;
			v[i]-=lwh[step];
			if(v[i]<lwh[1])
				space+=v[i];
			int ok=0;
			if(lwh[step]==lwh[step-1])
			{
				ok=sou(step-1,i);
			}                               
			else
			{
			      	ok=sou(step-1,1);
			}
			if(v[i]<lwh[1])
				space-=v[i];
			v[i]+=lwh[step];
			if(ok==1)
				return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("fence8.in","r",stdin);
	freopen("fence8.out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&v[i]); 
		sumv+=v[i];
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++)
		scanf("%d",&lwh[i]);
	//while(sumv<minlwh[m])m--;
	qsort(&v[1],n,sizeof(v[1]),cmp);
	qsort(&lwh[1],m,sizeof(lwh[1]),cmp);
	for(i=1;i<=m;i++)
		minlwh[i]=minlwh[i-1]+lwh[i];
	l=0;r=m;mid=(l+r)/2;
	while(l<=r)
	{
		space=0;
		//for(i=1;i<=n;i++)
			//v[i]=v[i]; 
		if(sou(mid,1)==1)
			l=mid+1;
		else 
			r=mid-1;
		mid=(l+r)/2;
	}
	printf("%d\n",mid);
	return 0;
}
