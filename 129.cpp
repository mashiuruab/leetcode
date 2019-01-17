#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<string> container;

void traverse(TreeNode* root, string& path) {
	if(root == NULL) {
		return;
	}

	string left = path + to_string(root->val);
	string right = path + to_string(root->val);
	
	traverse(root->left, left);
	traverse(root->right, right);

	if(root->left == NULL && root->right == NULL) {
		path = path + to_string(root->val);
		container.push_back(path);
	}
}

int sumNumbers(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	string  path = "";

	traverse(root, path);

	int total_sum = 0;

	for(int i=0;i<container.size();i++){
		total_sum += stoi(container[i]);
	}

	return total_sum;
}

int main(int argc, char** argv) {
	return  0;
}
