#include <stdio.h>

int map[25][25];
int visited[25][25];
int count[314]; // 단지별 세대 수, 단지가 최대 625/2개 만큼 생길 수 있음에 주의
int countIdx = 0; // 단지수 
int N;

void dfs(int r, int c);

int q[1250]; // 전체가 1단지인 경우 625*2 (세대수 * 가로, 세로 좌표)
void bfs(int r, int c);

int main(void) 
{
	
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(map[i][j]==1 && visited[i][j]==0)
			{
				countIdx++; // 단지 번호 
				//dfs(i, j);
				bfs(i, j);				
			}
		}
	}
	printf("%d\n", countIdx);
	for(int i = 1; i < countIdx; i++)
	{
		int minIdx = i;
		for(int j = i; j <= countIdx; j++)
		{
			if(count[minIdx]>count[j])
				minIdx = j;
		}
		int tmp = count[i];
		count[i] = count[minIdx];
		count[minIdx] = tmp;
	}
	for(int i = 1; i <= countIdx; i++)
		printf("%d\n", count[i]);
	return 0;
}

void dfs(int r, int c)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	
	visited[r][c] = 1;
	count[countIdx]++;
	for(int i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(nr>=0 && nr<N && nc>=0 && nc<N)
		{
			if(map[nr][nc]==1 && visited[nr][nc]==0)
				dfs(nr, nc);
		}
	}
}

void bfs(int r, int c)
{
	int dr[] = {0, 1, 0, -1};
	int dc[] = {1, 0, -1, 0};
	int front = -1;
	int rear = -1;
	q[++rear] = r;
	q[++rear] = c;
	visited[r][c] = 1;
	while(front != rear)
	{
		r = q[++front];
		c = q[++front];
		count[countIdx]++; 
		for(int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(nr>=0 && nr<N && nc>=0 && nc<N)
			{
				if(map[nr][nc]==1 && visited[nr][nc]==0)
				{
					q[++rear] = nr;
					q[++rear] = nc;
					visited[nr][nc] = visited[r][c] + 1;
				}
			}
		}
	}
}
