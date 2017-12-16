#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read();
void Print(List L);
PtrToNode NewNode(PtrToNode p);

List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read() {
    int i, len;
    List L = (List)malloc(sizeof(struct Node));
    PtrToNode p = (PtrToNode) L;
    scanf("%d", &len);
    for (i=0;i<len;i++) {
        p = NewNode(p);
        scanf("%d", &(p->Data));      
    }
    return L;
}

void Print(List L) {
    if (L->Next == NULL) {
        printf("NULL\n");
    }
    else {
        PtrToNode p = (PtrToNode)L;
        while (p->Next != NULL) {
            p = p->Next;
            printf("%d ", p->Data);
        }
        printf("\n");
    }
}

PtrToNode NewNode(PtrToNode p) {
    p->Next = (PtrToNode)malloc(sizeof(struct Node));
    p = p->Next;
    p ->Next = NULL;    
    return p;
}

List Merge(List L1, List L2) {
    List L = (List)malloc(sizeof(struct Node));
    PtrToNode p = L;
    while (L1->Next != NULL || L2->Next != NULL) {
        if (L1->Next != NULL && L2->Next != NULL) {
            p = NewNode(p);
            if (L1->Next->Data > L2->Next->Data) {
                p->Data = L2->Next->Data;
                L2->Next = L2->Next->Next;
            }
            else 
                p->Data = L1->Next->Data; {
                L1->Next = L1->Next->Next;
            }
        }
        else if (L1->Next == NULL) {
            p->Next = L2->Next;
            L2->Next = NULL;
        }
        else {
            p->Next = L1->Next;
            L1->Next = NULL;           
        }
    }
    return L;
}