#include <stdio.h>

int A[] = {1,2,3};
int L[3];
void f(int n, int k);

int main(void) 
{
	f(0, 3);
	return 0;
}

void f(int n, int k)
{
	if(n == k)
	{
		for(int i = 0; i < k; i++)
		{
			if( L[i] == 1)
				printf("%d", A[i]);
		}
		printf("\n");
	}
	else
	{
		L[n] = 0;
		f(n + 1, k);
		L[n] = 1;
		f(n + 1, k);
	}
}
