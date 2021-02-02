#include <stdio.h>
#include <stdlib.h>

typedef struct N{
	int veri;
	struct N *next;
}Node;

void yazdirListe(Node *root)
{
	int i = 1;
	printf("\n-----LISTE YAZDIRILIYOR-----\n");
	while(root != NULL)
	{	
		printf("%d. veri = %d\troot Adres = %d\n",i, root->veri,root);
		root = root->next;
		++i;
	}
	
}

void ekleEleman(Node *root, int eklenecekEleman)
{
	while(root->next != NULL)
	{
		root = root->next;	
	}	
	root->next = (Node *)malloc(sizeof(Node));

	root->next->veri = eklenecekEleman;
	root->next->next = NULL;	
}

int main()
{
	Node *root = (Node *)malloc(sizeof(Node));
	root->veri = 100;
	root->next = NULL;
	int i;
	
	for(i = 0; i < 5; i++)
	{
		ekleEleman(root, i * 10);
	}
	
	yazdirListe(root);
	
	printf("%d",root); //ROOT ADRESIM DEGISMIYOR. CUNKU CALL BY VALUE YAPIYORUZ.

		
	
	
	return 0;
}
