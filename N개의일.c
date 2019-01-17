#include <stdio.h>

int p[10];
int used[10];
int t[10][10];
int minV;

void find(int n, int k);

int main(void) 
{
	int T;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		int N;
		minV = 100;
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				scanf("%d", &t[i][j]);
			}
		}
		find(0, N);
		printf("#%d %d\n", tc, minV);
	}
	
	return 0;
}

void find(int n, int k)
{
	if(n == k)
	{
		int s = 0;
		for(int i = 0; i < k; i++)
			s += t[p[i]][i];
		if(minV > s)
			minV = s;
	}
	else
	{
		for(int i = 0; i < k; i++)
		{
			if(used[i] == 0)
			{
				used[i] = 1;
				p[n] = i;
				find(n + 1, k);
				used[i] = 0;
			}
		}
	}
}
