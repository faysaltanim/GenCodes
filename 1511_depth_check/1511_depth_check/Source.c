#include<stdio.h>
#include<conio.h>

#define READ(filename) freopen(filename, "r", stdin)
#define WRITE(filename) freopen(filename, "w", stdout)

#define SIZE 100
#define START 0

int x[SIZE];
int y[SIZE];
int grid[SIZE][SIZE];
int N, M;
int min;
int minLen;
int ways=0;
//int result;

void init()
{
	for (int l = 0; l<SIZE; l++)
	{
		x[l] = 0;
		y[l] = 0;
	}
}

void go(int x, int y, int len, int dx, int dy)
{
	if (len > minLen)
	{
		//printf("\nlen(%d) is > minLen(%d)\n", len, minLen);
		return;
	}
	
	if (x == dx && y == dy)
	{
		if (len < minLen)
		{
			//printf("\nWays set to 1\n");
			ways = 1;
			minLen = len;
		}
		else if (len == minLen)
		{
			ways++;
			//printf("\nWays: %d\n", ways);
		}
		return;
	}

	if (x - 1 >= 0 && grid[x - 1][y] != 9)
	{
		go(x - 1, y, len + 1, dx, dy);
	}

	 if (x + 1 < N && grid[x + 1][y] != 9)
	{
		go(x + 1, y, len + 1, dx, dy);
	}

	 if (y - 1 >= 0 && grid[x][y - 1] != 9)
	{
		go(x, y - 1, len + 1, dx, dy);
	}
	 if (y + 1 <N && grid[x][y + 1] != 9)
	{
		go(x, y + 1, len + 1, dx, dy);
	}

}

void solveCase()
{
	
	int result = 1;
		for (int k = 1; k < M; k++)
		{
		minLen = N*N;
		ways = 0;
		go(x[k], y[k], 0, x[k + 1], y[k + 1]);
		
		result = result*ways;
		}
		printf("Ways: %d\n", ways);
		printf("Result: %d", result);
}

int main()
{
	READ("input.txt");
	WRITE("output.txt");
	init();
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &grid[i][j]);
			printf("%d", grid[i][j]);
			if (grid[i][j] != 9 && grid[i][j] != 0)
			{

				x[grid[i][j]] = i;
				y[grid[i][j]] = j;
			}
			
		}
		printf("\n");
	}

	solveCase();
//	printf("Result: %d", result);
	return 0;

}
