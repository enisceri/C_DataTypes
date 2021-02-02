/*
	Enis CERI
	Veri Yapilari
	
	Silme islemlerinin yapilmasi.
	1. pop fonksiyonu ile son elemanin silinmesi. (pop fonksiyonu)
	2. Listede eger varsa istenilen elemanin silinmesi. (removeElement)
	3. Listede index'e gore silme islemi yapan fonksiyon. (removeIndex)
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct N{
	int veri;
	struct N *next;
}Node;

int uzunlukListe(Node *root)
{
	int i = 0;
	
	while(root != NULL)
	{
		++i;
		root = root->next;
	}
	return i;
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

void yazdir(Node *root)
{
	printf("\n-----BAGLI LISTE ELEMANLARI----\n");
	while(root != NULL)
	{
		printf("%d ",root->veri);
		root = root->next;
	}
}



Node * removeElement(Node *root, int eleman)
{
	Node *temp;
	Node *iter = root;
	
	if(uzunlukListe(root) == 1)
	{
		if(eleman == root->veri)
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
	
	
	else if(uzunlukListe(root) > 1)
	{	
		//ilk eleman silinmek istenirse
		if(root->veri == eleman)
		{
			temp = root;
			root = root->next;
			free(temp);
			
			return root;
		}
		
		//ilk eleman disindaki elemanlar silinmek istenirse.
		while(iter->next != NULL && iter->next->veri != eleman)
		{
			iter = iter->next;
		}		
		
		//Aradigimizi bulamadiysak
		if(iter->next == NULL)
		{
			return root;
		}
		
		//Aradigimiz sayi listede var ise silecegiz.
		else
		{
			temp = iter->next;
			iter->next = iter->next->next;
			free(temp);

			
			return root;		
		}
		
	}
}


Node * pop(Node *root)
{
	Node *temp;

	if(uzunlukListe(root) == 1)
	{ // eleman sayisi 1
		temp = root,
		root = NULL;
		free(temp);
		return root;	
	}
	
	else if(uzunlukListe(root) > 1)
	{
		Node *iter = root;
		
		while(iter->next->next != NULL)
		{
			iter = iter->next;
		}
		temp = iter->next;
		iter->next = NULL;
		free(temp);
	
		return root;
		
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


int main()
{
	Node *root = (Node *)malloc(sizeof(Node));
	root->next = NULL;
	root->veri = 10;
	push_back(root,20);
	push_back(root,30);
	push_back(root,80);


	
	yazdir(root);	

	root = removeIndex(root,0);
	
	yazdir(root);	


	
	
	return 0;
}
