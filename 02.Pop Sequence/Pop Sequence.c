#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct Stack{
	int stack[MAX];
	int top;
}* PtrStack;

void check(int m, int n);
void push(PtrStack s, int p);
int pop(PtrStack s);

int main() {
	int i, m, n, k;
	scanf("%d %d %d", &m, &n, &k);
	for (i=0;i<k;i++)
		check(m, n);
	return 0;
}

void check(int m, int n) {
	int i, next = 0, temp;
	int list[MAX];
	PtrStack s = (PtrStack)malloc(sizeof(struct Stack));
	s->top = -1;
	for (i=0;i<n;i++) {
		scanf("%d", &list[i]);
	}
	for (i=0;i<n;i++) {
		if (list[i] >= next+1)
			if (list[i] - next + s->top <m) {
				for (next=next+1;next<=list[i];next++) 
					push(s, next);
				next --;
				pop(s);
			}
			else {
				printf("NO\n");
				return;
			}
		else {
			temp = pop(s);
			if (list[i] != temp) {
				printf("NO\n");
				return;
			}
		}
	}
	printf("YES\n");
}

void push(PtrStack s, int p) {
	s->top ++;
	s->stack[s->top] = p;
}

int pop(PtrStack s) {
	s->top --;
	return s->stack[s->top+1];
}