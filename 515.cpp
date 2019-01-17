#include<iostream>
#include<vector>


using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(TreeNode* root, int level, vector<int> &result) {
	if(root == NULL) return;

	if(result.size() <= level) {
		result.push_back(root->val);
	}

	if(root->val > result[level]) {
		result[level] = root->val;
	}

	level++;

	traverse(root->left, level, result);
	traverse(root->right, level, result);
}

vector<int> largestValues(TreeNode* root) {
        vector<int> result;

	traverse(root, 0, result);

	return result;
}

int main(int argc, char** argv) {
	return 0;
}
