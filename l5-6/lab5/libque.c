#include "libque.h"
#pragma once
/* Функция создания очереди с заданной вместимостью */
/* size = 0 в момент создания */
struct Queue* createQueue(int capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = -1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

/* ОЧЕРЕДЬ ПОЛНА КОГДА SIZE == ВМЕСТИМОСТИ(CAPASITY) */
int isFull(struct Queue* queue)
{  return (queue->size == queue->capacity);  }

/* ОЧЕРЕДЬ ПУСТА КОГДА SIZE == 0 */
int isEmpty(struct Queue* queue)
{  return (queue->size == 0); }


/* ДОБАВИТЬ ЭЛЕМЕНТ В КОНЕЦ ОЧЕРЕДИ */
void enQueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size += 1;
}

 /* *********** УДАЛИТЬ ЭЛЕМЕНТ ИЗ НАЧАЛА СПИСКА */
int deQueue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size -= 1;
    return item;
}

/* *****ПОКАЗАТЬ МАССИВ */
void showArray(struct Queue* queue)
{
    printf("\n Queue:\n");
    for(int k = queue->front ; k <= queue->rear; k++)
    {
        printf("%d\t", queue->array[k]);
    }
    printf("\n");
}
