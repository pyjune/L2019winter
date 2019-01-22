#include <stdio.h>

int maze[100][100];
int N;

int find(int r, int c);

int main(void) 
{
	freopen("input.txt", "r", stdin);
	int T;
	int sr, sc;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				scanf("%1d", &maze[i][j]);
				if(maze[i][j] == 2)
				{
					sr = i;
					sc = j;
				}
			}
		}
		printf("#%d %d\n", tc, find(sr, sc));
	}

	return 0;
}

int find(int r, int c)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	
	if(maze[r][c] == 3) // 목적지 도착 
	{
		return 1;
	}
//	else if(maze[r][c] == 1) // 벽이면 리턴 (진입 후 검사) 
//		return 0;
	else
	{
		maze[r][c] = 1; // 지나간 칸 표시 
		for(int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(maze[nr][nc] != 1) // 벽이 아니면 (진입 전 검사) 
				if(find(nr, nc) == 1)
					return 1; 
		}
		return 0;
	}
}
