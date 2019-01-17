#include<iostream>
#include<map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
        ListNode* result = head;
	ListNode* prev = NULL;

	while(head != NULL) {
		if(prev != NULL && prev->val == head->val) {
			prev->next = head->next;
			head = head->next;
			continue;
		}
	
		prev = head;
		head = head->next;
	}

	return result;
}

int main(int argc, char** argv) {
	ListNode* one = new ListNode(1);
	ListNode* two = new ListNode(2);
	ListNode* three = new ListNode(3);
	ListNode* three1 = new ListNode(3);
	ListNode* four = new ListNode(4);
	ListNode* four1 = new ListNode(4);
	ListNode* five = new ListNode(5);
	

	one->next = two;
	two->next = three;
	three->next = three1;
	three1->next = four;
	four->next = four1;
	four1->next = five;

	ListNode* result = deleteDuplicates(one);

	ListNode* head = result;

	while(head != NULL) {
		cout<< head->val << ", ";
		head = head->next;
	}

	cout<< endl;
	
	return 0;
}
