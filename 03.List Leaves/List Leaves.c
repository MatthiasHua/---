#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
	int left;
	int right;
} Node;

int t(char c);
int Read(Node tree[]);
void traversalNode(Node tree[], int list[]);

int main() {
	int i, Root;
	Node tree[MAX];
	int list[MAX+3] = {0};
	Root = Read(tree);
	list[0] = Root;
	traversalNode(tree, list);
	for (i=0;i<list[MAX+2]-1;i++)
		printf("%d ", list[i]);
	printf("%d\n", list[list[MAX+2]-1]);
	return 0;
}

int Read(Node tree[]) {
	int i, n;
	char l, r;	
	int check[MAX] = {0};
	scanf("%d", &n);
	getchar();
	for (i=0;i<n;i++) {
		scanf("%c %c", &l, &r);
		getchar();
		tree[i].left = t(l);
		if (tree[i].left != -1)
			check[tree[i].left] = 1;
		tree[i].right = t(r);
		if (tree[i].right != -1)
			check[tree[i].right] = 1;
	}
	i=0;
	while (i<n) {
		if (check[i] == 0)
			return i;
		i++;
	}
}

void traversalNode(Node tree[MAX], int list[MAX+3]) {
	int left = list[MAX], right = list[MAX+1];
	if (left > right) 
		return;
	int parent = list[left];
	left ++;
	if (tree[parent].left == -1 && tree[parent].right == -1) {
		list[list[MAX+2]] = parent;
		list[MAX+2] ++;
	}
	if (tree[parent].left != -1) {
		right ++;
		list[right]  = tree[parent].left;
	}
	if (tree[parent].right != -1) {
		right ++;
		list[right]  = tree[parent].right;
	}
	list[MAX] = left;
	list[MAX+1] = right;
	int i;
	traversalNode(tree, list);

}

int t(char c) {
	if (c == '-')
		return -1;
	else 
		return c-'0';
}