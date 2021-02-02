#include "stack_withLinkedList.h" 

/*
	Bu kodda stack kodlari linked-list kullanilarak yazilmistir.
*/
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

int pop(Node **root)
{
	if(*root == NULL)
	{
		printf("\nUyari : Stack Bos !");
		return -1;
	}
	
	else //root NULL degilse
	{
		if(size(*root) == 1)
		{
			int silinecekDeger = (*root)->veri;

			*root = NULL;
			free(*root);
			
			return silinecekDeger;
		}
		else if(size(*root) > 1)
		{
			Node *temp;
	
			Node *iter = *root;
			
			while(iter->next->next != NULL)
			{
				iter = iter->next;
			}
			
			temp = iter->next;
			int silinecekDeger = temp->veri;		
			iter->next = NULL;
			free(temp);
			
			return silinecekDeger;
		}
	}
	

	


}



Node* push(Node *root, int eleman)
{
	if(root == NULL)
	{
		root = (Node *)malloc(sizeof(Node));
		root->veri = eleman;
		root->next = NULL;
		
		return root;
	}
	
	else
	{
		Node *iter = root;
		
		while(iter->next != NULL)
		{
			iter = iter->next;
		}
		
		iter->next = (Node *)malloc(sizeof(Node));
		iter->next->veri = eleman;
		iter->next->next = NULL;
		
		return root;		
	}
}

void yazdir(Node *root)
{
	printf("\n----STACK ELEMANLARI----\n");
	while(root != NULL)
	{
		printf("%d ",root->veri);
		root = root->next;
	}
}


int main()
{
	Node *root = NULL;	
	yazdir(root);
	
	printf("\n%d popped\n",pop(&root));
	printf("\n%d size root\n",size(root));

	root = push(root,10);
	root = push(root,20);
	root = push(root,30);
	root = push(root,40);
	root = push(root,50);
	yazdir(root);	


	printf("\n%d popped\n",pop(&root));
	printf("\n%d popped\n",pop(&root));
	printf("\n%d popped\n",pop(&root));
	printf("\n%d popped\n",pop(&root));	

	printf("\n%d popped\n",pop(&root));
	printf("\n%d popped\n",pop(&root));

	



	yazdir(root);	

	

	
	return 0;
}
