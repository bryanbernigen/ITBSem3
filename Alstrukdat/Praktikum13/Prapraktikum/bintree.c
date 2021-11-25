/*
NIM             : 13520034
Nama            : Bryan Bernigen
Tanggal         : 11 November 2021
Topik praktikum : Binary Tree
Deskripsi       : prapraktikum untuk praktikum 13 dengan topik yang sama
*/

#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree NewTree(ElType root, BinTree left_tree, BinTree right_tree)
{
    BinTree p = (BinTree)malloc(sizeof(TreeNode));
    if (p != NULL)
    {
        ROOT(p) = root;
        LEFT(p) = left_tree;
        RIGHT(p) = right_tree;
    }
    return p;
};

void CreateTree(ElType root, BinTree left_tree, BinTree right_tree, BinTree *p)
{
    *p = (BinTree)malloc(sizeof(TreeNode));
    if (*p != NULL)
    {
        ROOT(*p) = root;
        LEFT(*p) = left_tree;
        RIGHT(*p) = right_tree;
    }
};

Address newTreeNode(ElType val)
{
    Address p = (Address)malloc(sizeof(TreeNode));
    if (p != NULL)
    {
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
    return p;
};

void deallocTreeNode(Address p)
{
    LEFT(p) = NULL;
    RIGHT(p) = NULL;
    free(p);
};

boolean isTreeEmpty(BinTree p)
{
    return (p == NULL);
};

boolean isOneElmt(BinTree p)
{
    return (!isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) == NULL);
};

boolean isUnerLeft(BinTree p)
{
    return (!isTreeEmpty(p) && LEFT(p) != NULL && RIGHT(p) == NULL);
};

boolean isUnerRight(BinTree p)
{
    return (!isTreeEmpty(p) && LEFT(p) == NULL && RIGHT(p) != NULL);
};

boolean isBinary(BinTree p)
{
    return (!isTreeEmpty(p) && LEFT(p) != NULL && RIGHT(p) != NULL);
};

void printPreorder(BinTree p)
{
    printf("(");
    if (!isTreeEmpty(p))
    {
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
}
void printInorder(BinTree p)
{
    printf("(");
    if (!isTreeEmpty(p))
    {
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");
}
void printPostorder(BinTree p)
{
    printf("(");
    if (!isTreeEmpty(p))
    {
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
}

void printTreeHelp(BinTree p, int h, int space)
{
    int i;
    if (!isTreeEmpty(p))
    {
        for (i = 0; i < space; i++)
            printf(" ");
        printf("%d\n", ROOT(p));
        printTreeHelp(LEFT(p), h, space + h);
        printTreeHelp(RIGHT(p), h, space + h);
    }
}

void printTree(BinTree p, int h)
{
    if (!isTreeEmpty(p))
    {
        printf("%d\n", ROOT(p));
        printTreeHelp(LEFT(p), h, h);
        printTreeHelp(RIGHT(p), h, h);
    }
};
