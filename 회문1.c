#include <stdio.h>

char str[100][101]; // 최대 길이가 100인 문자열을 최대 100개 저장 

void find(int N, int M);
int main(int argc, char *argv[]) {
	
	int tc, T;
	int N, M;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(tc=1;tc<=T;tc++)
	{
		scanf("%d %d", &N, &M);
		for(int i=0;i<N;i++)
		{
			scanf("%s", str[i]); // 각 문자열을 저장할 주소 
			//printf("%s\n", str[i]); // 입력 확인 
		}
		printf("#%d ", tc);
		find(N, M);
	}
	return 0;
}

void find(int N, int M)
{
	int i, j, k;
	for(i=0;i<N;i++) // row 또는 col 
	{
		for(j=0;j<=N-M;j++) // 회문을 검사하는 첫 글자.. 
		{
			for(k=0;k<M/2;k++) // 가로방향 
			{
				if(str[i][j+k]!=str[i][j+M-1-k])
					break;
			}
			if(k==M/2) // 회문 발견..
			{
			// str[i][j]에서부터 M개의 글자를 출력 후return..
				for(k=0;k<M;k++)
					printf("%c", str[i][j+k]);
				printf("\n");
				return;
			}
			for(k=0;k<M/2;k++)// 세로방향 
			{
				if(str[j+k][i]!=str[j+M-1-k][i])
					break;
			}
			if(k==M/2) // 회문 발견..
			{
			// str[j][i]에서부터 M개의 글자를 출력 후return..
				for(k=0;k<M;k++)
					printf("%c", str[j+k][i]);
				printf("\n");
				return;
			}	
		}
	}
}
