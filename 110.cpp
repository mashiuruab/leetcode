#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool is_balanced = true;

void traverse(TreeNode* root, int& height) {
	if(root == NULL) return;

	int left = height + 1;
	int right = height + 1;

	traverse(root->left,  left);
	traverse(root->right, right);

	height = (left > right) ? left : right;
	
	int diff = abs(left - right);
	bool is_ok = (diff == 0 || diff == 1);

	is_balanced &= is_ok;
}

bool isBalanced(TreeNode* root) {
	int height  = 0;

	traverse(root, height);

	return is_balanced;
}

int main(int argc, char** argv) {

}
