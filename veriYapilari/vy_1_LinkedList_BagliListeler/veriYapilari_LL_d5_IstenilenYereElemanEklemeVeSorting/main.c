/*
	Enis CERI
	Veri Yapilari ile Alakali Islemler
 1. Listeyi yazdiran fonksiyon
 2. Listenin sonuna eleman ekleyen fonksiyon (push_back)
 3. Indis bazli eleman ekleyen fonksiyon
 4. Listenin uzunlugunu bulan fonksiyon
 5. Listeyi kucukten buyuge siralayan fonksiyon
 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct N{
	int veri;
	struct N *next;
}Node;

void yazdir(Node *root)
{
	printf("\n----BAGLI LISTE ELEMANLARI----\n");
	while(root != NULL)
	{
		printf("%d ->> ",root->veri);
		root = root->next;
	}
	
}

void push_back(Node *root, int eleman)
{
	while(root->next != NULL)
	{
		root = root->next;
	}
	root->next = (Node *)malloc(sizeof(Node));
	root->next->next = NULL;
	root->next->veri = eleman;
}

Node * elemanEkle(Node *root, int eleman, int indis)
{
	
	if(indis == 0)
	{
		Node *temp = (Node *)malloc(sizeof(Node));
		
		temp->next = root;
		root = temp;
		temp->veri = eleman;
		
		
		return root;
	}
	
	else
	{
		int i;
		Node *iter = root;
		
		for(i = 1; i < indis; ++i)
		{
			iter = iter->next;
		}
		
		Node *temp = (Node *)malloc(sizeof(Node));
		temp->next = iter->next;
		iter->next = temp;
		temp->veri = eleman;	
		
		return root;
	}
}


int uzunlukListe(Node *root)
{
	int i = 0;
	while(root !=NULL)
	{
		++i;
		root= root->next;
	}
	return i;
}

Node * sortListe(Node *root)
{

	Node *temp = (Node *)malloc(sizeof(Node));
	int i,j;
	Node *iter = root;
	Node *iter2 = root;
	temp->veri = root->veri;
	
	while(iter2->next != NULL)
	{
		
		while(iter->next != NULL)
		{
			if(iter->veri > iter->next->veri)
			{
				temp->veri = iter->veri;
				iter->veri = iter->next->veri;
				iter->next->veri = temp->veri;
			}		
			
			iter = iter->next;
		}
		iter = root;
		iter2 = iter2->next;
	}
	
	return root;


}

int main()
{
	Node *root = (Node *)malloc(sizeof(Node));
	root->veri = 5;
	root->next = NULL;
	push_back(root,4);
	push_back(root,3);
	push_back(root,2);
	push_back(root,1);
	
	yazdir(root);
	root = sortListe(root);
	yazdir(root);
	
	push_back(root,11);
	push_back(root,-7);
	push_back(root,220);
	push_back(root,5);
	
	root = sortListe(root);	
	yazdir(root);
	
	push_back(root,-14);
	push_back(root,-20);
	push_back(root,200);
	sortListe(root);
	yazdir(root);
	
	
	return 0;
}
