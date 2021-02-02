#include <stdio.h>
#include <stdlib.h>


struct N
{
	int veri;
	struct N *next;
	
};

typedef struct N Node;

Node *root = NULL;
Node *son = NULL;

void enqueue(int eleman)
{
	if(root == NULL)
	{
		root = (Node *) malloc(sizeof(Node));
		root->veri = eleman;
		root->next = NULL;	
		son = root;
	}
	
	else
	{
		son->next = (Node *)malloc(sizeof(Node));
		son->next->veri = eleman;
		son = son->next;
		son->next = NULL;
	}		
}

int dequeue()
{
	if(root == NULL)
	{
		printf("\n	Queueu bos !\n");
		return -1;
	}

	int silinecekDeger = root->veri;
	Node *temp = root;
	root = root->next;
	
	free(temp);
	
	return silinecekDeger;
}

void yazdir()
{
	printf("\n---QUEUE ELEMANLARI---\n");

	while(root != NULL)
	{
		printf("%d ",root->veri);
		root = root->next;
	}
}
int main()
{
	int i = 0;
	
	for(i = 0; i < 20; i++)
	{
		enqueue(i);			
	}	
	printf("\n%d dequeued",dequeue());
	printf("\n%d dequeued",dequeue());
	printf("\n%d dequeued",dequeue());
	printf("\n%d dequeued",dequeue());
	printf("\n%d dequeued",dequeue());
	printf("\n%d dequeued",dequeue());
	printf("\n%d dequeued",dequeue());
	printf("\n%d dequeued",dequeue());

	
	yazdir();
	
	return 0;
}
