#include<iostream>

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void divide(ListNode* root, ListNode* &middle, ListNode* &left, ListNode* &right) {
	if(root->next == NULL) {
		middle = root;
		left = NULL;
		right = NULL;
		return;
	}

	ListNode* slow = root;
	ListNode* fast = root;
	ListNode* prev_slow = NULL;

	while(fast != NULL && fast->next != NULL) {
		prev_slow = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	middle = prev_slow->next;
	prev_slow->next = NULL;

	left = root;
	right = middle->next;
}

void traverse(TreeNode* &root, ListNode* head) {
	if(head == NULL) {
		root = NULL;
		return;
	}

	ListNode* middle = NULL;
	ListNode* left = NULL;
	ListNode* right = NULL;

	divide(head, middle, left, right);

	root->val = middle->val;

	TreeNode* dummyLeft = new TreeNode(-1);
	traverse(dummyLeft, left);
	root->left = dummyLeft;

	TreeNode* dummyRight = new TreeNode(-1);
	traverse(dummyRight, right);
	root->right = dummyRight;
}

TreeNode* sortedListToBST(ListNode* head) {
	TreeNode* root = new TreeNode(-1);

	traverse(root, head);

	return root;
}

int main(int argc, char** argv) {
	ListNode* one = new ListNode(1);
	ListNode* two = new ListNode(2);
	ListNode* three = new ListNode(3);
	ListNode* four = new ListNode(4);
	ListNode* five = new ListNode(5);
	ListNode* six = new ListNode(6);

	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
	five->next = six;

	ListNode* middle = NULL;
	ListNode* left = NULL;
	ListNode* right = NULL;

	divide(one, middle, left, right);

	cout << "middle = " << middle->val << endl;

	cout << "left = " << endl;

	while (left != NULL) {
		cout << left->val << ", ";
		left = left->next;
	}

	cout << endl;

	cout << "right = " << endl;

	while (right != NULL) {
		cout << right->val << ", ";
		right = right->next;
	}
	
	cout << endl;

	return 0;
}
