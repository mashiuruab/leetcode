#include<iostream>
#include<string>
#include<vector>
#include<cassert>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class m_stack {
public:
	vector<TreeNode*> mem;

	void push(TreeNode* value) {
		mem.push_back(value);
	}

	TreeNode* pop() {
		TreeNode* back = mem.back();
		mem.pop_back();
		return back;
	}

	bool empty() {
		return mem.size() == 0;
	}
};

vector<int> result;
m_stack stack;

void traverse(TreeNode* root) {
	if(root == NULL) {
		return;
	}

	traverse(root->left);
	//if(root->left != NULL) result.push_back(root->left->val);

	result.push_back(root->val);

	traverse(root->right);
	//if(root->right != NULL) result.push_back(root->right->val);
}

void t_left(TreeNode* root) {
	while(root != NULL || !stack.empty()){
		if(root == NULL) {
			TreeNode* temp = stack.pop();
			result.push_back(temp->val);
			root  = temp->right;
			continue;
		} else {
			stack.push(root);
			root = root->left;
		}
	}
}

vector<int> inorderTraversal(TreeNode* root) {
	//traverse(root);
	t_left(root);
	return result;
}

int main(int argc, char** argv) {
	return 0;
}
