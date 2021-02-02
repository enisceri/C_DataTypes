/*
	Enis CERI
	Veri Yapilari
	1. Yazdirma
	2. Sona eleman ekleme
	3. Sirali eleman ekleme yapan fonksiyon
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct N{
	int veri;
	struct N * next;
}Node;

void yazdir(Node *root)
{
	printf("\n------LISTE------\n");
	while(root != NULL)
	{
		printf("%d ",root->veri);
		root = root->next; 
	}
}

void ekle(Node *root,int eleman)
{
	while(root->next != NULL)
	{
		root = root->next;
	}
	root->next = (Node *)malloc(sizeof(Node));
	root->next->veri = eleman;
	root->next->next = NULL;
}




Node * ekleSirali(Node *root,int eleman)
{
	//Linked-List Bossa
	if(root == NULL)
	{
		root = (Node*)malloc(sizeof(Node));
		root->next = NULL;
		root->veri = eleman;
		return root;
	}
	//---------------------------------------------
	
	if(root->veri > eleman)//ilk elemandan kucuk olma durumu
	{
		Node* temp = (Node *)malloc(sizeof(Node));
		temp->veri = eleman;			
		temp->next = root;
		root = temp;
		return temp;
	}
	Node *iter = root;	 
	while(iter->next != NULL && iter->next->veri < eleman)
	{
		iter = iter->next;
	}
	Node* temp = (Node *)malloc(sizeof(Node));
	temp->next = iter->next;
	iter->next = temp;
	temp->veri = eleman;
	return root;
		
}

int main()
{
	Node *root;
	root = (Node *)malloc(sizeof(Node));
	root->veri = 10;
	root->next = NULL;
	
	ekle(root,20); 
	ekle(root,30);
	ekle(root,40);
	ekle(root,60);
	ekle(root,70);
		

	yazdir(root);
	printf("\n--------SIRALI EKLEME ISLEMLERI ASAGIDA---------\n");
	root = ekleSirali(root,400);
	root = ekleSirali(root,40);
	root = ekleSirali(root,4);
	root = ekleSirali(root,450);
	root = ekleSirali(root,50);
	
	yazdir(root);

	return 0;
}
