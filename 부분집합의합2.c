#include <stdio.h>

int L[20];
void f(int n, int k);
int N;
int X;
int cnt;
void f(int n, int k);
void f2(int n, int k, int s);
int cnt2;
int main(void) 
{
	int T;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		cnt = 0;
		cnt2 = 0;
		scanf("%d %d", &N, &X);
		f(0, N);
		//f2(0, N, 0);
		printf("#%d %d %d\n", tc, cnt, cnt2);
	}

	return 0;
}
void f2(int n, int k, int s)
{
	cnt2++;
	if(s == X)
		cnt++;
	else if(n == k)
		return;
	else
	{
		f2(n + 1, k, s);
		f2(n + 1, k, s+n+1); // A[n]을 포함하는 경 
	}
}
void f(int n, int k)
{
	cnt2++;
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
