#include <stdio.h>
int v[100001];
int cnt[100001];
int q[100001];
int f=-1;
int r=-1;
int find(int n,int m);

int main(void)
{
	int n,m;
	scanf("%d %d", &n,&m);
    printf("%d\n" ,find(n,m));
 	
    printf("%d\n", cnt[m]);
}
int find(int n,int m)
{
	q[++r] = n;
	v[n] = 1;
	cnt[n] = 1;
	while(f != r)
	{
		int t = q[++f];
		if(t == m)
		    return v[t]-1;
		if(t>0)
		{
			if(v[t-1]==0)
			{
				q[++r] = t-1;
				v[t-1] = v[t]+1;
				cnt[t-1] = cnt[t];
			}
			else if(v[t-1] == v[t]+1)
			{
				cnt[t-1] += cnt[t];
			}
		}
		if(t<100000 )
		{
			if(v[t+1]==0)
			{
				q[++r]=t+1;
				v[t+1]=v[t]+1;
				cnt[t+1]=cnt[t];
			}
			else if(v[t+1]==v[t]+1)
			{
				cnt[t+1]+=cnt[t];
			}
		}
		if(2*t<=100000)
		{
			if(v[2*t]==0)
			{
				q[++r]=t*2;
				v[t*2]=v[t]+1;
				cnt[t*2]=cnt[t];
			}
			else if(v[2*t]==v[t]+1)
			{
				cnt[t*2]+=cnt[t];
			}
		}
	}
}
