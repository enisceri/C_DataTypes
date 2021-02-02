#include <stdio.h>
#include <stdlib.h>

typedef struct N{
	int veri;
	struct N * next;
}Node;

void yazdir(Node *root)
{
	Node *iter = root;
	printf("\n----DAIRESEL BAGLI LISTE ELEMANLARI----\n");
	
	printf("%d ",iter->veri); // ilk elemani bastirmaliyiz.
	iter = iter->next;
	
	while(iter != root)
	{
		printf("%d ",iter->veri);
		iter = iter->next;
	}
}

int size(Node *root)
{
	int i = 0;
	Node *iter = root;
	if(iter != NULL)
	{
		++i;
	}
	iter= iter->next;
	while(iter != root)
	{
		++i;
		iter = iter->next;
	}
	
	return i;
}


Node * push_back(Node *root, int eleman)
{
	Node *iter = root;

	while(iter->next != root)
	{
		iter = iter->next;
	}
	iter->next = (Node *)malloc(sizeof(Node));
	iter->next->next = root;
	iter->next->veri = eleman;

}

Node * ekleSirali(Node *root,int eleman)
{
	//Linked-List Bossa
	if(root == NULL)
	{
		root = (Node*)malloc(sizeof(Node));
		root->next = root;
		root->veri = eleman;
		return root;
	}
	//---------------------------------------------
	
	if(root->veri > eleman)//ilk elemandan kucuk olma durumu
	{
		Node* temp = (Node *)malloc(sizeof(Node));
		temp->veri = eleman;			
		temp->next = root;
		
		Node *iter = root;
		while(iter->next != root)
		{
			iter = iter->next;
		}
		iter->next = temp;
				
		return temp;
	}
	
	Node *iter = root;	 
	while(iter->next != root && iter->next->veri < eleman)
	{
		iter = iter->next;
	}
	Node* temp = (Node *)malloc(sizeof(Node));
	temp->next = iter->next;
	iter->next = temp;
	temp->veri = eleman;
	return root;
		
}

Node * removeElement(Node *root, int eleman)
{
	Node *temp;
	Node *iter = root;
	
	if(size(root) == 1)
	{
		if(root->veri == eleman)
		{
			Node *temp = (Node*)malloc(sizeof(Node));
			temp = root;
			temp->next = NULL;
			free(root);

			return temp;
		}
		
		else
		{
			return root;
		}
	
	}

}





int main()
{
	Node *root = (Node *)malloc(sizeof(Node));
	root->next = root;
	root->veri = 10;
/*	root->next = (Node *)malloc(sizeof(Node));
	root->next->next = root;
	root->next->veri = 25;
	
		
	yazdir(root);

	root = ekleSirali(root,50);
	root = ekleSirali(root,0);
	root = ekleSirali(root,30);
	yazdir(root);*/
	
	root = removeElement(root,10);
	yazdir(root);
	


	
	return 0;
}
