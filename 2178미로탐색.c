#include <stdio.h>

int maze[101][101];
int N;
int M;
int minV = 10000;

int visited[101][101];
int q[20000];


void find(int r, int c, int e);
int bfs(void);

int main(void) 
{
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++) // (1,1)~(N,M)까지.. 
	{
		for(int j = 1; j <= M; j++)
		{
			scanf("%1d", &maze[i][j]);
		}
	}
//	find(1, 1, 0);
//	printf("%d\n", minV);
	printf("%d\n", bfs());
	return 0;
}

int bfs(void)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	int front = -1;
	int rear = -1;
	// 시작점 enqueue, 방문표시
	q[++rear] = 1;
	q[++rear] = 1;
	visited[1][1] = 1;
	// 큐가 비어있지 않으면 반복
	while(front != rear)
	{
		int r = q[++front]; // 처리할 칸 dequeue 
		int c = q[++front];	
		if(r==N && c==M) // 목적지인 경우
		{
			return visited[N][M]; // 출발 도착 칸 포함	
		}
		for(int k = 0; k < 4; k++) // 인접하고 미방문인 칸 enqueue 
		{
			int nr = r + dr[k];
			int nc = c + dc[k];
			if(nr>=1 && nr<=N && nc>=1 && nc<=M)
			{
				if(maze[nr][nc]==1 && visited[nr][nc] == 0)
				{
					q[++rear] = nr;
					q[++rear] = nc;
					visited[nr][nc] = visited[r][c] + 1;
				}	
			}
		} 
	}
	return 0; 
}
// DFS는 시간 초과
void find(int r, int c, int e)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	if(r==N && c==M)
	{
		if(minV > e+1)
			minV = e + 1;
	}
//	else if(maze[r][c]==0)
//		return;
	else
	{
		maze[r][c] = 0;
		for(int k = 0; k < 4; k++)
		{
			int nr = r + dr[k];
			int nc = c + dc[k];
			if(nr>=1 && nr<=N && nc>=1 && nc<=M)
			{
				if(maze[nr][nc] == 1)
					find(nr, nc, e+1);
			}
		}
		maze[r][c] = 1;
	}
}
