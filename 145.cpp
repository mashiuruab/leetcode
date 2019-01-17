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

	traverse(result, root->left);
	traverse(result, root->right);
	result.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
	
	traverse(result, root);

	return result;
}

int main(int argc, char** argv) {
	
	return 0;
}
