/*
5 6
1 2 1 3 3 2 2 5 3 4 5 4
*/

#include <stdio.h>

int q[5];
int front = -1;
int rear = -1;

void bfs(int n);

int V;
int E;
int adj[6][6];
int visited[6];

int bfs3(int n, int k); // n->k 최단거리..
 
int main(void) {
	scanf("%d %d", &V, &E);
	for(int i = 0; i < E; i++)
	{
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = 1;
		//adj[n2][n1] = 1; // 방향성이 없는 경우 
	}	
	//bfs(1);
	//for(int i = 1; i <= V; i++)
	//	printf("%d ", visited[i]);
	//printf("1->4 최단거리 : %d", visited[4] - 1);
	printf("%d\n", bfs3(5, 3));
	return 0;
}

// n->k 최단거리... 
int bfs3(int n, int k)
{
	q[++rear] = n; // enqueue(n)
	visited[n] = 1;
	while(front != rear) // while(q_is_not_empty())
	{
		n = q[++front]; // n = dequeue()
		if(n == k)
		{
			return (visited[n] - 1);
		} 
		for(int i = 1; i <= V; i++)
		{
			if((adj[n][i] != 0) && (visited[i] == 0))
			{
				q[++rear] = i; // enqueue(i)
				visited[i] = visited[n] + 1;
			}
		}
	}
	return 0;
}

void bfs(int n)
{
	q[++rear] = n; // enqueue(n)
	visited[n] = 1;
	while(front != rear) // while(q_is_not_empty())
	{
		n = q[++front]; // n = dequeue()
		for(int i = 1; i <= V; i++)
		{
			if((adj[n][i] != 0) && (visited[i] == 0))
			{
				q[++rear] = i; // enqueue(i)
				visited[i] = visited[n] + 1;
			}
		}
	}
}
