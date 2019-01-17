#include<iostream>
#include<map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
	if(head == NULL) return NULL;
	ListNode* result = head;
	ListNode* prev = NULL;

	while(head != NULL) {
		if(head->next != NULL) {
			if(prev != NULL) {
				ListNode* temp = head->next->next;
				prev->next = head->next;
				head->next->next = head;
				head->next = temp;
			} else {
				ListNode* temp = head->next->next;
				result = head->next;
				head->next->next = head;
				head->next = temp;
			}
		}
		
		prev = head;
		head = head->next;
	}

	return result;        
}

int main(int argc, char** argv){

	ListNode* one = new ListNode(1);
	ListNode* two = new ListNode(2);
	ListNode* three = new ListNode(3);
	ListNode* four = new ListNode(4);
	ListNode* five = new ListNode(5);
	ListNode* six = new ListNode(6);
	ListNode* seven = new ListNode(7);
	

	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
	five->next = six;
	six->next = seven;

	ListNode* result = swapPairs(one);

	while(result != NULL) {
		cout<< result->val <<", ";
		result = result->next;
	}

	cout<<endl;
	return 0;
}
