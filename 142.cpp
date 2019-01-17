#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
	if(head == NULL) return NULL;

        ListNode* slow = head;
	ListNode* fast = head;
	ListNode* prev_slow = NULL;
	
	do {
		prev_slow = slow;
		slow = slow->next;
		if(fast->next != NULL) {
			fast = fast->next->next;
		} else  {
			fast = fast->next;
		} 
	} while(fast != NULL && slow != fast);

	if(slow != NULL && fast != NULL && slow == fast) {
		return prev_slow;
	} else {
		return NULL;
	}
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
	six->next = one;

	ListNode* cycle = detectCycle(one);

	if(cycle != NULL) cout << "cycle node = " << cycle->val << endl;
	
	return 0;
}
