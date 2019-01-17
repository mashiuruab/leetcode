#include<iostream>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(TreeNode* root, vector<vector<int>> &rc, int level) {
	if(root == NULL) return;

	if(rc.size() <= level) {
		vector<int> temp;
		rc.push_back(temp);
	}

	rc[level].push_back(root->val);

	level++;

	traverse(root->left, rc, level);
	traverse(root->right, rc, level);
}

vector<int> rightSideView(TreeNode* root) {
	vector<vector<int>> rc;

	traverse(root, rc, 0);

	vector<int> result;

	for(int i = 0; i < rc.size(); i++) {
		vector<int> temp = rc[i];
		result.push_back(temp[temp.size() - 1]);
	}

	return result;
}

int main(int argc, char** argv) {
	return 0;
}
