#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void traverse(ListNode* head, int &x, ListNode* &left, ListNode* &right) {
	if(head == NULL) return;

	traverse(head->next, x, left, right);

	if(head->val < x) {
		//cout << head->val << ", k = " << k << endl;
		ListNode* newNode = new ListNode(head->val);
		newNode->next = left;
		left = newNode;
	} else {
		//cout << head->val << ", k = " << k << endl;
		ListNode* newNode = new ListNode(head->val);
		newNode->next = right;
		right = newNode;
	}
}

ListNode* partition(ListNode* head, int x) {
	ListNode* left = NULL;
	ListNode* right = NULL;

	traverse(head, x, left, right);

	ListNode* result = left;

	ListNode* prev_left = NULL;

	while(left != NULL) {
		prev_left = left;
		left = left->next;
	}

	if(prev_left == NULL) {
		result = right;
	} else {
		prev_left->next = right;
	}

	return result;
}


int main(int argc, char** argv){
	ListNode* one = new ListNode(1);
	ListNode* two = new ListNode(4);
	ListNode* three = new ListNode(3);
	ListNode* four = new ListNode(2);
	ListNode* five = new ListNode(5);
	ListNode* six = new ListNode(2);

	int x = 3;

	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
	five->next = six;

	ListNode* result = partition(one, x);

	while(result != NULL) {
		cout << result->val << ", ";
		result = result->next;
	}

	cout<< endl;

	return 0;
}
