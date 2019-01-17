#include<iostream>
#include<map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void traverse(ListNode* head, int count, int m, int n, ListNode* &left, ListNode* &middle, ListNode* &right) {
	if(head == NULL) return;

	count++;

	traverse(head->next, count, m, n, left, middle, right);

	ListNode* newNode = new ListNode(head->val);

	if(count > n) {
		newNode->next = right;
		right = newNode;	
	} else if (count >=m && count <= n) {
		if(middle == NULL) {
			middle = newNode;
		} else {
			ListNode* temp = middle;

			while(temp->next != NULL) {
				temp = temp->next;
			}

			temp->next = newNode;
		}
	} else if (count < m) {
		newNode->next = left;
		left = newNode;
	}
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
	ListNode* left = NULL;
	ListNode* middle = NULL;
	ListNode* right = NULL;

	int count = 0;

	traverse(head, count, m, n, left, middle, right);

	ListNode* result = left;

	if(left != NULL) {
		while(left->next != NULL) {
			left = left->next;
		}
		if (middle != NULL) {
			left->next = middle;
		} else {
			left->next = right;
		}
	} else {
		if (middle != NULL) {
			result = middle;
		} else {
			result = right;
		}
	}

	if(middle != NULL) {
		while(middle->next != NULL) {
			middle = middle->next;
		}

		middle->next = right;
	}

	return result;
}

int main(int argc, char** argv){
	ListNode* one = new ListNode(1);
	ListNode* two = new ListNode(2);
	ListNode* three = new ListNode(3);
	ListNode* four = new ListNode(4);
	ListNode* five = new ListNode(5);
	

	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;


	int m = 2;
	int n = 4;

	ListNode* result = reverseBetween(one, m, n);

	ListNode* head = result;

	while(head != NULL) {
		cout<< head->val << ", ";
		head = head->next;
	}

	cout<< endl;
	
	return 0;
}
