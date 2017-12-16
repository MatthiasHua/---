List Merge(List L1, List L2) {
    List L = (List)malloc(sizeof(struct Node));
    PtrToNode p = L;
    while (L1->Next != NULL || L2->Next != NULL) {
        if (L1->Next != NULL && L2->Next != NULL) {
            p->Next = (PtrToNode)malloc(sizeof(struct Node));
            p = p->Next;
            p ->Next = NULL;    
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