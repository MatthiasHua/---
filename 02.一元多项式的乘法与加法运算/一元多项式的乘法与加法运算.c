#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Base;
	ElementType Index;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read();
void Print(List L);
List Add(List L1, List L2);
List Multiply(List L1, List L2);

int main() {
	List L1 = Read();
	List L2 = Read();
    List Sum = Add(L1,L2);
    List Product = Multiply(L1,L2);    
	Print(Product);
    Print(Sum);
	return 0;
}

List Read() {
    int i, len;
    List L = (List)malloc(sizeof(struct Node));
    scanf("%d", &len);
    PtrToNode p = (PtrToNode)L;
    for (i=0;i<len;i++) {
        p->Next = (PtrToNode)malloc(sizeof(struct Node));
        p = p->Next;
        p->Next = NULL;
        scanf("%d %d", &(p->Base), &(p->Index));        
    }
    return L;
}

void Print(List L) {
    if (L->Next == NULL) {
        printf("NULL\n");
    }
    else {
        PtrToNode p = L->Next;
        do {
            printf("%d %d ", p->Base, p->Index);
            p = p->Next;
        } while (p != NULL);
        printf("\n");
    }
}

void insert(List L, ElementType base, ElementType index) {
    PtrToNode p = (PtrToNode)L;
    while (p->Next != NULL) {
        if (index > p->Next->Index) {
            PtrToNode temp =  (PtrToNode)malloc(sizeof(struct Node));
            temp->Next = p->Next;
            p->Next = temp;
            temp->Base = base;
            temp->Index = index;
            return;        
        }
        if (p->Next->Index == index) {
            p->Next->Base += base;
            return;
        }
        p = p->Next;
    }
    p->Next = (PtrToNode)malloc(sizeof(struct Node));
    p = p->Next;
    p->Base = base;
    p->Index = index;
    p->Next = NULL;
}

List Multiply(List L1, List L2) {
    List L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    PtrToNode p1 = (PtrToNode)L1, p2 = (PtrToNode)L2;
    while (p1->Next != NULL) {
        p1 = p1->Next;
        p2 = (PtrToNode)L2;
        while (p2->Next != NULL) {
            p2 = p2 -> Next;
            insert(L, p1->Base * p2->Base, p1->Index + p2->Index);
        }
    }
    return L; 
}

List Add(List L1, List L2) {
    List L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    PtrToNode p1 = (PtrToNode)L1, p2 = (PtrToNode)L2;
    while (p1->Next != NULL) {
        p1 = p1->Next;
        insert(L, p1->Base, p1->Index);
    }
    while (p2->Next != NULL) {
        p2 = p2->Next;
        insert(L, p2->Base, p2->Index);
    }
    return L; 
}