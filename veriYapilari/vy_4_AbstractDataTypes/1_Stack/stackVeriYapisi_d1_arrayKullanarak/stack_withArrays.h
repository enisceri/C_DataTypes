#ifndef STACK_WITHARRAYS_H
#define STACK_WITHARRAYS_H
#include <stdio.h>
#include <stdlib.h> // malloc warning almamak icin eklenmelidir. (incompatible implicit declaration)

struct s
{
	int boyut;
	int tepe ;
	int *dizi;// Dinamik bellek ile genisletilip daraltilacak.
};
typedef struct s stack;


//FONKSIYON PROTOTIPLERI
int pop(stack *s);
void push(int eleman, stack *s);
void yazdir(stack *s);
stack * initStack();





#endif
