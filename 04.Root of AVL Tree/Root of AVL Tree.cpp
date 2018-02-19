#include <bits/stdc++.h>

using namespace std;

struct tree {
	int data, height;
	tree *left, *right;	
};

int max(int a, int b) {
	if (a > b) 
		return a;
	else 
		return b;
}

int height(tree *ptree) {
	if (!ptree)
		return 0;
	else 
		return ptree->height;
}

tree *LL(tree *ptree) {
	tree *leftnode = ptree->left;
	ptree->left = leftnode->right;
	leftnode->right = ptree;
	ptree->height = max(height(ptree->left), height(ptree->right)) + 1;
	leftnode->height = max(height(leftnode->left), height(leftnode->right)) + 1;
	return leftnode;
}

tree *RR(tree *ptree) {
	tree *rightnode = ptree->right;
	ptree->right = rightnode->left;
	rightnode->left = ptree;
	ptree->height = max(height(ptree->left), height(ptree->right)) + 1;
	rightnode->height = max(height(rightnode->left), height(rightnode->right)) + 1;
	return rightnode;
}

tree *LR(tree *ptree) {
	ptree->left = RR(ptree->left);
	return LL(ptree);
}

tree *RL(tree *ptree) {
	ptree->right = LL(ptree->right);
	return RR(ptree);
}

tree *insert_node(int temp, tree *ptree) {
	if (!ptree) {
		tree *newnode = new tree;
		newnode->height = 1;
		newnode->data = temp;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;	
	}
	if (temp < ptree->data) {
		ptree->left = insert_node(temp, ptree->left);
		if (height(ptree->left) - height(ptree->right) > 1) {
			if (temp < ptree->left->data)
				ptree = LL(ptree);
			else 
				ptree = LR(ptree);
		}
	}
	else {
		ptree->right = insert_node(temp, ptree->right);
		if (height(ptree->right) - height(ptree->left) > 1) {
			if (temp > ptree->right->data)
				ptree = RR(ptree);
			else 
				ptree = RL(ptree);
				
		}
	}
	ptree->height = max(height(ptree->left), height(ptree->right)) + 1;
	return ptree;
}

int main() {
	int i, n, temp;
	cin >> n;
	if (!n) 
		return 0;
	tree *ptree = new tree;
	cin >> ptree->data;
	ptree->height = 1;
	ptree->left = NULL;  
	ptree->right = NULL;
	for (i=1;i<n;i++) {
		cin >> temp;
		ptree = insert_node(temp, ptree);
	}
	cout << ptree->data << endl;
	return 0;
}