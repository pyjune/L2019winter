#include <stdio.h>

int main(void) 
{
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	
	long long m[71][71];
	for(int i = 0; i<=70; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			if(i==j || j==0)
				m[i][j] = 1;
			else
				m[i][j] = m[i-1][j-1] + m[i-1][j];
		}
	}
	
	for(int tc = 1; tc <= T; tc++)
	{
		int n, a, b;
		scanf("%d %d %d", &n, &a, &b);
		printf("#%d %lld\n", tc, m[n][a]);
	}
	
	return 0;
}
