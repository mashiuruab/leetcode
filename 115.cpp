#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

queue<TreeLinkNode*> mq;

void traverse(TreeLinkNode* root) {
	if(root == NULL) {
		return;
	}

	//cout<< root->val << " ";
	
	if(root->left != NULL) {
		mq.push(root->left);
	}
	
	if(root->right != NULL) {
		mq.push(root->right);
	}

	traverse(root->left);
	traverse(root->right);
}

void connect(TreeLinkNode *root) {
        mq.push(root);
	traverse(root);

	for(int i=0;!mq.empty();i++) {
		TreeLinkNode* prev = NULL;
		for(int j=0;j<pow(2,i);j++) {
			if(mq.empty()) {
				break;
			}

			TreeLinkNode* current = mq.front();
			mq.pop();

			if(prev != NULL) {
				prev->next = current;
			}
			prev = current;
			
		}
	}
}

void  print_LL(TreeLinkNode* root) {
	if(root == NULL) {
		return;
	}

	cout<< root->val << "->";

	TreeLinkNode* temp = root;
	
	while(temp->next != NULL) {
		cout<< temp->next->val << "->";
		temp = temp->next;
	}

	if(temp->next == NULL) {
		cout << "NULL" << endl;
	}
	
	print_LL(root->left);
	print_LL(root->right);
}

int main(int argc, char** argv) {
	TreeLinkNode* root = new TreeLinkNode(1);
	TreeLinkNode* two = new TreeLinkNode(2);
	TreeLinkNode* three = new TreeLinkNode(3);
	TreeLinkNode* four = new TreeLinkNode(4);
	TreeLinkNode* five = new TreeLinkNode(5);
	TreeLinkNode* seven = new TreeLinkNode(7);

	two->left = four;
	two->right = five;
	three->right = seven;
	root->left = two;
	root->right = three;

	connect(root);

	print_LL(root);

	return 0;
}
