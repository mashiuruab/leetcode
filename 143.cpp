#include<iostream>
#include<map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* pos = NULL;
bool go = true;

void traverse(ListNode* head) {
	if(head == NULL) return;

	traverse(head->next);

	if(pos == head) go = false;

	if(pos->next == head) {
		pos = head;
		pos->next = NULL;
		go = false;
	}

	if(!go) return; 
	
	//cout<< "---------------------------"<<endl;
	//cout<< "current pos " << pos->val << endl;
	//cout<< "setting " << head->val << endl;

	ListNode* temp = pos->next;
	pos->next = head;
	head->next = temp;
	pos = temp;

	//cout<< "pos after setting " << pos->val << endl;
}

void reorderList(ListNode* head) {
	if(head == NULL) return;

        pos = head;
	traverse(head);

	pos->next = NULL;

	ListNode* temp = head;

	while(temp != NULL){
		//cout<< temp->val << ", ";
		temp = temp->next;
	}

	cout<< endl;
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

	reorderList(one);

	return 0;
}
