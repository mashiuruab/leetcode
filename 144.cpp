#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(vector<int> &result, TreeNode* root) {
	if(root == NULL) {
		return;
	}

	result.push_back(root->val);
	traverse(result, root->left);
	traverse(result, root->right);
}

vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
	
	traverse(result, root);

	return result;
}

int main(int argc, char** argv) {
	
	return 0;
}
