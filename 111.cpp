#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int  minimum = INT_MAX;

void traverse(TreeNode* root, int& length) {
	if(root == NULL) {		
		return;
	}

	int left = length + 1;
	int right = length + 1;

	traverse(root->left, left);
	traverse(root->right, right);

	if(root->left == NULL && root->right == NULL) {
		if(length + 1 < minimum) {
			minimum = length + 1;
		}
	}
}

int minDepth(TreeNode* root) {
	if(root == NULL) return 0;

	int length = 0;
	traverse(root, length);

	return minimum;        
}

int main(int argc, char** argv) {
	TreeNode* root = new TreeNode(1);
	TreeNode* newNode = new TreeNode(2);
	root->left = newNode;
	root->right = NULL;

	cout<< minDepth(root) << endl;
	return 0;
}
