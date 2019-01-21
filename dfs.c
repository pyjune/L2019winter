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

int stack[5];
int top = -1;

void dfs2(int n);

int dfs3(int n, int k); // k번 노드에 도착할 수 있으면 1, 아니면 0 

int cnt;
void dfs4(int n, int k);

int main(void) 
{
	scanf("%d %d", &V, &E);
	for(int i = 0; i < E; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = 1;
		//adj[n2][n1] = 1; // 방향성이 없는 경우 
	}
	//dfs(1);
	//dfs2(1);
	//printf("%d\n", dfs3(5, 3));
	dfs4(1, 4);
	printf("%d\n", cnt);
	return 0;
}
// n에서 k로가는 경로의  수 
void dfs4(int n, int k)
{
	if(n == k) // 목적지 노드에 도착 
		cnt++;
	else
	{
		visited[n] = 1; // n번이후에 n번으로 진입 방지 
		for(int i = 1; i <= V; i++)
		{
			if((adj[n][i] != 0) && (visited[i] == 0))
			{
				dfs4(i, k);
			}
		}
		visited[n] = 0;	// n번 이전에서 n번으로 진입 허용 
	}
}

// n에서 k로 가는 경로가 존재하는지 확인 
int dfs3(int n, int k)
{
	if(n == k)
		return 1;
	else
	{
		visited[n] = 1;
		for(int i = 1; i <= V; i++)
		{
			if((adj[n][i] != 0) && (visited[i] == 0))
			{
				if(dfs3(i, k) == 1)
					return 1;
			}
		}
		return 0;
	}
}

void dfs2(int n)
{
	// 시작노드 push, 방문처리 
	stack[++top] = n; // push()
	visited[n] = 1;
	// 반복
	while(top != -1)
	{
		n = stack[top--]; 	// pop()
		printf("%d ", n);	// 노드번호 표시
		for(int i = 1; i <=V; i++)
		{
			if((adj[n][i] != 0) && (visited[i] == 0))
			{
				stack[++top] = i;
				visited[i] = 1;
			}
		}
	} 
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
