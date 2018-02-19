#include <bits/stdc++.h>

using namespace std;

struct tree {
	int data;
	tree* left;
	tree* right;	
};

tree* insert_node(tree *ptree, int temp) {
	if (!ptree) {
		tree *newnode = new tree;
		newnode->data = temp;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}
	if (temp < ptree->data)
		ptree->left = insert_node(ptree->left, temp);
	else
		ptree->right = insert_node(ptree->right, temp);
	return ptree;
}

tree *input_tree(int n) {
	int i, temp;
	tree *ptree = new tree;
	cin >> ptree->data;
	ptree->left = NULL;
	ptree->right = NULL;
	for (i=1;i<n;i++) {
		cin >> temp;
		insert_node(ptree, temp);
	}
	return ptree;
}

int compare_tree(tree *t1, tree *t2) {
	if (t1 == NULL && t2 == NULL)
		return 1;
	if (t1->data == t2->data)
		return compare_tree(t1->left, t2->left) * compare_tree(t1->right, t2->right);
	return 0;
}

int free_tree(tree *t) {
	if (t) {
		free_tree(t->left);
		free_tree(t->right);		
	}
	delete t;
}

int judge() {
	int i, n, l;
	tree *t1 , *t2;
	cin >> n;
	if (!n)
		return n;
	cin >> l;
	t1 = input_tree(n);
	for (i=0;i<l;i++) {
		t2 = input_tree(n);
		if (compare_tree(t1, t2))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		free_tree(t2);
	}
	free_tree(t1);
	return n;
}

int main() {
	while (judge());
	return 0;
}