#include<iostream>
#include<vector>


using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(TreeNode* root, int level, vector<int> &lv) {
	if(root == NULL) return;

	if(lv.size() <= level) {
		lv.push_back(root->val);
	}

	level++;

	traverse(root->left,level, lv);
	traverse(root->right, level, lv);
}

int findBottomLeftValue(TreeNode* root) {
        vector<int> level_value;

	traverse(root, 0, level_value);

	return level_value[level_value.size() - 1];
}

int main(int argc, char** argv) {
	return 0;
}
