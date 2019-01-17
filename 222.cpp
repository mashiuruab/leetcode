#include<iostream>
#include<cmath>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void find_left_H(TreeNode* root, int &h) {
	if(root == NULL) {
		return;
	}

	while(root != NULL) {
		h++;
		root = root->left;
	}
}

void find_right_H(TreeNode* root, int &h) {
	if(root == NULL) {
		return;
	}

	while(root != NULL) {
		h++;
		root = root->right;
	}
}

int countNodes(TreeNode* root) {
	if(root == NULL) return  0;
	TreeNode* left = root;
	TreeNode* right = root;
	int left_h = 0;
	int right_h = 0;
	
	find_left_H(left, left_h);
	find_right_H(right, right_h);

	if(left_h == right_h) {
		return pow(2, left_h) - 1;
	} else {
		return  1 + countNodes(root->left) + countNodes(root->right);
	}
} 

/*
void traverse(TreeNode* root, int &count) {
	if(root == NULL) {
		return;
	}

	count++;
	traverse(root->left, count);
	traverse(root->right, count);
}

int countNodes(TreeNode* root) {
	int count = 0;
        traverse(root, count);
	return count;
}
*/

int main(int argc, char** argv) {
	return  0;
}
