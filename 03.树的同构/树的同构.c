#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct Node {
	int left;
	int right;
	char name;
} TreeNode;

int Read(TreeNode T[]);
int check(TreeNode T1[], int Root1, TreeNode T2[], int Root2);

int main()
{
	TreeNode* T1 = malloc(MAX * sizeof(struct Node)), * T2 = malloc(MAX * sizeof(struct Node));
	int Root1, Root2;
	Root1 = Read(T1);
	Root2 = Read(T2);
	if (check(T1, Root1, T2, Root2) == 1)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}

int check(TreeNode T1[], int Root1, TreeNode T2[], int Root2) {
	if (Root1 == -1 && Root2 == -1)
		return 1;
	if (Root1 == -1 || Root2 == -1) 
		return 0;
	if (T1[Root1].name != T2[Root2].name) 
		return 0;
	int c1 = check(T1, T1[Root1].left, T2, T2[Root2].left);
	int c2 = check(T1, T1[Root1].right, T2, T2[Root2].right);
	int c3 = check(T1, T1[Root1].left, T2, T2[Root2].right);
	int c4 = check(T1, T1[Root1].right, T2, T2[Root2].left);
	return (c1 && c2) || (c3 && c4);
}

int cToi(char c) {
	if (c == '-')
		return -1;
	else 
		return c-'0';
}

int Read(TreeNode T[]) {
	int i, n;
	char cl, cr;
	int check[MAX] = {0};
	scanf("%d", &n);
	getchar();
	if (n == 0)
		return -1;

	for (i=0;i<n;i++) {
		scanf("%c %c %c", &T[i].name, &cl, &cr);
		getchar();
		T[i].left = cToi(cl);
		T[i].right = cToi(cr);
		if (T[i].left != -1)
			check[T[i].left] = 1;
		if (T[i].right != -1)
			check[T[i].right] = 1;
	}
	i=0;
	while (check[i])
		i++;
	return i;
}