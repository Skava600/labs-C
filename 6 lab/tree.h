#ifndef TREE_H
#define TREE_H


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "que.h"
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
//struct tnode* createTree(void);
#endif
