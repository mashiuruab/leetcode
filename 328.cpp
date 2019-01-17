#include<iostream>
#include<map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head) {
	if(head == NULL) return NULL;

	ListNode* result = head;

	int count = 1;

	ListNode* odd = head;
	ListNode* even = NULL;
	ListNode* prev;

	while(head != NULL){
		if(count > 1 && (count % 2 == 1)) {
			ListNode* temp = head->next;
			odd->next= head;
			odd = odd->next;
			prev->next = head->next;
			head = head->next;
			count++;
			continue;
		} else if (count == 2) {
			even = head;
		}

		prev = head;
		head = head->next; 
		count++;
	}

	odd->next = even;

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

	ListNode* result = oddEvenList(one);

	while(result != NULL) {
		cout<< result->val <<", ";
		result = result->next;
	}

	cout<<endl;	
	return 0;
}
