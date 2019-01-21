/*
5 6
1 2 1 3 3 2 2 5 3 4 5 4
*/

#include <stdio.h>
int V;
int E;
int adj[6][6];
int visited[6];

void dfs(int n);

int main(void) 
{
	scanf("%d %d", &V, &E);
	for(int i = 0; i < E; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = 1;
		// adj[n2][n1] = 1; // 방향성이 없는 경우 
	}
	dfs(1); 
	return 0;
}

void dfs(int n)
{
	visited[n] = 1; //처리됨 표시
	printf("%d ", n);
	for(int i = 1; i <= V; i++) // n과 인접한 노드 i에 대해
	{
		if((adj[n][i] != 0) && (visited[i] == 0)) //방문하지 않은 노드면
			dfs(i); // i노드로 이동 
	} 
}
