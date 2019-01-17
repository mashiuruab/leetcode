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

bool found = false;

void traverse(TreeNode* root, int sum, int temp_sum) {
	if(root == NULL) {
		return;
	} else if (found) {
		return;
	}

	temp_sum += root->val;

	traverse(root->left, sum, temp_sum);
	traverse(root->right, sum, temp_sum);

	if(root->left == NULL && root->right == NULL) {
		found = found  || (temp_sum == sum);
	}
}

bool hasPathSum(TreeNode* root, int sum) {
	if(root == NULL) return  false;
	traverse(root,sum,0);
	return found;
}

int main(int argc, char** argv) {
	TreeNode* root = new TreeNode(1);
	TreeNode* newNode = new TreeNode(2);
	root->left =  newNode;
	root->right = NULL;

	cout<< hasPathSum(root, 1) << endl;
	return 0;
}
