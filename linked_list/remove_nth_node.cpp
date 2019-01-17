#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode  *next;
	ListNode(int x) : val(x), next(NULL) {
	
	}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
	if(head  == NULL || n == 0) return head;

	int length = 0;
	ListNode* temp  = head;
	
	while(temp != NULL){
		temp = temp->next;
		length++;
	}

	temp = head;

	if (length - n == 0) {
		head =  head->next;
		return head;
	}

	int counter = 1;

	while(true) {
		if(length - n ==  counter) {
			temp->next = temp->next->next;
			break;
		}
		temp = temp->next;
		counter++;				
	}

	return head;
}

ListNode* reverseList2(ListNode* head) {
	if(head == NULL) return NULL;

	ListNode* temp = new ListNode(head->val);
	head = head->next;
	
	while(head != NULL) {
		ListNode* newNode = new ListNode(head->val);
		newNode->next = temp;
		temp = newNode;
		head = head->next;
	}
	
	return temp;
}

ListNode* reverseList(ListNode* head) {
	static ListNode* tempHead;
	static ListNode* head_to_return;
	static int count1 = 0;
	static int count2 = 0;

	if(head == NULL) return NULL;	

	count1++;
	reverseList(head->next);
	count2++;

	if((count2 == 1) && (count2 != count1)){
		tempHead = new ListNode(head->val);
		head_to_return = tempHead;
		tempHead->next = new ListNode(-1);
		tempHead  = tempHead->next;
	} else  if  ((count2 == 1) && (count2 == count1)) {
		tempHead = new ListNode(head->val);
		head_to_return = tempHead;
	} else if(count2 != count1) {
		tempHead->val = head->val;
		tempHead->next = new ListNode(-1);
		tempHead  = tempHead->next;
	} else if(count2 == count1) {
		tempHead->val = head->val;
		tempHead->next = NULL;
		return head_to_return;
	}
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if(l1 == NULL) {
		return l2;
	} else  if (l2 == NULL) {
		return l1;
	}

	ListNode* head =  l1;
	ListNode* temp;
	ListNode* templ2 = l2;
	ListNode* prev = NULL;

	while(l2 != NULL) {
		templ2 = l2;
		l2 = l2->next;
		while(l1 != NULL && l1->val <= templ2->val) {
			if(l1->next  != NULL && l1->next->val <= templ2->val) {
				l1 = l1->next;
				continue;
			} else if (l1->next == NULL) {
				l1->next = templ2;
				return head;
			}

			temp = l1->next;
			l1->next = templ2;
			templ2->next = temp;
			prev = l1;
			l1 = l1->next;
		}

		if(l1 != NULL && l1->val > templ2->val) {
			if(prev != NULL) {
				//cout<< "block " << templ2->val <<  endl;
				//cout<< "prev->next->val " << prev->next->val << endl;
				temp = prev->next;
				prev->next = templ2;
				templ2->next = temp;
				prev = templ2;
			} else {
				//cout<< "worked here" << endl;
				head = templ2;
				head->next = l1;
				prev = head;
			}
		}
	}

	return head;
}

bool isPalindrome(ListNode* head) {
	vector<int> arr;

	while(head != NULL) {
		arr.push_back(head->val);
		head = head->next;
	}
	
	bool palindrome = true;

	for(int i=0;i<arr.size() / 2;i++) {
		palindrome &= (arr[i] ==  arr[arr.size() - 1 - i]);		
	}
	
	return palindrome;
}

bool hasCycle(ListNode *head) {
	if(head == NULL) return false;

	vector<ListNode*> addr_container;
	
	while(head != NULL) {
		for(int i=0;i<addr_container.size();i++){
			if(addr_container[i] == head) return true;
		}
		addr_container.push_back(head);
		head = head->next;
	}

	return false;
}

void print_linked_list(ListNode* head) {
	while(head != NULL) {
		cout<< head->val << " -> ";
		head  =  head->next;
	}
	cout<< "NULL" << endl;
}

ListNode* createDummy() {
	ListNode* node = new ListNode(-1);
	ListNode* head = node;

	for(int i=1;i<=5;i++) {
		if(i != 5) {
			node->val = i;
			node->next = new ListNode(-1);
		} else {
			node->val = i;
			node->next = NULL;
		}
		node = node-> next;
	}

	return head;
}

int main(int argc, char** argv){
	ListNode* head1 = new ListNode(6);
	ListNode* head2 = createDummy();
	/*ListNode* head1 = new ListNode(2);
	ListNode* head2 = new ListNode(1);*/
	print_linked_list(mergeTwoLists(head1,head2));
}
