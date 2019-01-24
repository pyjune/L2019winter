#include <stdio.h>

int map[8][8];


int N;
int M;

int maxV;
void wall(int n);
int bfs(void);

int main(void) 
{
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	wall(0);
	printf("%d\n", maxV);
	return 0;
}

int bfs(void)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	int q[1000];
	int virus[8][8] = {0,};
	int front = -1;
	int rear = -1;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j< M; j++)
		{
			if(map[i][j] == 2)
			{
				q[++rear] = i;
				q[++rear] = j;
				virus[i][j] = 1;
			}
		}
	}
	while(front != rear)
	{
		int r = q[++front];
		int c = q[++front];
		for(int i = 0; i<4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(nr>=0 && nr<N && nc>=0 && nc<M)
			{
				if(map[nr][nc]==0 && virus[nr][nc]==0)
				{
					q[++rear] = nr;
					q[++rear] = nc;
					virus[nr][nc] = 1;
				}
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j<M; j++)
		{
			if(map[i][j] == 0 && virus[i][j]==0)
				cnt++;
		}
	}
	return cnt;
	
}

void wall(int n)
{
	if(n == 3)
	{
		int r = bfs();
		if( maxV < r )
			maxV = r;
	}
	else
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				if(map[i][j] == 0)
				{
					map[i][j] = 1; 
					wall(n+1); // 벽을 세우고 진행
					map[i][j] = 0;
				}
			}
		}
		
	}
}
