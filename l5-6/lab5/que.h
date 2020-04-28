#ifndef QUE_H
#define QUE_H


#include <stdio.h>
#include <stdlib.h>
#include "locale.h"
#include "stdlib.h"
#include "conio.h"
#include "windows.h"
struct Queue
{
    int capacity, size, rear, front;
    int* array;
};
struct Queue* createQueue( int capacity);
int isFull(struct Queue* queue) ;
int isEmpty(struct Queue* queue) ;
void enQueue(struct Queue* queue, int item) ;
int deQueue(struct Queue* queue);
void showArray(struct Queue* queue);
#endif // QUE_H
