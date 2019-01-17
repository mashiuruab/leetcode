#include<iostream>

using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traverse(TreeNode* p, TreeNode* q, bool &is_same) {
	if(p == NULL && q == NULL) return;

	if(p == NULL || q == NULL) {
		is_same &= false;
		return;
	}

	is_same &= (p->val == q->val);

	if(!is_same) return;

	traverse(p->left, q->left, is_same);

	if(!is_same) return;

	traverse(p->right, q->right, is_same);
}

bool isSameTree(TreeNode* p, TreeNode* q) {
        bool is_same = true;

	traverse(p, q, is_same);

	return is_same;
}

int main(int argc, char** argv) {
	return 0;
}
