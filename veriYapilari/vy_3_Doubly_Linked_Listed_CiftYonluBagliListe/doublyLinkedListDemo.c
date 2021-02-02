/*
	Enis CERI
	
	Linked List'ten farki istedigimiz zaman geri donebiliyor olusumuzdur.
*/


#include <stdio.h>
#include <stdlib.h>

typedef struct N{
	int veri;
	struct N * next;
	struct N * prev;
}Node;

void yazdir(Node **root)
{
	printf("\n----CIFT YONLU BAGLI LISTE YAZDIRILIYOR----\n");
	Node *iter = *root;
	
	while(iter != NULL)
	{
		printf("%d ", iter->veri);
		iter = iter->next;
	}
}

int uzunluk(Node *root)
{
	int i = 0;
	while(root != NULL)
	{
		++i;
		root = root->next;
	}
	return i;
}

void pushBack(Node **root, int eleman)
{
	Node *iter = *root;
	Node *lastNode = (Node *)malloc(sizeof(Node));
	lastNode->veri = eleman;
	
	while(iter->next != NULL)
	{
		iter = iter->next;
	}
	
	iter->next = lastNode;
	lastNode->prev = iter;
	lastNode->next = NULL;
	
}

void indisBazliEkleme(Node **root, int eleman, int indis)
{
	if(indis == 0)
	{
		Node *temp = (Node *)malloc(sizeof(Node));
		temp->prev = NULL;
		temp->next = *root;
		*root = temp;
		temp->veri = eleman;
		
	}
	
	else
	{			
		Node *iter = *root;
		
		int i = 0;
		for(i = 1; i < indis; ++i)
		{
			iter = iter->next;	
		}
		
		Node *temp = (Node *)malloc(sizeof(Node));
		temp->next = iter->next;
		iter->next = temp;
		temp->prev = iter;
		temp->veri = eleman;	
	}
}

void pop(Node **root)
{
	Node *iter = *root;
	Node *temp;
	
	while(iter->next->next != NULL)
	{
		iter = iter->next;
	}
	
	temp = iter->next;
	iter->next = NULL;
	free(temp);
}

void siraliEkle(Node **root, int eleman)
{
	//Double Linked List bossa
	if(*root == NULL)
	{
		*root = (Node *)malloc(sizeof(Node));
		(*root)->next = NULL;
		(*root)->prev = NULL;
		(*root)->veri = eleman;
	}
	//--------------------------------
	else
	{
		Node *iter = *root;
		//Basa Ekleme Durumu (ilk elemandan daha kucuk bir sayi eklenme durumu)
		if(iter->veri > eleman)
		{
			Node *temp = (Node *)malloc(sizeof(Node));
			temp->veri = eleman;
			temp->next = *root;
			
			temp->prev = NULL;
			*root = temp;
				
		}
		
		//Araya ya da sona eklenme durumu
		else
		{
			Node *iter = *root;
			
			while(iter->next != NULL && iter->next->veri < eleman)
			{
				iter = iter->next;
			}
			Node *temp = (Node *)malloc(sizeof(Node));
			temp->veri = eleman;
			temp->next = iter->next;
			iter->next = temp;
			temp->prev = iter;
			if(temp->next != NULL)
			{
				temp->next->prev = temp;
			}
		}
	}
}

void sil(Node **root, int eleman)
{
	
	if(uzunluk(*root) == 1)
	{
		if((*root)->veri == eleman)
		{
			Node *temp;
			temp = *root;
			free(temp);			
			*root = NULL;
		}
		
		else
		{
			return;
		}
	}
	
	else if(uzunluk(*root) > 1)
	{
		//ilk elemani silmek istersek
		if((*root)->veri == eleman)
		{
			Node *temp;
			temp = *root;
			*root = (*root)->next;
			free(temp);			
		}
		
		else
		{
			Node *iter = *root;
			
			while(iter->next != NULL && iter->next->veri != eleman)
			{
				iter = iter->next;		
			}
			
			//Aradigimizi bulamazsak
			if(iter->next == NULL)
			{
				return;
			}
			
			//Aradigimiz sayi listede var ise silecegiz.
			else
			{
				//son elemanin silinme durumu
				if(iter->next->next == NULL)
				{
					Node *temp;
					temp = iter->next;
					free(temp);
					iter->next = NULL;
				}
				
				else
				{
					//ortadan eleman silinme durumu
					Node *temp;
					temp = iter->next;					
					iter->next = iter->next->next;					
					iter->next->prev = iter;
					free(temp);
					
				}
				

			}
			
		
		}
		
		
	}
}

int main()
{
	Node *root = (Node *)malloc(sizeof(Node));
	root->next = NULL;
	root->prev = NULL;
	root->veri = 10;	
	pushBack(&root,20);
	
	pushBack(&root,20);
	pushBack(&root,400);
	pushBack(&root,40);

	yazdir(&root);
	
	siraliEkle(&root, 1);
	yazdir(&root);
	
	siraliEkle(&root,7);
	siraliEkle(&root,-70);
	yazdir(&root);


	Node *t = (Node *)malloc(sizeof(Node));
	t->prev = NULL;
	t->next = NULL;
	t->veri = 123;
	

	
	printf("\n\n");
	pushBack(&t,1);
	pushBack(&t,4);
	pushBack(&t,3);
	pushBack(&t,7);
	pushBack(&t,87);
	yazdir(&t);
	
	sil(&t,3);

	yazdir(&t);
	




	
	
	return 0;
}
