#include <stdio.h>

int A[3];

void f(int n, int k);
void f2(int n, int k, int m);

int main(void) 
{
	//f(0, 3);
	f2(0, 3, 5);
	return 0;
}

void f(int n, int k)
{
	if(n == k)
	{
		for(int i = 0; i < k; i++)
			printf("%d ", A[i]);
		printf("\n");
	}
	else
	{
		for(int i = 1; i <= 3; i++)
		{
			A[n] = i;
			f(n+1, k);
		}
	}
}

void f2(int n, int k, int m)
{
	if(n == k)
	{
		for(int i = 0; i < k; i++)
			printf("%d ", A[i]);
		printf("\n");
	}
	else
	{
		for(int i = 1; i <= m; i++)
		{
			A[n] = i;
			f2(n+1, k, m);
		}
	}
}
