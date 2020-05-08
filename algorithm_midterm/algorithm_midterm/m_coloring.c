#define _CRT_SECURE_NO_WARNINGS
#define N 4
#define M 3
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int vColor[N];
int W[N][N] = { {0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0} };

bool promising(int i)
{
	int j; bool change;

	change = true;
	j = 1;
	while (j < i && change)
	{
		if (W[i-1][j-1] && vColor[i] == vColor[j])
			change = false;
		j++;
	}
	return change;
}


void m_coloring(int i)
{
	int color;

	if (promising(i))
	{
		if (i == N)
		{
			
			for (int j = 1; j < N+1; j++)
			{
				printf("%d ", vColor[j]);
			}
			printf("\n");
		}
		else
		{
			for (color = 1; color <=M; color++)
			{
				vColor[i+1] = color;
				m_coloring(i+1);
			}
		}
	}
}

int main()
{
	m_coloring(0);
	
	return 0;
}