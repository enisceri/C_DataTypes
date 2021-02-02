#include <stdio.h>
#include <stdlib.h>
/*
     Not  (<) simgesi * ifadesinden kucuk bir sayiyi (>) ifadesi * ifadesinden buyuk bir sayiyi temsil etmektedir.
     
     			Binary Search Tree
     				
     				*
     			  /   \
     		    (<)   (>)
			   /  \   /  \
			(<)  (>) (<) (>)
	Goruldugu uzere her bir dugum ikiye ayriliyor. Dolayisiyla sag ve solu gosteren pointerlara ve deger tutmak icin degiskene ihtiyac var.
*/

struct N
{
	struct N* left;
	struct N* right;
	int data;
	
};
typedef struct N Node;

Node * ekle(Node *agac, int eleman)
{
	if(agac == NULL)
	{
		Node *root = (Node *)malloc(sizeof(Node));
		root->data = eleman;
		root->left = NULL;
		root->right = NULL;
		
		return root;		
	}


	
	if(agac->data < eleman) // Sagina ekleme durumu	
	{
		agac->right = ekle(agac->right,eleman);
		return agac;
	}
	
	
	agac->left = ekle(agac->left,eleman);
	return agac;
		
}

void yazdir(Node *agac)
{
	/* Kucukten buyuge siralamak icin LNR kullanilir.
		infix   -> LNR, RNL
		prefix  -> NLR, NRL
		postfix -> LRN, RLN
	*/


	
	if(agac == NULL)
	{
		return;
	}
	yazdir(agac->left);
	printf("%d ",agac->data);
	yazdir(agac->right);

}

int bul(Node *agac, int arananSayi)
{
	if(agac == NULL)
	{		
		return -1;
	}
	
	if(agac->data == arananSayi)
	{
		return 1;
	}
	
	if(bul(agac->left,arananSayi) == 1)
	{
		return 1;		
	}
	if(bul(agac->right,arananSayi) == 1)
	{
		return 1;		
	}
	
	return -1;
	
}

int maxSayi(Node *agac)
{
	while(agac->right != NULL)
	{
		agac = agac->right;
	}
	return agac->data;
}
int minSayi(Node *agac)
{
	while(agac->left != NULL)
	{
		agac = agac->left;
	}
	return agac->data;
}	

Node * sil(Node *agac, int eleman)
{
	//Solundaki degerlerin maximumu ya da sagindaki agacin minimumu
	if(agac == NULL)
	{
		return NULL;
	}
	
	if(agac->data == eleman)
	{
		if(agac->left == NULL && agac->right == NULL)
		{
			return NULL;	
		}	

		if(agac->right != NULL)
		{
			agac->data = minSayi(agac->right);
			agac->right = sil(agac->right,minSayi(agac->right));
			
			return agac;
		}
		else
		{
			agac->data = maxSayi(agac->left);
			agac->left = sil(agac->left,maxSayi(agac->left));
			return agac;
		}
	}
	
	if(agac->data < eleman)
	{
		agac->right = sil(agac->right,eleman);
		return agac;
	}
	else
	{
		agac->left = sil(agac->left,eleman);
		return agac;
	}
	
}

int main()
{
	Node *agac = NULL;
	agac = ekle(agac,56);
	agac = ekle(agac,200);
	agac = ekle(agac,26);
	agac = ekle(agac,12);
	agac = ekle(agac,190);
	agac = ekle(agac,213);
	agac = ekle(agac,18);
	agac = ekle(agac,28);
	agac = ekle(agac,12);
	agac = ekle(agac,24);
	agac = ekle(agac,27);




	yazdir(agac);

	agac = sil(agac,56);
	printf("\n");
	yazdir(agac);
	
	printf("\nArama sonucu : %d",bul(agac,1920));
	printf("\nMax  		   : %d",maxSayi(agac));
	printf("\nMin  		   : %d",minSayi(agac));

	return 0;	
}
