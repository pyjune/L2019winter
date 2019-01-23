#include <stdio.h>

int maze[100][100];
int visited[100][100];
int N;

int q[20000];
int front;
int rear;

int bfs(int r, int c);

main(void) 
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
		printf("#%d %d\n", tc, bfs(sr, sc)); // 도착여부 판단
		for(int i = 0; i < N; i++)
		{
			for(int j = 0 ; j < N; j++)
			{
				visited[i][j] = 0;
			}
		}
	}
}

int bfs(int r, int c)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	// 큐 생성 
	front = -1;
	rear = -1;
	// 시작점 인큐
	q[++rear] = r;
	q[++rear] = c;
	visited[r][c] = 1;
	
	while(front != rear) // 큐가 비워질 때까지 반복
	{
		r = q[++front];
		c = q[++front];
		if(maze[r][c] == 3) // 디큐한 칸이 목적지면 종료 
		{
			return 1;
		}
		// 인접하고 방문하지 않은 칸...
		for(int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(maze[nr][nc] != 1 && visited[nr][nc] == 0) // 이웃 칸이 벽이 아니면... 
			{
				q[++rear] = nr;
				q[++rear] = nc;
				visited[nr][nc] = visited[r][c] + 1;
			}	
		} 
	}
	return 0; 
}
