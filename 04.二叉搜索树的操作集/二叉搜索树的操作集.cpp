#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT );
void InorderTraversal( BinTree BT );

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");
    return 0;
}

void PreorderTraversal(BinTree BST) {
    if (BST) {
        printf("%d ", BST->Data);
        PreorderTraversal(BST->Left);
        PreorderTraversal(BST->Right); 
    }
}

void InorderTraversal( BinTree BST ) {
    if (BST) {
        PreorderTraversal(BST->Left);
        printf("%d ", BST->Data);
        PreorderTraversal(BST->Right); 
    } 
}

BinTree Insert(BinTree BST, ElementType X) {
    if (!BST) {
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
        return BST;
    }
    if (X < BST->Data)
        BST->Left = Insert(BST->Left, X);
    else
        BST->Right = Insert(BST->Right, X);
    return BST;
}

BinTree Delete( BinTree BST, ElementType X ) {
    BinTree Tmp;
    if (!BST) {
        printf("Not Found\n");
        return BST;
    }
    if (BST->Data == X) {
        if (BST->Left && BST->Right) {
            Tmp  = BST->Right;
            FindMax(BST->Left)->Right = Tmp->Left;
            Tmp->Left = BST->Left;            
        }
        else if (BST->Left)
            Tmp  = BST->Left;
        else if (BST->Right)
            Tmp  = BST->Right;        
        else 
            Tmp = NULL;
        free(BST);
        return Tmp;
    }

    if (X < BST->Data)
        BST->Left = Delete(BST->Left, X);
    else
        BST->Right = Delete(BST->Right, X);
    return BST;
}

Position Find( BinTree BST, ElementType X ) {
    if (BST) {
        if (X ==BST->Data)
            return BST;
        if (X < BST->Data)
            return Find(BST->Left, X);
        else 
            return Find(BST->Right, X);
    }
    return BST;
}

Position FindMin( BinTree BST ) {
    if (!BST)
        return NULL;
    if (BST->Left)
        return FindMin(BST->Left);
    return BST;
}

Position FindMax( BinTree BST ) {
    if (!BST)
        return NULL;
    if (BST->Right)
        return FindMax(BST->Right);
    return BST;
}