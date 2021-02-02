#include <stdio.h>
#include <stdlib.h>

typedef struct N{
	int veri;
	struct N* next; //Bir sonraki veriye erismek icin.
	
}Node;

int main()
{
	
	int i;
	Node *root = NULL;
	Node *iter = NULL; //iterator

	root = (Node *)malloc(sizeof(Node));
	root ->veri = 10;
	
	root->next = (Node*)malloc(sizeof(Node));
	root->next->veri = 20;	
	
	root->next->next = (Node*)malloc(sizeof(Node));
	root->next->next->veri = 30;
	
	iter = root;
	
	printf("%d\n",iter->veri);
	
	iter = iter->next;
	printf("%d\n",iter->veri);

	iter = iter->next;
	printf("%d\n",iter->veri);	

	return 0;
}
