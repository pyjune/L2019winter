#include <stdio.h>

int L[20];
void f(int n, int k);
int N;
int X;
int cnt;

int main(void) 
{
	int T;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		cnt = 0;
		scanf("%d %d", &N, &X);
		f(0, N);
		printf("#%d %d\n", tc, cnt);
	}

	return 0;
}

void f(int n, int k)
{
	if(n == k)
	{
		int s = 0;
		for(int i = 0; i < k; i++)
		{
			if( L[i] == 1)
				s += i+1;
		}
		if(s == X)
			cnt++;
	}
	else
	{
		L[n] = 0;
		f(n + 1, k);
		L[n] = 1;
		f(n + 1, k);
	}
}
