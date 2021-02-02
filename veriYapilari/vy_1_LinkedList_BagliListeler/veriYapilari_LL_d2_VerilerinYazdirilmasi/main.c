#include <stdio.h>
#include <stdlib.h>
/*
	ENÝS CERI
	1. Bagli Listelere Fonk. ve Dongu ile Erisim
	2. Sentinal Kavrami (Bir kutunun isaretcisinin NULL oldugunu garanti etmek manasina gelir.)
*/

typedef struct N{
	int veri;
	struct N *next;
}Node;

void bagliListeYazdir(Node *root)
{
	//Node *iter;
	//iter = root;
	printf("\n------LISTE YAZILIYOR-----\n");
	while(root != NULL)
	{
		printf("Veri :%d\tRoot Adres:%d\n",root->veri,root);
		root = root->next;
	}
	
}



int main()
{
	Node *root;
	Node *iter;
	
	root = (Node *)malloc(sizeof(Node));
	root->veri = 10;
	
	root->next = (Node*)malloc(sizeof(Node));
	root->next->veri = 20;
	
	root->next->next = (Node *) malloc(sizeof(Node));
	root->next->next->veri = 30;
	root->next->next->next = NULL; //Bu son kutunun pointerinin NULL oldugunu garanti etmeliyiz.
								   //Buna SENTINAL denir. Yani isin bittigini gosteren ifade. (sentinal :bitis simgesi)
	
	iter = root;
	
	//while(iter != NULL) ile tum elemanlari gorebilirim.
	//while(iter->next != NULL) da ise son kutuyu kaybetmedigim icin eleman ekleyebilirim ama ekrana son elemani yazdirmaz.

	while(iter->next != NULL)
	{
		printf("%d\n",iter->veri);
		iter = iter->next;
	}
	
	int i;
	for(i = 1; i <= 5; i++)
	{
		iter->next = (Node *)malloc(sizeof(Node));
		iter = iter->next;
		iter->veri = i * 100;	
		
		iter->next = NULL;
		
	}

	iter = root;
	
	printf("\n----------LISTE ELEMANLARI-----------\n");
	//10 20 30 eski elemanlardi. 100,200,300,400,500 'u ekledik.
	
	while(iter != NULL)
	{
		printf("%d\n",iter->veri);
		iter= iter->next;
	}
	
	
	bagliListeYazdir(root);
	printf("Root Adres :%d",root);
	
	return 0;
}
