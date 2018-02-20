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