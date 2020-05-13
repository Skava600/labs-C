#include "tree.h"
#pragma once
/***СОЗДАТЬ очередь*************************/

struct Queue* createQueue(int capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = -1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

/* ОЧЕРЕДЬ ПОЛНА КОГДА SIZE == ВМЕСТИМОСТИ(CAPASITY)*/
int isFull(struct Queue* queue)
{  return (queue->size == queue->capacity);  }

/* ОЧЕРЕДЬ ПУСТА КОГДА SIZE == 0*/
int isEmpty(struct Queue* queue)
{  return (queue->size == 0); }


/* ДОБАВИТЬ ЭЛЕМЕНТ В КОНЕЦ ОЧЕРЕДИ*/
void enQueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size += 1;
}

/* УДАЛИТЬ ЭЛЕМЕНТ ИЗ НАЧАЛА СПИСКА*/
int deQueue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size -= 1;
    return item;
}

/*ПОКАЗАТЬ МАССИВ*/
void showArray(struct Queue* queue)
{
    printf("\n Queue:\n");
    int k = queue->front;
    for( ; k <= queue->rear; k++)
    {
        printf("%d\t", queue->array[k]);
    }
    printf("\n");
}



/* ПОЛУЧИТЬ ПЕРЕДНИЙ ОБЪЕКТ ОЧЕРЕДИ*/
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

/* ПОЛУЧИТЬ ХВОСТОВОЙ ОБЪЕКТ ОЧЕРЕДИ*/
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}



/****СОЗДАТЬ ДЕРЕВО**************************/

tnode *create( tnode *root, int field)
{
    /* Выделение памяти под корень дерева*/
    tnode *tmp = malloc(sizeof(tnode));
/* Присваивание значения ключу*/
    tmp -> field = field;
/* Присваивание указателю на родителя значения NULL*/
    tmp -> parent = NULL;
/* Присваивание указателю на левое и правое поддерево значения NULL*/
    tmp -> left = tmp -> right = NULL;
    root = tmp;
    return root;
}
/****************************************/

/**********ДОБАВЛЕНИЕ УЗЛА В ДЕРЕВО*/
tnode * addnode(int key, tnode *tree)
{
    tnode *root2 = tree, *root3 = NULL;
   /* Выделение памяти под узел дерева*/
    tnode *tmp = malloc(sizeof(tnode));
   /* Присваивание значения ключу*/
       tmp -> field = key;
   /* Поиск нужной позиции для вставки*/
       while (root2 != NULL)
       {
           root3 = root2;
           if (key < root2 -> field)
               root2 = root2 -> left;
           else
               root2 = root2 -> right;
       }
       /*// Присваивание указателю на родителя значения указателя root3*/
       tmp -> parent = root3;
       /* // Присваивание указателю на левое и правое поддерево значения NULL*/
       tmp -> left = NULL;
       tmp -> right = NULL;
       /* Вставляем узел в дерево (руководствуемся правилом
   вставки элементов, см. начало статьи, пункт 3) */
       if (key < root3 -> field) root3 -> left = tmp;
       else root3 -> right = tmp;
       return tree;
   }
/*******************************************\*/

/*ОБРЕЗКА ДЕРЕВА*/
tnode* cutTree( tnode* tree)
{
    if (tree == NULL)
            return NULL;
   if (tree->left == NULL && tree->right == NULL  && tree->parent->left == tree && tree->parent->right != NULL)
   {
       printf("%d ",tree->field);
       tree->parent->left = NULL;
       free(tree->parent->left);
       return NULL;
    }
    tree->right = cutTree(tree->right);
    tree->left = cutTree(tree->left);
    return tree;
}
/*****************************************/

/* ПРОВЕРКА НА ЛИСТ*/
int isLeaf(tnode *node)
{
   if (node == NULL)
       return 0;
   if (node->left == NULL && node->right == NULL)
       return 1;
   return 0;
}
/******************************************/

/*/ВЫВОД ДЕРЕВЬЕВ В РАЗЛИЧНОМ ВИДЕ*/
void preorder(tnode *root)
{
    if (root == NULL)
        return;
    if (root -> field)
        printf("%d ", root -> field);
    preorder(root -> left);
    preorder(root -> right);
}
void postorder(tnode *root)
{
    if (root == NULL)
        return;
    postorder(root -> left);
    postorder(root -> right);
    if (root -> field)
        printf("%d ", root -> field);
}
void inorder(tnode *root)
{
    if (root == NULL)
        return;
    inorder(root -> left);
    if (root -> field)
        printf("%d ", root -> field);
    inorder(root -> right);
}
/***************************************************************************/
