/*
	Bismillahirrahmanirrahim
	Enis CERI
	Veri Yapilari Islemleri 
	
	1. Bagli Listeyi Yazdiran Fonksiyon
	2. Bagli Listenin sonuna eleman ekleyen fonksiyon (push_back)
	3. Listenin uzunlugunu bulan fonksiyon (size) 
	4. Listenin son elemanini silen fonksiyon (pop)
	5. Listeden istenilen eleman eger varsa silen fonksiyon (removeElement)
	6. Listeden istenilen indisteki elemani silen fonksiyon (removeIndex)
	7. Listenin istenilen indisine eleman ekleyen fonksiyon (add)
	8. Listeyi kucukten buyuge veya buyukten kucuge siralayan fonksiyon (sortListe)
	9. Listeyi hem siralayip hem de eklenilen elemani kucukten buyuge uygun yere koyan fonksiyon (ekleSirali)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct N{
	int veri;
	struct N *next;
}Node;

void yazdir(Node *root)
{
	printf("\n----BAGLI LISTE ELEMANLARI----\n");	
	while(root != NULL)
	{
		printf("%d ",root->veri);
		root = root->next;
	}	
}

void push_back(Node *root, int eleman)
{
	while(root->next != NULL)
	{
		root= root->next;
	}
	root->next = (Node *)malloc(sizeof(Node));
	root->next->next = NULL;
	root->next->veri = eleman;
}

int size(Node *root)
{
	int i = 0;
	while(root != NULL)
	{
		++i;
		root = root->next;
	}
	
	return i;
}

Node * pop(Node *root)
{
	Node *temp;
	if(size(root) == 1)
	{
		temp = root;
		root = NULL;
		free(temp);
		
		return root;
	}
	
	else if(size(root) > 1)
	{
		Node *iter = root;
		
		while(iter->next->next != NULL)
		{
			iter = iter->next;
		}
		
		temp = iter->next;
		iter->next = NULL;
		free(iter);
		
		return root;
	}
}

Node * removeElement(Node *root, int eleman)
{
	Node *temp;
	Node *iter = root;
	
	if(size(root) == 1)
	{
		if(root->veri == eleman)
		{
			temp = root;
			root = NULL;
			free(temp);
			
			return root;
		}
		
		else
		{
			return root;
		}
	
	}
	
	else if(size(root) > 1)
	{
		//ilk elemani silmek istersek
		if(root->veri == eleman)
		{
			temp = root;
			root = root->next;
			free(temp);
			
			return root; 
		}
		
		while(iter->next != NULL && iter->next->veri != eleman)
		{
			iter = iter->next;		
		}
		
		//Aradigimizi bulamazsak
		if(iter->next == NULL)
		{
			return root;
		}
		
		//Aradigimiz sayi listede var ise silecegiz.
		else
		{
			temp = iter->next;
			iter = iter->next->next;
			free(temp);
			
			return root;
		}
			
	}
}


Node * removeIndex(Node *root, int indis)
{
	int i = 0;
	Node *temp;
	Node *iter = root;
	
	if(indis == 0)
	{
		temp = root;
		root = root->next;
		free(temp);
		
		return root;	
	}
	
	else
	{
		for(i = 1; i < indis; i++)
		{
			iter = iter->next;
		}
		
		temp = iter->next;
		iter->next = iter->next->next;
		free(temp);
		
		return root;
	}
}

Node * add(Node *root, int eleman, int indis)
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

Node * sortListe(Node *root, bool kucuktenBuyuge)
{	
	if(kucuktenBuyuge)
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
	
	else
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
				if(iter->veri < iter->next->veri)
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
	Node *root = (Node *)malloc(sizeof(Node));
	root->next = NULL;
	root->veri = 10;
	push_back(root,20);
	push_back(root,30);
	push_back(root,1);
	push_back(root,5);
	push_back(root,180);
	push_back(root,70);
	yazdir(root);	

	root = sortListe(root,true);
	
	yazdir(root);	
	
	root = sortListe(root,false);
	yazdir(root);
		
	return 0;
}
