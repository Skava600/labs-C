#ifndef TREE_H
#define TREE_H


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Queue
{
    int capacity, size, rear, front;
    int* array;
    /*Указатели на адреса начала списка и его конца*/
};
struct Queue* createQueue( int capacity);
int isEmpty(struct Queue* queue) ;
void enQueue(struct Queue* queue, int item) ;
int deQueue(struct Queue* queue);
int front(struct Queue* queue);
int rear(struct Queue* queue) ;
void showArray(struct Queue* queue);

typedef struct tree
{
    int field;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
} tnode;
tnode *create( tnode *root, int field);
tnode * addnode(int key, tnode *tree);
void preorder(tnode *root);
void postorder(tnode *root);
void inorder(tnode *root);
tnode* cutTree( tnode *tree);
int isLeaf( tnode *node) ;
#endif
