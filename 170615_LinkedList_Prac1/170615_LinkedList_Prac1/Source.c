/*

Created by:
M Faysal Tanim
June 15, 2017.

*/


#include<stdio.h>
#include<conio.h>
#include<malloc.h>


struct Node{
	int data;
	struct Node *next;
};

struct Node *createNode(int n)
{
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node *));
	temp->data = n;
	temp->next = NULL;
	return temp;
}

struct Node *push(struct Node *head, int data)
{
	struct Node *temp = createNode(data);

}

int main()
{
	return 0;
}