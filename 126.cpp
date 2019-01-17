#include<iostream>
#include<climits>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int max_value = INT_MIN;

void traverse(TreeNode* root, int& value) {
	if(root == NULL) {
		return;
	}

	int left = 0;
	int right = 0;

	//cout << root->val << " ";

	traverse(root->left, left);
	traverse(root->right, right);

	int node_value = root->val  + left + right;
	int node_left = root->val + left;
	int node_right = root->val + right;
	value += node_value;
	
	
	if(left != 0 && left > max_value) {
		max_value = left;
		//cout << "max value set 1 = " << max_value << endl;
	}

	if(right != 0 && right > max_value) {
		max_value = right;
		//cout << "max value set 2 = " << max_value << endl;
	}

	if(value > max_value) {
		max_value = value;
		//cout << "max value set 3 = " << max_value << endl;
	}

	if(node_value > max_value) {
		max_value = node_value;
		//cout << "max value set 4 = " << max_value << endl;
	}

	if(root->val > max_value) {
		max_value = root->val;
		//cout << "max value set 4 = " << max_value << endl;
	}

	if(node_left > max_value) {
		max_value = node_left;
	}

	if(node_right > max_value) {
		max_value = node_right;
	}
}

int maxPathSum(TreeNode* root) {
	if(root == NULL) {
		return 0;
	}

	int value = 0;
	traverse(root, value);

	//cout << "Testing max = " << max_value << ", value = " << value << endl;

	return max_value;       
}

int main(int argc, char** argv) {
	TreeNode* root = new TreeNode(-10);
	TreeNode* nine = new TreeNode(9);
	TreeNode* twenty = new TreeNode(20);
	TreeNode* fifteen = new TreeNode(15);
	TreeNode* seven = new TreeNode(7);

	twenty->left = fifteen;
	twenty->right = seven;
	root->left = nine;
	root->right = twenty;

	maxPathSum(root);

	return 0;
}
