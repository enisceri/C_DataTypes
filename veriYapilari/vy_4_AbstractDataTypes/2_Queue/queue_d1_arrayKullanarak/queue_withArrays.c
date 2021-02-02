#include <stdio.h>
#include <stdlib.h>

int *dizi    = NULL; // dinamik olarak genisletilip daraltilacak.
int sira     = 0;
int siraBasi = 0;
int boyut    = 2;




void clearQueueGaps()
{
	//Dizinin basinda dequeue isleminden dolayi olusan bos yerleri temizler.
	
	if(siraBasi == 0)
	{
		return;
	}
	
	int i = 0;
	for(i = 0; i < boyut; i++)
	{		
		dizi[i] = dizi[i + siraBasi];
	}
	
	sira -= siraBasi;
	siraBasi = 0;
	

}

int dequeue()
{   // Kuyruk basindaki elemani cikarir.

	if(sira == siraBasi)
	{
		printf("\nUYARI : Kuyrukta eleman yok !\n");
		return -1;	
	}	
	
	//sira - siraBasi o an kuyruktaki eleman sayisini verir.
	
	if(sira - siraBasi <= boyut / 4 && boyut > 2)
	{
		boyut /= 2;
		int *yeniDizi = (int *)malloc(sizeof(int) * boyut);	
		
		int i = 0;
		for(i = 0; i < sira - siraBasi; i++)
		{
			yeniDizi[i] = dizi[i + siraBasi];			
		}
		sira -= siraBasi;
		siraBasi = 0;
		free(dizi);
		dizi = yeniDizi;
	}	
	
	int kuyruktanCikanEleman = dizi[siraBasi];
	siraBasi++;
	clearQueueGaps();
	return kuyruktanCikanEleman;
	
 	
}


void enqueue(int eleman)
{
	if(dizi == NULL)
	{
		dizi = (int *)malloc(sizeof(int) * 2); // 2 elemanli olarak baslasin.	
	}
	
	if(sira >= boyut)
	{
		boyut *= 2;
		int *yeniDizi = (int *)malloc(sizeof(int) * boyut);
		
		
		int i = 0;	
		for(i = 0; i < boyut / 2; i++)
		{
			yeniDizi[i] = dizi[i];
		}
		free(dizi);

		dizi = yeniDizi;
				
	}
		
	dizi[sira++] = eleman;	
	
}

void yazdir()
{
	printf("\n---QUEUE ELEMANLARI---\n");
	int i = 0;
	for(i = 0; i < sira - siraBasi; i++)
	{
		printf("%d ",dizi[i]);
	}
}

int main()
{ 	

	int i = 0;
	
	for(i = 0; i< 20; i++)
	{
		enqueue(i);
	}
	printf("Size : %d",boyut);

	for(i = 0; i< 13; i++)
	{
		printf("\n%d dequeued",dequeue());
	}	
	
	for(i = 0; i< 10; i++)
	{
		enqueue(i*10);
	}	
	for(i = 0; i< 10; i++)
	{
		printf("\n%d dequeued",dequeue());
	}
	for(i = 0; i< 10; i++)
	{
		printf("\n%d dequeued",dequeue());
	}
	
	printf("Size : %d",boyut);
	yazdir();
	
	return 0;
}
