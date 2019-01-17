#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void traverse(ListNode* head, int &l, int &k, ListNode* &left, ListNode* &right) {
	if(head == NULL) return;

	l++;
	traverse(head->next, l, k, left, right);

	while(k > l) k = k - l;

	if(k > 0) {
		//cout << head->val << ", k = " << k << endl;
		k--;
		ListNode* newNode = new ListNode(head->val);
		newNode->next = left;
		left = newNode;
	} else {
		ListNode* tempL = left;

		//cout << head->val << ", k = " << k << endl;
		ListNode* newNode = new ListNode(head->val);
		newNode->next = right;
		right = newNode;
	}
}

ListNode* rotateRight(ListNode* head, int k) {
	ListNode* left = NULL;
	ListNode* right = NULL;

	int l = 0;
	
	traverse(head, l, k, left, right);

	ListNode* result = left;
	ListNode* prev_left = NULL;

	while(left != NULL) {
		prev_left = left;
		left = left->next;
	}

	if(prev_left != NULL) {
		prev_left->next = right;
	} else {
		result = right;
	}

	return result;
}

int main(int argc, char** argv){
	ListNode* one = new ListNode(1);
	ListNode* two = new ListNode(2);
	ListNode* three = new ListNode(3);
	ListNode* four = new ListNode(4);
	ListNode* five = new ListNode(5);

	int k = 2;

	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;

	ListNode* result = rotateRight(one, k);

	while(result != NULL) {
		cout << result->val << ", ";
		result = result->next;
	}

	cout<< endl;

	return 0;
}
