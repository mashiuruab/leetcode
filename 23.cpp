#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode  *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge_sorted(ListNode* left, ListNode* right) {
	if(left == NULL) {
		return right;
	} 

	if(right == NULL) {
		return  left;
	}

	if(left == NULL && right == NULL) {
		return NULL;
	}

	ListNode* result = new ListNode(-1);
	ListNode* head  = result;

	while(true) {
		if(left == NULL && right == NULL) {
			break;
		}

		if(left == NULL && right != NULL) {
			result->val = right->val;
			result->next = right->next;
			break;
		} else if (left != NULL && right == NULL) {
			result->val = left->val;
			result->next = left->next;
			break;
		}

		if(left-> val <= right->val) {
			result->val = left->val;
			left = left->next;	
		} else {
			result->val  = right->val;
			right = right->next;
		}

		if(left != NULL || right != NULL) {
			result->next = new ListNode(-1);
			result = result->next;
		}
	}

	return head;
}

ListNode* traverse(vector<ListNode*>& lists, int start, int end) {
	if(start ==  end) {
		return lists[start];
	}

	int mid = (start + end) / 2;

	ListNode* left_merge = traverse(lists, start, mid);
	ListNode* right_merge = traverse(lists, mid+1, end);

	return  merge_sorted(left_merge, right_merge);
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	if(lists.size() == 0) {
		return NULL;
	} else {
		return traverse(lists, 0, lists.size() - 1);	        
	}
}

int main(int argc, char** argv) {
	return  0;
}
