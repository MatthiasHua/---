#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
	ElementType Adress;
	ElementType Data;
	PtrToNode Next;
};
typedef struct {
	int data;
	int next;
} MemeryNode;

void Print(PtrToNode head);
PtrToNode resever(PtrToNode head, int K);

int main() {
	MemeryNode memery[MAX];
	int i, j, cnt = 0;
	int f, n, k;
	int adress, data, next;
	PtrToNode head = (PtrToNode)malloc(sizeof(struct Node));
	PtrToNode p = head;
	scanf("%d %d %d", &f, &n, &k);
	for (i=0;i<n;i++) {
		scanf("%d %d %d", &adress, &data, &next);
		memery[adress].data = data;
		memery[adress].next = next;
	}
	while (f != -1) {
		cnt ++;
		p->Next = (PtrToNode)malloc(sizeof(struct Node));
		p = p->Next;
		p->Next = NULL;
		p->Adress = f;
		p->Data = memery[f].data;	
		f = memery[f].next;
	}
	head->Next = resever(head, k);
	p = head;
	for (i=1;i<cnt/k;i++) {
		for (j=0;j<k;j++)
			p = p->Next;
		p->Next = resever(p, k);
	}
	Print(head);
	return 0;

}

void Print(PtrToNode head) {
	while (head->Next != NULL) {
		head = head->Next;
		if (head->Next != NULL)
			printf("%05d %d %05d\n", head->Adress, head->Data, head->Next->Adress);
		else 
			printf("%05d %d %d\n", head->Adress, head->Data, -1);			
	}
}

PtrToNode resever(PtrToNode head, int K) {
	PtrToNode new = head->Next;
	PtrToNode old = new->Next;
	PtrToNode temp;
	int i;
	for (i=1;i<K;i++) {
		temp = old->Next;
		old->Next = new;
		new = old;
		old = temp;
	}
	head->Next->Next = old;
	return new;
}