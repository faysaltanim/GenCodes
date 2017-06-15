#include<stdio.h>
#include<conio.h>

#define READ(filename) freopen(filename, "r", stdin)
#define WRITE(filename) freopen(filename, "w", stdout)

#define SIZE 1000
#define START 0

int N;
int grid[SIZE][SIZE];
int visited[SIZE][SIZE];
int startx, starty, destx, desty;
int min = 999999;
int ways = 0;

void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			grid[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

void solve(int startx1, int starty1, int destx1, int desty1, int count)
{
	printf("solve Function Starts count: %d\n", count);
	if (count>min)
	{

		printf("first if\n");
		return;
	}
	
	if (startx1 == destx1 && starty1 == desty1)
	{
		printf("second if\n");
		if (min > count)
		{
			min = count;
			ways++;
			return;
		}
		else if (min == count)
		{
			ways++;

		}
		return;
	}
	
	if (startx1 + 1 < N)
	{
		solve(startx1 + 1, starty1, destx1, desty1, count + 1);
	}

	if (startx1 - 1 >= 0)
	{
		solve(startx1 - 1, starty1, destx1, desty1, count + 1);
	}

	if (starty1 + 1 < N)
	{
		solve(startx1, starty1+1, destx1, desty1, count + 1);
	}

	if (starty1 - 1 >= 0)
	{
		solve(startx1, starty1-1, destx1, desty1, count + 1);
	}
}

void printCase()
{
	printf("Ways: %d and Minimum Lenth: %d", ways, min);
}

void readStartEnd()
{
	scanf("%d %d %d %d %d", &N, &startx, &starty, &destx, &desty);
}

int main()
{
	READ("input.txt");
	WRITE("output.txt");

	scanf("%d", &N);
	
	readStartEnd();
	init();
	solve(startx, starty, destx, desty, START);
	printCase();

	

	return 0;
}