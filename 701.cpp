#include<iostream>
#include<map>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(TreeNode* root, int val) {
	if(root->val < val) {
		if(root->right == NULL) {
			TreeNode* newNode = new TreeNode(val);
			root->right = newNode;
			return;
		}

		traverse(root->right, val);
	} else {
		if(root->left == NULL) {
			TreeNode* newNode = new TreeNode(val);
			root->left = newNode;
			return;
		} else {
			traverse(root->left, val);
		}
	}
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
        traverse(root, val);
	return root;
}

int main(int argc, char** argv){
	return  0;
}
