#include <stdio.h>

int maze[100][100];
int N;
int cnt;
int minV;

void find(int r, int c);

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
//		cnt = 0;
//		find(sr, sc);
//		printf("#%d %d\n", tc, cnt);
		minV = 10000;
		find2(sr, sc, 0);
		if(minV==10000)
			minV = 1;
		printf("#%d %d\n", tc, minV-1);
	}

	return 0;
}
// 최단 거리(출발, 도착 칸 제외) 
void find2(int r, int c, int e)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	
	if(maze[r][c] == 3) // 목적지 도착 
	{
		if(minV > e)
			minV = e;
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
				find2(nr, nc, e+1);
		}
		maze[r][c] = 0; // 
	}
}

// 경로의  수 
void find(int r, int c)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	
	if(maze[r][c] == 3) // 목적지 도착 
	{
		cnt++;
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
				find(nr, nc);
		}
		maze[r][c] = 0; // 
	}
}
