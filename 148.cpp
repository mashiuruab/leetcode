#include<iostream>
#include<map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge(ListNode* left, ListNode* right) {
	ListNode* head = new ListNode(-1);
	bool flag = true;
	ListNode* result = head;

	while(left != NULL || right != NULL) {
		if(left != NULL && right != NULL && left->val < right->val) {
			if(head->val == -1 && flag) {
				flag = false;
				head->val = left->val;
			} else {
				head->next = left;
				head = head->next;
			}
			
			left = left->next;
		} else if(left != NULL && right != NULL && left->val > right->val) {
			if(head->val == -1 && flag) {
				flag = false;
				head->val = right->val;
			} else {
				head->next = right;
				head = head->next;
			}
			
			right = right->next;
		} else if(left != NULL && right != NULL && left->val == right->val) {
			if(head->val == -1 && flag) {
				flag = false;
				head->val = left->val;
				head->next = right;
				head = head->next;
			} else {
				head->next = left;
				head = head->next;
				head->next = right;
				head = head->next;
			}
			
			left = left->next;
			right = right->next;
		} else if (left == NULL && right != NULL) {
			head->next = right;
			return result;
		} else if (right == NULL && left != NULL) {
			head->next = left;
			return result;
		}
	}

	return result;
}

void divide(ListNode* head, ListNode* &left, ListNode* &right, int &count, int &l) {
	if(head == NULL) return;

	l++;
	divide(head->next, left, right, count, l);

	ListNode* newNode = new ListNode(head->val);
	
	if(count < (l / 2)) { // right
		newNode->next = right;
		right = newNode;
	} else { // left
		newNode->next = left;
		left = newNode;
	}

	count++;
}

void divide_f(ListNode* head, ListNode* &left, ListNode* &right, int &count, int &l) {
	left = head;

	ListNode* slow = left;
	ListNode* fast = left;

	while(fast != NULL) {
		cout<< slow->val << endl;
		slow = slow->next;
		if(fast->next != NULL) {
			fast = fast->next->next;
		} else {
			fast = fast->next;
		}	
	}

	if (slow != NULL) {
		right = slow->next;
	}
}

ListNode* divide_r(ListNode* head) {
	if(head == NULL) return NULL;
	if(head->next == NULL) return head;

	ListNode* left = NULL;
	ListNode* right = NULL;

	int count = 0;
	int l = 0;

	divide(head, left, right, count, l);

	//cout<< "worked here " << endl;

	ListNode* m_l = divide_r(left);
	ListNode* m_r = divide_r(right);

	return merge(m_l, m_r);
}

ListNode* sortList(ListNode* head) {
	if(head == NULL) return NULL;
	else return divide_r(head);       
}

int main(int argc, char** argv) {
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

	/*
	ListNode* left = NULL;
	ListNode* right = NULL;

	int count = 0;
	int l = 0;

	divide(one, left, right, count, l);

	ListNode* temp = left;
	cout<< "left node = " << endl;
	while(temp != NULL) {
		cout<< temp->val << ", ";
		temp = temp->next;
	}

	cout<<endl;

	temp = right;
	
	cout<< "right node = " << endl;
	while(temp != NULL) {
		cout<< temp->val << ", ";
		temp = temp->next;
	}

	cout<<endl;

	cout<< "merge example" << endl;

	ListNode* result = merge(left, right);

	temp = result;

	while(temp != NULL) {
		cout<< temp->val << ", ";
		temp = temp->next;
	}

	cout<< endl;
	*/

	ListNode* result = sortList(one);

	ListNode* temp = result;

	while(temp != NULL) {
		cout<< temp->val << ", ";
		temp = temp->next;
	}

	cout<< endl;
	

	return 0;
}
