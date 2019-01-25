#include <stdio.h>

int N;
int K;
int a[10][2];
int t[4][4] = {
	1, 2, 3, 4,
	4, 1, 2, 3,
	3, 4, 1, 2,
	2, 3, 4, 1
};


int find(int k);

int main(void)
{
	int T;
	freopen("Text.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d %d", &N, &K);
		a[0][0] = 1;
		a[0][1] = 1;
		for (int i = 1; i <=K; i++)
		{
			scanf("%d %d", &a[i][0], &a[i][1]); // [][0] row, [][1] column

		}
		printf("#%d %d\n", tc, find(K));
	}
}

int find(int k)
{
	int dir = 0;
	int pos = 0;
	int cnt = 0; 
	for (int i = 0; i < k; i++)
	{
		if (a[i][0] < a[i+1][0] && a[i][1] < a[i+1][1]) // 다음 숫자가 오른쪽 아래
		{
			pos = 0;
		}
		else if (a[i][0] < a[i+1][0] && a[i+1][1] < a[i][1]) // 다음 숫자가 왼쪽 아래
		{
			pos = 1;
		}
		else if (a[i+1][0] < a[i][0] && a[i+1][1] < a[i][1]) // 다음 숫자가 왼쪽 위
		{
			pos = 2;
		}
		else if (a[i+1][0] < a[i][0] && a[i][1] < a[i+1][1]) // 다음 숫자가 오른쪽 위
		{
			pos = 3;
		}

		cnt += t[dir][pos];
		dir = (dir + t[dir][pos]) % 4;

	}
	return cnt;
}
