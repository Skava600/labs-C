#include "tree.h"
#pragma once
//***СОЗДАТЬ ДЕРЕВО*************************
tnode *create( tnode *root, int field)
{
// Выделение памяти под корень дерева
    tnode *tmp = malloc(sizeof(tnode));
// Присваивание значения ключу
    tmp -> field = field;
// Присваивание указателю на родителя значения NULL
    tmp -> parent = NULL;
// Присваивание указателю на левое и правое поддерево значения NULL
    tmp -> left = tmp -> right = NULL;
    root = tmp;
    return root;
}
//***************************************

//*********ДОБАВЛЕНИЕ УЗЛА В ДЕРЕВО
tnode * addnode(int key, tnode *tree)
{
    tnode *root2 = tree, *root3 = NULL;
   // Выделение памяти под узел дерева
    tnode *tmp = malloc(sizeof(tnode));
   // Присваивание значения ключу
       tmp -> field = key;
   // Поиск нужной позиции для вставки
       while (root2 != NULL)
       {
           root3 = root2;
           if (key < root2 -> field)
               root2 = root2 -> left;
           else
               root2 = root2 -> right;
       }
   // Присваивание указателю на родителя значения указателя root3
       tmp -> parent = root3;
   // Присваивание указателю на левое и правое поддерево значения NULL
       tmp -> left = NULL;
       tmp -> right = NULL;
   /* Вставляем узел в дерево (руководствуемся правилом
   вставки элементов, см. начало статьи, пункт 3) */
       if (key < root3 -> field) root3 -> left = tmp;
       else root3 -> right = tmp;
       return tree;
   }
//******************************************\

//ОБРЕЗКА ДЕРЕВА
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
//***************************************

// ПРОВЕРКА НА ЛИСТ
int isLeaf(tnode *node)
{
   if (node == NULL)
       return 0;
   if (node->left == NULL && node->right == NULL)
       return 1;
   return 0;
}
//*****************************************

//ВЫВОД ДЕРЕВЬЕВ В РАЗЛИЧНОМ ВИДЕ
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
//**************************************************************************
