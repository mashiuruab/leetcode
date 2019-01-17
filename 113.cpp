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

vector<vector<int>> result;
int org_sum;

void traverse(TreeNode* root, int temp_sum, vector<int> path) {
	if(root == NULL) {		
		return;
	}

	temp_sum += root->val;

	path.push_back(root->val);

	traverse(root->left, temp_sum, path);
	traverse(root->right, temp_sum, path);

	if((root->left == NULL && root->right == NULL) && (temp_sum == org_sum)) {
		result.push_back(path);
	}
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL) {
		return result;
	}

	org_sum = sum;
	vector<int> path;
	traverse(root, 0, path);

	return result;
}

int main(int argc, char** argv) {
	return 0;
}
