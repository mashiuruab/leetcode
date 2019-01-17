#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

ListNode* insert(ListNode* head, int val) {
	if(head == NULL) {
        head = new ListNode(val);
		return head;
	} else if (val < head->val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        return head;
    }
	
	ListNode* prev = head;

    //cout<< "for value = " << val << " and head found " << head->val << endl;

    ListNode* tempHead = head;
    
	while(head != NULL && (head->val < val)){
        //cout<< head->val << ", ";
		prev = head;
		head = head->next;
	}
    
    //cout<< endl;

    ListNode* temp = prev->next;
	prev->next = new ListNode(val);
	prev->next->next = temp;
	
    return tempHead;
}

ListNode* insertionSortList(ListNode* head) {
	ListNode* result = NULL;
    ListNode* rHead = result;
	while(head != NULL) {
        //cout<< head->val << endl;
		result = insert(result, head->val);
        //result = rHead;
		head = head->next;	
	}

	return result;       
}

int main(int argc, char** argv){
	ListNode* 
	return 0;
}
