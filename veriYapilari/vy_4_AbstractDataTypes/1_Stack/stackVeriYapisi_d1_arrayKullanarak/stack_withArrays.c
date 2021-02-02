#include "stack_withArrays.h"

/*	STACK WITH ARRAYS (Bu kodda array'ler ile kodlama yapilmistir. Ikinci kodda linked list ile olacaktir.
 LIFO (Last In First Out) -> Otobus mantigi ile son giren ilk cikar.	 
 3 temel operasyonu vardir.
 1. Push : Stack'in sonuna eleman ekler.
 2. Pop  : Stack'in sonundan eleman siler.
 3. Top  : Stack'in tepesindeki bilgiyi alir. Ama silmez.

*/

stack * initStack()
{
	stack *s = (stack *)malloc(sizeof(stack));
	s->dizi = NULL;
	s->boyut = 2;
	s->tepe = 0;
	
	return s; 
}
 
int pop(stack *s)
{
	
	if(s->tepe <= 0 || s->dizi == NULL)
	{
		printf("UYARI : Dizi bos !");
		return -1;
	}
	

	else if(s->tepe <= (s->boyut / 4) && s->boyut > 2)
	{
		int *yeniDizi = (int *)malloc(sizeof(int) * (s->boyut / 2));			


		int i = 0;
		for(i = 0; i < s->tepe; i++)
		{
			yeniDizi[i] = s->dizi[i];
		}
		free(s->dizi);
		s->dizi = yeniDizi;
		s->boyut /= 2;
	}
	
	return s->dizi[--(s->tepe)];	
}

void push(int eleman, stack *s)
{
	if(s->dizi == NULL)
	{
		s->dizi = (int *)malloc(sizeof(int) * 2);			
	}
	if(s->tepe >= s->boyut - 1)
	{
		int *yeniDizi = (int *)malloc(sizeof(int) * s->boyut * 2);
		
		int i = 0;
		for(i = 0; i < s->boyut; ++i)
		{
			yeniDizi[i] = s->dizi[i];
		}
		free(s->dizi);
		s->dizi = yeniDizi;		
		s->boyut *= 2;
	}
	
	s->dizi[s->tepe++] = eleman;	
}

void yazdir(stack *s)
{
	printf("\n----Stack Elemanlar----\n");
	printf("Dizi Boyut : %d\n",s->boyut);
	printf("Tepe       : %d\n",s->tepe);

	int i = 0;
	for(i = 0; i < s->tepe; ++i)
	{
		printf("%d ", s->dizi[i]);
	}
}


int main()
{
	stack *s1 = initStack();
	stack *s2 = initStack();
	
	int i;
	for(i = 0; i < 10; i++)
	{
		push(i*10,s1);
	}
	
	yazdir(s1);
	
	for(i = 0; i < 10; i++)
	{
		push(pop(s1),s2);
	}

	
	push(10,s1);
	push(20,s1);
	push(30,s1);
	push(40,s1);
	push(50,s1);
	push(60,s1);
	push(70,s1);
	push(80,s1);

	yazdir(s1);
	

	
	printf("\nPopped %d\n",pop(s1));
	printf("\nPopped %d\n",pop(s1));
	printf("\nPopped %d\n",pop(s1));

	
	
	return 0;
}
