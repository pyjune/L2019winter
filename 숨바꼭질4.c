#include <stdio.h>
int v[100001];
int q[100001];
int f=-1;
int r=-1;
int find(int n,int m);

int from[100001];
int stack[100001];
int top = -1;

int main(void)
{
	int n,m;
	scanf("%d %d", &n,&m);
    printf("%d\n" ,find(n,m));
 	while(m!=-1)
 	{
 		stack[++top] = m;
		m =	from[m];
	}
	while(top > -1)
	{
		printf("%d ", stack[top--]);
	}
 	printf("\n");
}
int find(int n,int m)
{
	
	q[++r] = n;
	v[n] = 1;
	from[n] = -1;
	while(f != r)
	{
		int t = q[++f];
		
		if(t == m)
		    return v[t]-1;

		if(t*2<=100000 && v[t*2]==0)
        {					
			q[++r] = 2*t;
			v[2*t] = v[t]+1;
			from[2*t] = t;
		}
			
		if(t>0 && v[t-1]==0)
		{
			q[++r] = t-1;
			v[t-1] = v[t]+1;
			from[t-1] = t;
		}
		if(t<100000 && v[t+1]==0)
		{
			q[++r]=t+1;
			v[t+1]=v[t]+1;
			from[t+1] = t;
		}

	}
}
