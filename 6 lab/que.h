#ifndef QUE_H
#define QUE_H


#include <stdio.h>
#include <stdlib.h>
#include "conio.h"

struct Queue
{
    int capacity, size, rear, front;
    int* array;
    //Указатели на адреса начала списка и его конца
};
struct Queue* createQueue( int capacity);
int isEmpty(struct Queue* queue) ;
void enQueue(struct Queue* queue, int item) ;
int deQueue(struct Queue* queue);
int front(struct Queue* queue);
int rear(struct Queue* queue) ;
void showArray(struct Queue* queue);
#endif // QUE_H
