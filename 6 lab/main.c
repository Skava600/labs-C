#include <stdio.h>
#include "Tree.h"
void printInForms(tnode* root)
{
    printf("\n\nTree in order\n");
    inorder(root);
    printf("\n\nTree in postorder\n");
    postorder(root);
    printf("\n\nTree in preorder\n");
    preorder(root);
}
void print(tnode *tree,int level)
{
    if(tree)
    {
        print(tree->left,level + 1);
        int i = 0;
        for(;i< level;i++)
            printf("   ");
        printf("%d\n",tree->field);
        print(tree->right,level + 1);
    }
}
int main()
{
    struct Queue* queue = createQueue(100);
    enQueue(queue, 21);
    enQueue(queue, 7);
    enQueue(queue, 32);
    enQueue(queue, 5);
    enQueue(queue, 14);
    enQueue(queue, 27);
    enQueue(queue, 37);
    enQueue(queue, 4);
    enQueue(queue, 6);
    enQueue(queue, 25);
    enQueue(queue, 30);
    showArray(queue);
    tnode* root;
    root = NULL;
    int  i = queue->front;
    root = create(root, queue->array[i]);
    i++;
    do
    {
        addnode(queue->array[i], root);
        i++;
    }while(i <= queue->rear);
    print(root, 0);
    printInForms(root);
    printf("\n\nCutted leafs:\n");
    cutTree(root);
    printf("\n\nTree after cutting:");
    printInForms(root);
    return 0;
}
