#include <stdio.h>

int box[1000][1000];
int v[1000][1000];


int q[2000000];

int bfs(int M, int N);
int bfs2(int M, int N, int cnt);

int main(void) 
{
	int M;
	int N;
	int cnt = 0;
	scanf("%d %d", &M, &N);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			scanf("%d", &box[i][j]);
			if(box[i][j] == 0)
				cnt++;
		}
	}
	//printf("%d\n", bfs(M, N));
	printf("%d\n", bfs2(M, N, cnt));
	
	return 0;
}

int bfs2(int M, int N, int cnt)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	int last = 0;
	int front = -1;
	int rear = -1;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(box[i][j] == 1) // 익은 토마토의 위치 
			{
				q[++rear] = i;
				q[++rear] = j;
				v[i][j] = 1;
			}
		}
	}
	while(front != rear)
	{
		int r = q[++front];
		int c = q[++front];
		for(int k = 0; k < 4; k++)
		{
			int nr = r + dr[k];
			int nc = c + dc[k];
			if(nr>=0 && nr<N && nc>=0 && nc<M)
			{
				if(box[nr][nc] == 0 && v[nr][nc] == 0)
				{
					cnt--;
					q[++rear] = nr;
					q[++rear] = nc;
					v[nr][nc] = v[r][c] + 1;
					last = v[r][c];
				}
			}
		}
	}
	if(cnt>0)
		return -1;
	else
		return last;
	
}

int bfs(int M, int N)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	
	int front = -1;
	int rear = -1;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(box[i][j] == 1) // 익은 토마토의 위치 
			{
				q[++rear] = i;
				q[++rear] = j;
				v[i][j] = 1;
			}
		}
	}
	while(front != rear)
	{
		int r = q[++front];
		int c = q[++front];
		for(int k = 0; k < 4; k++)
		{
			int nr = r + dr[k];
			int nc = c + dc[k];
			if(nr>=0 && nr<N && nc>=0 && nc<M)
			{
				if(box[nr][nc] == 0 && v[nr][nc] == 0)
				{
					q[++rear] = nr;
					q[++rear] = nc;
					v[nr][nc] = v[r][c] + 1;
				}
			}
		}
	}
	int maxV = 0;
	for(int i = 0; i < N; i++)
	{ 
		for(int j = 0; j < M; j++)
		{
			if((box[i][j] == 0 && v[i][j] == 0))
				return -1; // 안익은 토마토가 남은 경우
			if(maxV < v[i][j])
				maxV = v[i][j];
		}
	}
	return (maxV - 1);
	
}
