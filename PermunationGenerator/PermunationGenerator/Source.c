#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define READ(filename) freopen(filename, "r", stdin)
#define WRITE(filename) freopen(filename, "w", stdout)
#define SIZE 1000

int visited[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
char input[SIZE];
char data[SIZE];
int R;

void print()
{
	for (int k = 0; k < R; k++)
	{
		printf("%c", data[k]);
	}
	printf("\n");
}

void perm(int i)
{
	if (i >= R)
	{
		print();
		return;
	}

	for (int j = 0; j < R; j++)
	{
		if (visited[j] == 0)
		{
			visited[j] = 1;
			data[j] = input[i];
			perm(i + 1);
			visited[j] = 0;
		}
	}

}


int main()
{
	READ("input.txt");
	WRITE("output.txt");

	scanf("%s %d", &input, &R);
	/*printf("\nText: %s R: %d", input, R);
	printf("\nNth poisition input %c %c %c", input[1], input[3], input[4]);
	data[1] = input[1];
	data[3] = input[3];
	data[4] = input[4];
	printf("\nNth poisition data %c %c %c", data[1], data[3], data[4]);

	printf("\n\n");*/
	perm(0);
	return 0;

}
