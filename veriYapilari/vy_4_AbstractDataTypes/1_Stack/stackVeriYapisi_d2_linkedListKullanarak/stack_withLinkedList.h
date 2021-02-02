#ifndef STACK_WITHLINKEDLIST
#define STACK_WITHLINKEDLIST
#include <stdio.h>
#include <stdlib.h>

struct N
{
	int veri;
	struct N *next;	
};

typedef struct N Node;


//FONKSIYON PROTOTIPLER

int pop(Node **);
Node* push(Node *root, int eleman);
void yazdir(Node *);
int size(Node *root);


#endif
